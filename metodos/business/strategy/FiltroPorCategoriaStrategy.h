#ifndef FILRO_POR_CATEGORIA_STRATEGY_H
#define FILRO_POR_CATEGORIA_STRATEGY_H

#include "IFiltroAtividadeStrategy.h"
#include <string>

class FiltroPorCategoriaStrategy : public IFiltroAtividadeStrategy {
private:
    std::string categoriaFiltro;

public:
    explicit FiltroPorCategoriaStrategy(const std::string& categoria) : categoriaFiltro(categoria) {}

    std::vector<Atividade> filtrar(const std::vector<Atividade>& atividades) const override {
        std::vector<Atividade> filtradas;
        for (const auto& atividade : atividades) {
            if (atividade.getNome() == categoriaFiltro) {
                filtradas.push_back(atividade);
            }
        }
        return filtradas;
    }
};

#endif