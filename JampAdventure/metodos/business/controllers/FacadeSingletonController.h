#ifndef FACADE_SINGLETON_CONTROLLER_H
#define FACADE_SINGLETON_CONTROLLER_H

#include "InterfaceController.h"
#include "UserController.h"
#include "AtividadeController.h"

class FacadeSingletonController {
private:
    static FacadeSingletonController* instance;
    FacadeSingletonController() {}
public:
    static FacadeSingletonController* getInstance() {
        if (!instance) instance = new FacadeSingletonController();
        return instance;
    }
};

FacadeSingletonController* FacadeSingletonController::instance = nullptr;

#endif
