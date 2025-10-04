#ifndef USER_REPOSITORY_H
#define USER_REPOSITORY_H

#include "../business/model/User.h"
#include "IUserRepository.h"

#include <iostream>
#include <vector>

class UserRepository : public IUserRepository {
    public:
        bool addUser(const User& u) override;
        const std::vector<User>& listAll() const override;
        int nextId() const override; 
        const User* findByUsername(const std::string& username) const override;
    private:
        std::vector<User> users_;
};

#endif