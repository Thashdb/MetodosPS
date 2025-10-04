#include "ActivityInterface.h"
#include "../business/controllers/FacadeSingletonController.h"
#include "../business/command/CreateActivityCommand.h"
#include "../business/command/UpdateActivityCommand.h"
#include "../business/command/RemoveActivityCommand.h"
#include "../business/command/EnrollUserCommand.h"
#include "../business/command/UndoActivityUpdateCommand.h"
#include "../business/strategy/CategoryFilterStrategy.h"
#include "../business/strategy/DateFilterStrategy.h"
#include "../business/strategy/InstructorFilterStrategy.h"
#include "../business/model/Activity.h"

#include <iostream>
#include <limits>
#include <memory>
#include <vector>

namespace {
    void limpa() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void printActivities(const std::vector<Activity>& list) {
        if (list.empty()) {
            std::cout << "(sem atividades)\n";
            return;
        }
        for (const auto& a : list) {
            std::cout << " [" << a.id << "] " << a.name
                      << " - " << a.date << " " << a.time
                      << " - " << a.category
                      << " (instrutor: " << a.instructorUsername << ")\n";
            if (!a.participants.empty()) {
                std::cout << "   inscritos: ";
                for (size_t i = 0; i < a.participants.size(); ++i) {
                    std::cout << a.participants[i]
                              << (i + 1 < a.participants.size() ? ", " : "\n");
                }
            }
        }
    }
}

ActivityInterface::ActivityInterface(std::string username, UserRole role)
: currentUser_(std::move(username)), currentRole_(role) {}

void ActivityInterface::menu() {
    auto& facade = FacadeSingletonController::instance();

    for (;;) {
        std::cout << "\n=== Atividades ===\n"
                    << "1) (Instrutor) Criar atividade\n"
                    << "2) (Instrutor) Editar atividade\n"
                    << "3) (Instrutor) Remover atividade\n"
                    << "4) (Comum) Inscrever-se em atividade\n"
                    << "5) Listar atividades\n"
                    << "6) Filtrar atividades\n"
                    << "7) (Instrutor) Desfazer ultima atualizacao\n"
                    << "8) Minhas notificacoes\n"
                    << "0) Voltar\n"
                    << "Logado como: " << currentUser_
                    << (currentRole_==UserRole::Instructor ? " [Instrutor]\n" : " [Comum]\n")
                    << "Escolha: " << std::flush;

        int op;
        if (!(std::cin >> op)) { limpa(); std::cout << "Opcao invalida.\n"; continue; }
        limpa();
        if (op == 0) return;

        if (op == 1) {
            if (currentRole_ != UserRole::Instructor) { std::cout << "Apenas instrutor pode criar.\n"; continue; }
            std::string name, date, time, cat;
            std::cout << "Nome: "; std::getline(std::cin, name);
            std::cout << "Data (YYYY-MM-DD): "; std::getline(std::cin, date);
            std::cout << "Hora (HH:MM): "; std::getline(std::cin, time);
            std::cout << "Categoria: "; std::getline(std::cin, cat);
            CreateActivityCommand cmd{name, date, time, cat, currentUser_};
            bool ok = facade.execute(cmd);
            std::cout << (ok ? "Atividade criada!\n" : "Falha ao criar.\n");
        } else if (op == 2) {
            if (currentRole_ != UserRole::Instructor) { std::cout << "Apenas instrutor pode editar.\n"; continue; }
            int id; std::string name, date, time, cat;
            std::cout << "ID da atividade: "; std::cin >> id; limpa();
            std::cout << "Novo nome: "; std::getline(std::cin, name);
            std::cout << "Nova data (YYYY-MM-DD): "; std::getline(std::cin, date);
            std::cout << "Nova hora (HH:MM): "; std::getline(std::cin, time);
            std::cout << "Nova categoria: "; std::getline(std::cin, cat);
            UpdateActivityCommand cmd{id, name, date, time, cat, currentUser_};
            bool ok = facade.execute(cmd);
            std::cout << (ok ? "Atividade atualizada!\n" : "Falha ao atualizar.\n");
        } else if (op == 3) {
            if (currentRole_ != UserRole::Instructor) { std::cout << "Apenas instrutor pode remover.\n"; continue; }
            int id; std::cout << "ID da atividade: "; std::cin >> id; limpa();
            RemoveActivityCommand cmd{id, currentUser_};
            bool ok = facade.execute(cmd);
            std::cout << (ok ? "Atividade removida!\n" : "Falha ao remover.\n");
        } else if (op == 4) {
            if (currentRole_ != UserRole::Common) { std::cout << "Apenas usuario comum pode se inscrever.\n"; continue; }
            int id; std::cout << "ID da atividade: "; std::cin >> id; limpa();
            EnrollUserCommand cmd{id, currentUser_, UserRole::Common};
            bool ok = facade.execute(cmd);
            std::cout << (ok ? "Inscricao realizada!\n" : "Falha na inscricao.\n");
        } else if (op == 5) {
            printActivities(facade.activity().listAll());
        } else if (op == 6) {
            std::cout << "\n-- Filtros --\n"
                      << "1) Categoria\n"
                      << "2) Data\n"
                      << "3) Instrutor\n"
                      << "0) Cancelar\n"
                      << "Escolha: " << std::flush;
            int filtro;
            if (!(std::cin >> filtro)) { limpa(); std::cout << "Opcao invalida.\n"; continue; }
            limpa();

            if (filtro == 0) continue;

            std::unique_ptr<IActivityFilterStrategy> strategy;
            std::string valor;
            if (filtro == 1) {
                std::cout << "Categoria: "; std::getline(std::cin, valor);
                strategy = std::make_unique<CategoryFilterStrategy>(valor);
            } else if (filtro == 2) {
                std::cout << "Data (YYYY-MM-DD): "; std::getline(std::cin, valor);
                strategy = std::make_unique<DateFilterStrategy>(valor);
            } else if (filtro == 3) {
                std::cout << "Instrutor: "; std::getline(std::cin, valor);
                strategy = std::make_unique<InstructorFilterStrategy>(valor);
            } else {
                std::cout << "Opcao invalida.\n";
                continue;
            }

            if (valor.empty()) {
                std::cout << "O valor do filtro nao pode ser vazio.\n";
                continue;
            }

            auto filtered = facade.activity().filter(*strategy);
            if (filtered.empty()) {
                std::cout << "Nenhuma atividade encontrada para o filtro de "
                          << strategy->description() << ".\n";
            } else {
                printActivities(filtered);
            }
        } else if (op == 7) {
            if (currentRole_ != UserRole::Instructor) { std::cout << "Apenas instrutor pode desfazer atualizacao.\n"; continue; }
            UndoActivityUpdateCommand cmd;
            bool ok = facade.execute(cmd);
            std::cout << (ok ? "Ultima atualizacao desfeita!\n" : "Nada para desfazer.\n");
        } else if (op == 8) {
            auto notifications = facade.consumeNotifications(currentUser_);
            if (notifications.empty()) {
                std::cout << "Nenhuma notificacao pendente.\n";
            } else {
                std::cout << "\n--- Minhas notificacoes ---\n";
                for (const auto& msg : notifications) {
                    std::cout << "- " << msg << '\n';
                }
            }
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}