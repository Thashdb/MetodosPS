#ifndef BINARY_FILE_USER_REPOSITORY_H
#define BINARY_FILE_USER_REPOSITORY_H

#include <vector>
#include <string>
#include <fstream>

#include "IUserRepository.h"

class BinaryFileUserRepository : public IUserRepository {
public:
    explicit BinaryFileUserRepository(std::string path);
    bool addUser(const User& u) override;
    const std::vector<User>& listAll() const override;
    int nextId() const override;
    const User* findByUsername(const std::string& username) const override;
private:
    std::string path_;
    mutable std::vector<User> cache_;
    void loadIfNeeded() const;
    static void writeString(std::ofstream& f, const std::string& s);
    static std::string readString(std::ifstream& f);
};

#endif