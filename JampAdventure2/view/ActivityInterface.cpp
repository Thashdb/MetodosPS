#include "ActivityInterface.h"
#include "../business/controllers/FacadeSingletonController.h"

#include <iostream>
#include <limits>

static void limpa() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            bool ok = facade.activity().create(name, date, time, cat, currentUser_);
            std::cout << (ok ? "Atividade criada!\n" : "Falha ao criar.\n");
        } else if (op == 2) {
            if (currentRole_ != UserRole::Instructor) { std::cout << "Apenas instrutor pode editar.\n"; continue; }
            int id; std::string name, date, time, cat;
            std::cout << "ID da atividade: "; std::cin >> id; limpa();
            std::cout << "Novo nome: "; std::getline(std::cin, name);
            std::cout << "Nova data (YYYY-MM-DD): "; std::getline(std::cin, date);
            std::cout << "Nova hora (HH:MM): "; std::getline(std::cin, time);
            std::cout << "Nova categoria: "; std::getline(std::cin, cat);
            bool ok = facade.activity().update(id, name, date, time, cat, currentUser_);
            std::cout << (ok ? "Atividade atualizada!\n" : "Falha ao atualizar.\n");
        } else if (op == 3) {
            if (currentRole_ != UserRole::Instructor) { std::cout << "Apenas instrutor pode remover.\n"; continue; }
            int id; std::cout << "ID da atividade: "; std::cin >> id; limpa();
            bool ok = facade.activity().erase(id, currentUser_);
            std::cout << (ok ? "Atividade removida!\n" : "Falha ao remover.\n");
        } else if (op == 4) {
            if (currentRole_ != UserRole::Common) { std::cout << "Apenas usuario comum pode se inscrever.\n"; continue; }
            int id; std::cout << "ID da atividade: "; std::cin >> id; limpa();
            bool ok = facade.activity().enrollUser(id, currentUser_, UserRole::Common);
            std::cout << (ok ? "Inscricao realizada!\n" : "Falha na inscricao.\n");
        } else if (op == 5) {
            const auto& list = facade.activity().listAll();
            if (list.empty()) { std::cout << "(sem atividades)\n"; continue; }
            for (const auto& a : list) {
                std::cout << " [" << a.id << "] " << a.name
                          << " - " << a.date << " " << a.time
                          << " - " << a.category
                          << " (instrutor: " << a.instructorUsername << ")\n";
                if (!a.participants.empty()) {
                    std::cout << "   inscritos: ";
                    for (size_t i=0;i<a.participants.size();++i) {
                        std::cout << a.participants[i] << (i+1<a.participants.size()? ", ":"\n");
                    }
                }
            }
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}