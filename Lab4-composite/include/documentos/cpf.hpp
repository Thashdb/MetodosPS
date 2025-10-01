#ifndef CPF_HPP
#define CPF_HPP

#include "../core/secao.hpp"
#include <string>

class CPF : public Secao {
    public:
        CPF(std::string numero);
};

#endif // CPF_HPP
