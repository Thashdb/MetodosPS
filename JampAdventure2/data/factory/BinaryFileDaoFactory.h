#ifndef BINARY_FILE_DAO_FACTORY_H
#define BINARY_FILE_DAO_FACTORY_H

#include "IDaoFactory.h"
#include "../BinaryFileUserRepository.h" // Implementação em Arquivo

// Fábrica Concreta: Cria a família de DAOs para persistência em arquivo.
class BinaryFileDaoFactory : public IDaoFactory {
public:
    std::unique_ptr<IUserRepository> createUserDao() override {
        return std::make_unique<BinaryFileUserRepository>("usuarios.bin");
    }

    std::unique_ptr<ActivityRepository> createActivityDao() override {
        // Nota: ActivityRepository ainda é em RAM.
        // Se tivéssemos um BinaryFileActivityRepository, ele seria criado aqui.
        return std::make_unique<ActivityRepository>();
    }
};

#endif