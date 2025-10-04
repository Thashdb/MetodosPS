#ifndef REGISTER_USER_COMMAND_H
#define REGISTER_USER_COMMAND_H

#include "ICommand.h"
#include "../model/User.h"
#include <string>
#include <utility>

class RegisterUserCommand : public ICommand {
public:
    RegisterUserCommand(std::string username, std::string password, UserRole role)
        : username_(std::move(username)), password_(std::move(password)), role_(role) {}

    bool execute(FacadeSingletonController& facade) override {
        return facade.user().registerUser(username_, password_, role_);
    }

    std::string name() const override { return "RegisterUserCommand"; }

private:
    std::string username_;
    std::string password_;
    UserRole role_;
};

#endif