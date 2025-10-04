#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "../controllers/FacadeSingletonController.h"
#include <string>

// Interface Command
class ICommand {
public:
    virtual ~ICommand() = default;
    virtual bool execute(FacadeSingletonController& facade) = 0;
    virtual std::string name() const = 0;
};

#endif