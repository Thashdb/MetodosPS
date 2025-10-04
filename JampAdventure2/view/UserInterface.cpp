#include "UserInterface.h"
#include "../infra/error/ExceptionLogin.h"
#include "../infra/error/ExceptionPassword.h"

#include <iostream>
#include <limits>
#include <string>

UserInterface::UserInterface(UserController& ctl) : ctl_(ctl) {}

void UserInterface::menu() {
    for (;;) {
        std::cout << "\n=== Usuarios ===\n"
                  << "1) Criar usuario\n"
                  << "2) Listar usuarios\n"
                  << "0) Voltar\n"
                  << "Escolha: " << std::flush;

        int op;
        if (!(std::cin >> op)) { limpaEntrada(); std::cout << "Opcao invalida.\n"; continue; }
        limpaEntrada();

        if (op == 0) return;
        if (op == 1) criarUsuario();
        else if (op == 2) listarUsuarios();
        else std::cout << "Opcao invalida.\n";
    }
}

void UserInterface::limpaEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInterface::criarUsuario() {
    std::string login, senha;
    std::cout << "Login: ";  std::getline(std::cin, login);
    std::cout << "Senha: ";  std::getline(std::cin, senha);
    try {
        if (ctl_.addUser(login, senha)) std::cout << "Usuario adicionado!\n";
        else std::cout << "Falha ao adicionar usuario.\n";
    } catch (const ExceptionLogin& e) {
        std::cout << "Erro de login: " << e.what() << "\n";
    } catch (const ExceptionPassword& e) {
        std::cout << "Erro de senha: " << e.what() << "\n";
    } catch (const std::ios_base::failure& e) {
        std::cout << "Erro de I/O: " << e.what() << "\n";
    }
}

void UserInterface::listarUsuarios() const {
    const auto& all = ctl_.listAll();
    if (all.empty()) { std::cout << "(nenhum usuario)\n"; return; }
    std::cout << "Usuarios cadastrados:\n";
    for (const auto& u : all) std::cout << " - [" << u.id << "] " << u.username << "\n";
}