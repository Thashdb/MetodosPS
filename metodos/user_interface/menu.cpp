#include <iostream>
#include "menu.hpp"
#include "../user_manager/user_manager.hpp"

void mostrarMenu() {
    int opcao;

    do {
        std::cout << "\n=== Menu ===\n";
        std::cout << "1. Cadastrar usuário\n";
        std::cout << "2. Listar usuários\n";
        std::cout << "3. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                listarUsuarios();
                break;
            case 3:
                std::cout << "Saindo do programa.\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 3);
}
