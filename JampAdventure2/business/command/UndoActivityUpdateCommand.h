#ifndef UNDO_ACTIVITY_UPDATE_COMMAND_H
#define UNDO_ACTIVITY_UPDATE_COMMAND_H

#include "ICommand.h"
#include <string>

class UndoActivityUpdateCommand : public ICommand {
public:
    bool execute(FacadeSingletonController& facade) override {
        return facade.activity().undoLastUpdate();
    }

    std::string name() const override { return "UndoActivityUpdateCommand"; }
};

#endif
