#ifndef ACTIVITY_CARETAKER_H
#define ACTIVITY_CARETAKER_H

#include "ActivityMemento.h"
#include <memory>
#include <stdexcept>
#include <utility>

class ActivityCaretaker {
public:
    void save(ActivityMemento memento) {
        lastMemento_ = std::make_unique<ActivityMemento>(std::move(memento));
    }

    bool hasSnapshot() const { return static_cast<bool>(lastMemento_); }

    const ActivityMemento* peek() const { return lastMemento_.get(); }

    ActivityMemento release() {
        if (!lastMemento_) throw std::runtime_error("Nenhum memento armazenado");
        ActivityMemento copy = *lastMemento_;
        lastMemento_.reset();
        return copy;
    }

    void clear() { lastMemento_.reset(); }

private:
    std::unique_ptr<ActivityMemento> lastMemento_;
};

#endif
