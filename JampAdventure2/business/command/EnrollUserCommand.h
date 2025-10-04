#ifndef ENROLL_USER_COMMAND_H
#define ENROLL_USER_COMMAND_H

#include "ICommand.h"
#include "../model/User.h"
#include <string>
#include <utility>

class EnrollUserCommand : public ICommand {
public:
    EnrollUserCommand(int activityId, std::string username, UserRole role)
        : activityId_(activityId), username_(std::move(username)), role_(role) {}

    bool execute(FacadeSingletonController& facade) override {
        return facade.activity().enrollUser(activityId_, username_, role_);
    }

    std::string name() const override { return "EnrollUserCommand"; }

private:
    int activityId_;
    std::string username_;
    UserRole role_;
};

#endif
