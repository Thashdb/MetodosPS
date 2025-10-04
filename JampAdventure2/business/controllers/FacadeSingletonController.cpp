#include "FacadeSingletonController.h"
#include <stdexcept>

FacadeSingletonController& FacadeSingletonController::instance() {
    static FacadeSingletonController inst;
    return inst;
}

void FacadeSingletonController::wire(IUserRepository* userRepo, ActivityRepository* activityRepo) {
    if (!userRepo || !activityRepo) throw std::invalid_argument("Repositorios nulos");
    userRepo_ = userRepo;
    activityRepo_ = activityRepo;

    userCtl_     = new UserController(*userRepo_);
    activityCtl_ = new ActivityController(*activityRepo_);
}

UserController& FacadeSingletonController::user() {
    if (!userCtl_) throw std::runtime_error("Facade nao inicializada");
    return *userCtl_;
}

ActivityController& FacadeSingletonController::activity() {
    if (!activityCtl_) throw std::runtime_error("Facade nao inicializada");
    return *activityCtl_;
}

size_t FacadeSingletonController::countEntities() const {
    if (!userCtl_ || !activityCtl_) throw std::runtime_error("Facade nao inicializada");
    const auto& users = userCtl_->listAll();
    const auto& acts  = activityCtl_->listAll();
    return users.size() + acts.size();
}
