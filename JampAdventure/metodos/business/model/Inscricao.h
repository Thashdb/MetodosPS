#ifndef INSCRICAO_H
#define INSCRICAO_H

#include "state/IInscricaoState.h"
#include <memory>

class IInscricaoState;

class Inscricao {
private:
    std::unique_ptr<IInscricaoState> estadoAtual;
public:
    Inscricao();
    void transicionarPara(std::unique_ptr<IInscricaoState> novoEstado);
    void confirmar();
    void cancelar();
};

#endif