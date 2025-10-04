#include "BinaryFileUserRepository.h"
#include <stdexcept>
#include <cstdint>

BinaryFileUserRepository::BinaryFileUserRepository(std::string path)
: path_(std::move(path)) {}

void BinaryFileUserRepository::writeString(std::ofstream& f, const std::string& s){
    uint32_t n = static_cast<uint32_t>(s.size());
    f.write(reinterpret_cast<const char*>(&n), sizeof(n));
    f.write(s.data(), n);
}
std::string BinaryFileUserRepository::readString(std::ifstream& f){
    uint32_t n=0;
    f.read(reinterpret_cast<char*>(&n), sizeof(n));
    std::string s(n,'\0');
    f.read(&s[0], n);
    return s;
}

void BinaryFileUserRepository::loadIfNeeded() const {
    if (!cache_.empty()) return;
    std::ifstream in(path_, std::ios::binary);
    if (!in) return; // sem arquivo ainda
    while (in.peek()!=EOF) {
        User u{};
        in.read(reinterpret_cast<char*>(&u.id), sizeof(u.id));
        if (!in) break;
        u.username = readString(in);
        u.password = readString(in);
        uint8_t roleByte = 0; // NOVO: role
        in.read(reinterpret_cast<char*>(&roleByte), sizeof(roleByte));
        u.role = roleByte == 1 ? UserRole::Instructor : UserRole::Common;
        cache_.push_back(std::move(u));
    }
}

bool BinaryFileUserRepository::addUser(const User& u){
    std::ofstream out(path_, std::ios::binary | std::ios::app);
    if (!out) throw std::ios_base::failure("Falha ao abrir arquivo binario para escrita");
    out.write(reinterpret_cast<const char*>(&u.id), sizeof(u.id));
    writeString(out, u.username);
    writeString(out, u.password);
    uint8_t roleByte = (u.role == UserRole::Instructor ? 1u : 0u); // NOVO
    out.write(reinterpret_cast<const char*>(&roleByte), sizeof(roleByte));
    out.flush();
    cache_.push_back(u);
    return true;
}

const std::vector<User>& BinaryFileUserRepository::listAll() const {
    loadIfNeeded();
    return cache_;
}

int BinaryFileUserRepository::nextId() const {
    loadIfNeeded();
    return cache_.empty() ? 1 : (cache_.back().id + 1);
}

const User* BinaryFileUserRepository::findByUsername(const std::string& username) const {
    loadIfNeeded();
    for (const auto& u : cache_) if (u.username == username) return &u;
    return nullptr;
}