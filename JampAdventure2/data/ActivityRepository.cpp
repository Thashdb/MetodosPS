#include "ActivityRepository.h"
#include <algorithm>

bool ActivityRepository::add(const Activity& a) {
    store_.push_back(a);
    return true;
}

bool ActivityRepository::update(int id, const Activity& a) {
    for (auto& it : store_) {
        if (it.id == id) {
            it.name = a.name;
            it.date = a.date;
            it.time = a.time;
            it.category = a.category;
            it.instructorUsername = a.instructorUsername;
            return true;
        }
    }
    return false;
}

bool ActivityRepository::remove(int id) {
    auto before = store_.size();
    store_.erase(std::remove_if(store_.begin(), store_.end(),
                    [id](const Activity& x){ return x.id == id; }),
                    store_.end());
    return store_.size() != before;
}

const std::vector<Activity>& ActivityRepository::listAll() const {
    return store_;
}

int ActivityRepository::nextId() const {
    return store_.empty() ? 1 : (store_.back().id + 1);
}

size_t ActivityRepository::count() const {
    return store_.size();
}

bool ActivityRepository::enroll(int activityId, const std::string& username) {
    for (auto& a : store_) {
        if (a.id == activityId) {
            // evita duplicidade
            if (std::find(a.participants.begin(), a.participants.end(), username) == a.participants.end()) {
                a.participants.push_back(username);
                return true;
            }
            return false; // já inscrito
        }
    }
    return false; // atividade não encontrada
}
