#ifndef DADOS_PESSOAIS_HPP
#define DADOS_PESSOAIS_HPP

#include "../core/secao.hpp"

class DadosPessoais : public Secao {
    public:
        DadosPessoais() : Secao("Dados Pessoais") {}
};

#endif // DADOS_PESSOAIS_HPP