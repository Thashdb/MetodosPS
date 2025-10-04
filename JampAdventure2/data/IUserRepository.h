#ifndef IUSER_REPOSITORY_H
#define IUSER_REPOSITORY_H

#include <vector>
#include <string>
#include "../business/model/User.h"

struct IUserRepository {
    virtual ~IUserRepository() = default;
    virtual bool addUser(const User& u) = 0;
    virtual const std::vector<User>& listAll() const = 0;
    virtual int  nextId() const = 0;
    
    virtual const User* findByUsername(const std::string& username) const = 0;
};

#endif