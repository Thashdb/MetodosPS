#ifndef ESTADO_CANCELADO_H
#define ESTADO_CANCELADO_H
#include "IInscricaoState.h"

class EstadoCancelado : public IInscricaoState {
public:
    void confirmar(Inscricao& inscricao) override;
    void cancelar(Inscricao& inscricao) override;
};

#endif