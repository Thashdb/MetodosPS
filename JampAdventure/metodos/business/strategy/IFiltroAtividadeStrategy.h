#ifndef IFILTRO_ATIVIDADE_STRATEGY_H
#define IFILTRO_ATIVIDADE_STRATEGY_H

#include "../model/AtividadeController.h" 
#include <vector>

class IFiltroAtividadeStrategy {
public:
    virtual ~IFiltroAtividadeStrategy() = default;
    virtual std::vector<Atividade> filtrar(const std::vector<Atividade>& atividades) const = 0;
};

#endif