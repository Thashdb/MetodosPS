#ifndef IINSCRICAO_STATE_H
#define IINSCRICAO_STATE_H

#include "Inscricao.h"
#include "state/IInscricaoState.h"

Inscricao::Inscricao() : estadoAtual(nullptr) {}

void Inscricao::transicionarPara(std::unique_ptr<IInscricaoState> novoEstado) {
    estadoAtual = std::move(novoEstado);
}

void Inscricao::confirmar() {
    if (estadoAtual) {
        estadoAtual->confirmar(*this);
    }
}

void Inscricao::cancelar() {
    if (estadoAtual) {
        estadoAtual->cancelar(*this);
    }
}

class IInscricaoState {
public:
    virtual ~IInscricaoState() = default;
    virtual void confirmar(Inscricao& inscricao) = 0;
    virtual void cancelar(Inscricao& inscricao) = 0;
};

#endif