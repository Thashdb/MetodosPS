#ifndef ENDERECO_HPP
#define ENDERECO_HPP

#include "../core/secao.hpp"

class Endereco : public Secao {
    public:
        Endereco() : Secao("Endereco") {}
};

#endif // ENDERECO_HPP