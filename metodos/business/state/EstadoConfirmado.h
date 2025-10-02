#ifndef ESTADO_CONFIRMADO_H
#define ESTADO_CONFIRMADO_H
#include "IInscricaoState.h"

class EstadoConfirmado : public IInscricaoState {
public:
    void confirmar(Inscricao& inscricao) override; 
    void cancelar(Inscricao& inscricao) override;  
};

#endif