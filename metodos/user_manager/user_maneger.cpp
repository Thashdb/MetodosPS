#include <iostream>
#include <fstream>
#include "../user/user.hpp"
#include "user_manager.hpp"

#define ARQUIVO_USUARIOS "usuarios.txt"

void cadastrarUsuario() {
    User usuario;

    std::cout << "\n=== Cadastro de Usuário ===\n";
    std::cout << "Digite o login: ";
    std::cin >> usuario.login;

    std::cout << "Digite a senha: ";
    std::cin >> usuario.senha;

    std::ofstream arquivo(ARQUIVO_USUARIOS, std::ios::app);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return;
    }

    arquivo << usuario.login << " " << usuario.senha << "\n";
    arquivo.close();

    std::cout << "Usuário cadastrado com sucesso!\n";
}

void listarUsuarios() {
    User usuario;
    std::ifstream arquivo(ARQUIVO_USUARIOS);

    if (!arquivo.is_open()) {
        std::cout << "Nenhum usuário cadastrado.\n";
        return;
    }

    std::cout << "\n=== Lista de Usuários ===\n";
    while (arquivo >> usuario.login >> usuario.senha) {
        std::cout << "Login: " << usuario.login << "\n";
    }

    arquivo.close();
}
