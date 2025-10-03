#ifndef FILRO_POR_DATA_STRATEGY_H
#define FILRO_POR_DATA_STRATEGY_H

#include "IFiltroAtividadeStrategy.h"
#include <string>

class FiltroPorDataStrategy : public IFiltroAtividadeStrategy {
private:
    std::string dataFiltro;
public:
    explicit FiltroPorDataStrategy(const std::string& data) : dataFiltro(data) {}

    std::vector<Atividade> filtrar(const std::vector<Atividade>& atividades) const override {
        std::vector<Atividade> filtradas;
        for (const auto& atividade : atividades) {
            if (atividade.getNome() == dataFiltro) { 
                filtradas.push_back(atividade);
            }
        }
        return filtradas;
    }
};

#endif