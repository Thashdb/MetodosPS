#ifndef ACESSOS_CONTROLLER_H

#define ACESSOS_CONTROLLER_H
#include <vector>
#include "../model/User.h"
#include "../report/RelatorioHTML.h"
#include "../report/RelatorioPDF.h"

class AcessosController {
public:
	std::vector<User> coletarUsuarios() {
		return {
			User("alice", "123"),
			User("bob", "456"),
			User("carol", "789")
		};
	}

	void gerarRelatorioHTML() {
		std::vector<User> usuarios = coletarUsuarios();
		RelatorioHTML relatorio;
		relatorio.gerarRelatorio(usuarios);
	}

	void gerarRelatorioPDF() {
		std::vector<User> usuarios = coletarUsuarios();
		RelatorioPDF relatorio;
		relatorio.gerarRelatorio(usuarios);
	}
};

#endif 
