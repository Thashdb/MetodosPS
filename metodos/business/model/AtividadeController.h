#ifndef ATIVIDADE_H
#define ATIVIDADE_H

#include <string>

class Atividade {
private:
    std::string nome;
public:
    Atividade(std::string n = "") : nome(n) {}
    std::string getNome() { return nome; }
};

#endif
