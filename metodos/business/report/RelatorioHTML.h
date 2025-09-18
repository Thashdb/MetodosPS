#ifndef RELATORIO_HTML_H
#define RELATORIO_HTML_H
#include "RelatorioTemplate.h"
#include <iostream>

class RelatorioHTML : public RelatorioTemplate {
protected:
	void gerarCabecalho() override {
		std::cout << "<html><head><title>Relatório de Acessos</title></head><body>\n";
		std::cout << "<h1>Estatísticas de Acesso dos Usuários</h1>\n";
	}
		void gerarCorpo(const std::vector<User>& dados) override {
			std::cout << "<table border='1'><tr><th>Usuário</th><th>Acessos</th></tr>\n";
			for (const auto& user : dados) {
				std::cout << "<tr><td>" << user.getUsername() << "</td><td>" << user.getUsername().length() * 3 << "</td></tr>\n";
			}
			std::cout << "</table>\n";
		}
	void gerarRodape() override {
		std::cout << "</body></html>\n";
	}
};
#endif 
