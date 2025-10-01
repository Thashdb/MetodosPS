#ifndef COLABORADOR_HPP
#define COLABORADOR_HPP

#include "../core/secao.hpp"
#include <string>

class Colaborador : public Secao{
    public:
        explicit Colaborador(string nomeCompleto)
            : Secao("Cadastro do Colaborador: " + nomeCompleto) {}
};

#endif // COLABORADOR_HPP