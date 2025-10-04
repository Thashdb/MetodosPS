#ifndef REMOVE_ACTIVITY_COMMAND_H
#define REMOVE_ACTIVITY_COMMAND_H

#include "ICommand.h"
#include <string>
#include <utility>

class RemoveActivityCommand : public ICommand {
public:
    RemoveActivityCommand(int id, std::string instructor)
        : id_(id), instructor_(std::move(instructor)) {}

    bool execute(FacadeSingletonController& facade) override {
        return facade.activity().erase(id_, instructor_);
    }

    std::string name() const override { return "RemoveActivityCommand"; }

private:
    int id_;
    std::string instructor_;
};

#endif
