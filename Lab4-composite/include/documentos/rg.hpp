#ifndef RG_HPP
#define RG_HPP

#include "../core/secao.hpp"
#include <string>

class RG : public Secao {
    public:
        RG(std::string numero, std::string orgao);
};

#endif // RG_HPP