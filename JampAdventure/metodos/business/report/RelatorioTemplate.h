#ifndef RELATORIO_TEMPLATE_H
#define RELATORIO_TEMPLATE_H
#include <vector>
#include "../business/model/User.h"

class RelatorioTemplate {
public:
    void gerarRelatorio(const std::vector<User>& dados) {
        gerarCabecalho();
        gerarCorpo(dados);
        gerarRodape();
    }
    virtual ~RelatorioTemplate() = default;

protected:
    virtual void gerarCabecalho() = 0;
    virtual void gerarCorpo(const std::vector<User>& dados) = 0;
    virtual void gerarRodape() = 0;
};
#endif