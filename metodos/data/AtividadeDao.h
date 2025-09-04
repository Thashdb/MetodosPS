#ifndef ATIVIDADE_DAO_H
#define ATIVIDADE_DAO_H

#include <iostream>

class AtividadeDao {
public:
    void persist() { std::cout << "Atividade salvo no banco" << std::endl; }
};

#endif
