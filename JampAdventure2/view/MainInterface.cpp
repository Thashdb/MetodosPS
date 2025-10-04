#include "MainInterface.h"
#include "UserInterface.h"
#include "ActivityInterface.h"

#include "../data/UserRepository.h"
#include "../data/BinaryFileUserRepository.h"
#include "../data/ActivityRepository.h"
#include "../business/controllers/FacadeSingletonController.h"
#include "../business/controllers/UserController.h"
#include "../business/model/User.h"

#include <iostream>
#include <limits>
#include <memory>

namespace {
    void limpa() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void MainInterface::menu() {
    std::cout << "Sistema Iniciado!\n";

    // Escolhe persistencia de USUARIOS uma vez
    std::unique_ptr<IUserRepository> userRepo;
    {
        std::cout << "Persistencia de usuarios [1-RAM / 2-Arquivo binario]: " << std::flush;
        int modo = 1; if (!(std::cin >> modo)) { limpa(); modo = 1; } limpa();
        if (modo == 2) userRepo = std::make_unique<BinaryFileUserRepository>("usuarios.bin");
        else           userRepo = std::make_unique<UserRepository>();
    }

    ActivityRepository activityRepo; // atividades em RAM (id auto)
    auto& facade = FacadeSingletonController::instance();
    facade.wire(userRepo.get(), &activityRepo);

    for (;;) {
        std::cout << "\n=== Menu ===\n"
                    << "1) Cadastrar-se\n"
                    << "2) Fazer login\n"
                    << "3) Listar atividades cadastradas\n"
                    << "4) Total de entidades (usuarios + atividades)\n"
                    << "0) Sair\n"
                    << "Escolha: " << std::flush;

        int op;
        if (!(std::cin >> op)) { limpa(); std::cout << "Opcao invalida.\n"; continue; }
        limpa();
        if (op == 0) { std::cout << "Encerrando...\n"; break; }

        if (op == 1) {
            // CADASTRAR
            std::string username, password;
            int papel = 2;
            std::cout << "Login: ";  std::getline(std::cin, username);
            std::cout << "Senha: ";  std::getline(std::cin, password);
            std::cout << "Papel [1-Instrutor / 2-Aluno]: ";
            if (!(std::cin >> papel)) { limpa(); papel = 2; } limpa();
            UserRole role = (papel == 1 ? UserRole::Instructor : UserRole::Common);

            try {
                bool ok = facade.user().registerUser(username, password, role);
                std::cout << (ok ? "Cadastro realizado!\n" : "Falha: usuario ja existe ou dados invalidos.\n");
            } catch (const std::exception& e) {
                std::cout << "Erro: " << e.what() << "\n";
            }

        } else if (op == 2) {
            // LOGIN
            std::string username, password;
            std::cout << "Login: ";  std::getline(std::cin, username);
            std::cout << "Senha: ";  std::getline(std::cin, password);

            const User* u = facade.user().login(username, password);
            if (!u) { std::cout << "Credenciais invalidas.\n"; continue; }

            // Redireciona para o menu de atividades conforme role
            ActivityInterface ai(u->username, u->role);
            ai.menu();

        } else if (op == 3) {
            // LISTAR ATIVIDADES
            const auto& list = facade.activity().listAll();
            if (list.empty()) { std::cout << "(sem atividades)\n"; continue; }
            for (const auto& a : list) {
                std::cout << " [" << a.id << "] " << a.name
                          << " - " << a.date << " " << a.time
                          << " - " << a.category
                          << " (instrutor: " << a.instructorUsername << ")\n";
                if (!a.participants.empty()) {
                    std::cout << "   inscritos: ";
                    for (size_t i=0;i<a.participants.size();++i)
                        std::cout << a.participants[i] << (i+1<a.participants.size()? ", ":"\n");
                }
            }

        } else if (op == 4) {
            // TOTAL DE ENTIDADES
            std::cout << "Total: " << facade.countEntities() << "\n";

        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}