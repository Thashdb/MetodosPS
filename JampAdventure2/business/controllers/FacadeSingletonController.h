#ifndef FACADE_SINGLETON_CONTROLLER_H
#define FACADE_SINGLETON_CONTROLLER_H

#include "UserController.h"
#include "ActivityController.h"
#include "../../data/IUserRepository.h"
#include "../../data/ActivityRepository.h"

// Singleton + Facade: expõe uma "porta" única para os gerentes
class FacadeSingletonController {
public:
    static FacadeSingletonController& instance();

    // Injeta os repos e constrói os controllers (chamar uma vez no início)
    void wire(IUserRepository* userRepo, ActivityRepository* activityRepo);

    // Acesso aos controllers
    UserController& user();
    ActivityController& activity();

    // Total de ENTIDADES (usuários + atividades)
    size_t countEntities() const;

private:
    FacadeSingletonController() = default;
    FacadeSingletonController(const FacadeSingletonController&) = delete;
    FacadeSingletonController& operator=(const FacadeSingletonController&) = delete;

    IUserRepository* userRepo_{nullptr};
    ActivityRepository* activityRepo_{nullptr};

    // alocados após wire()
    UserController* userCtl_{nullptr};
    ActivityController* activityCtl_{nullptr};
};

#endif