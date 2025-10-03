#ifndef ESTADO_PENDENTE_H
#define ESTADO_PENDENTE_H
#include "IInscricaoState.h"

class EstadoPendente : public IInscricaoState {
public:
    void confirmar(Inscricao& inscricao) override;
    void cancelar(Inscricao& inscricao) override;
};

#endif
