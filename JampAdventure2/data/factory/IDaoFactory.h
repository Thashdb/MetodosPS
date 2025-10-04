#ifndef IDAO_FACTORY_H
#define IDAO_FACTORY_H

#include "../IUserRepository.h"
#include "../ActivityRepository.h"
#include <memory>

// Abstract Factory: Define a interface para criar uma família de DAOs.
class IDaoFactory {
public:
    virtual ~IDaoFactory() = default;

    virtual std::unique_ptr<IUserRepository> createUserDao() = 0;
    virtual std::unique_ptr<ActivityRepository> createActivityDao() = 0;
};

#endif