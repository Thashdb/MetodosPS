#ifndef CREATE_ACTIVITY_COMMAND_H
#define CREATE_ACTIVITY_COMMAND_H

#include "ICommand.h"
#include <string>
#include <utility>

class CreateActivityCommand : public ICommand {
public:
    CreateActivityCommand(std::string name,
                          std::string date,
                          std::string time,
                          std::string category,
                          std::string instructor)
        : name_(std::move(name)),
          date_(std::move(date)),
          time_(std::move(time)),
          category_(std::move(category)),
          instructor_(std::move(instructor)) {}

    bool execute(FacadeSingletonController& facade) override {
        return facade.activity().create(name_, date_, time_, category_, instructor_);
    }

    std::string name() const override { return "CreateActivityCommand"; }

private:
    std::string name_;
    std::string date_;
    std::string time_;
    std::string category_;
    std::string instructor_;
};

#endif
