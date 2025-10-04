#ifndef ACTIVITY_MEMENTO_H
#define ACTIVITY_MEMENTO_H

#include "../model/Activity.h"
#include <utility>

class ActivityMemento {
public:
    explicit ActivityMemento(Activity state) : state_(std::move(state)) {}

    const Activity& state() const { return state_; }

private:
    Activity state_;
};

#endif
