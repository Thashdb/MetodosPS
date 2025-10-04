#ifndef RAM_DAO_FACTORY_H
#define RAM_DAO_FACTORY_H

#include "IDaoFactory.h"
#include "../UserRepository.h" // Implementação em RAM

// Fábrica Concreta: Cria a família de DAOs para persistência em RAM.
class RamDaoFactory : public IDaoFactory {
public:
    std::unique_ptr<IUserRepository> createUserDao() override {
        return std::make_unique<UserRepository>();
    }

    std::unique_ptr<ActivityRepository> createActivityDao() override {
        return std::make_unique<ActivityRepository>();
    }
};

#endif