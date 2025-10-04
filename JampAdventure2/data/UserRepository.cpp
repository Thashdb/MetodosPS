#include "UserRepository.h"

bool UserRepository::addUser(const User& u) {
    users_.push_back(u);
    return true;
}

const std::vector<User>& UserRepository::listAll() const {
    return users_;
}

// id = 1 se vazio; senão, último id + 1
int UserRepository::nextId() const {
    return users_.empty() ? 1 : (users_.back().id + 1);
}

const User* UserRepository::findByUsername(const std::string& username) const {
    for (const auto& u : users_) {
        if (u.username == username) return &u;
    }
    return nullptr;
}