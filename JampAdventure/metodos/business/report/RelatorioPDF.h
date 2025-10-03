#ifndef RELATORIO_PDF_H
#define RELATORIO_PDF_H
#include "RelatorioTemplate.h"
#include <iostream>

class RelatorioPDF : public RelatorioTemplate {
protected:
	void gerarCabecalho() override {
		std::cout << "[PDF] Relatório de Acessos\n";
		std::cout << "[PDF] Estatísticas de Acesso dos Usuários\n";
	}
	void gerarCorpo(const std::vector<User>& dados) override {
		std::cout << "[PDF] Usuário | Acessos\n";
		for (const auto& user : dados) {
			std::cout << "[PDF] " << user.getUsername() << " | " << user.getUsername().length() * 3 << "\n";
		}
	}
	void gerarRodape() override {
		std::cout << "[PDF] Fim do Relatório\n";
	}
};
#endif 
