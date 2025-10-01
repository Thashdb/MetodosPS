#ifndef DADOS_ADMISSIONAIS_HPP
#define DADOS_ADMISSIONAIS_HPP

#include "../core/secao.hpp"

class DadosAdmissionais : public Secao {
    public:
        DadosAdmissionais() : Secao("Dados Admissionais") {}
};

#endif // DADOS_ADMISSIONAIS_HPP