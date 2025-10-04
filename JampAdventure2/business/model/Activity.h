#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>
#include <vector>

// ENTIDADE: Atividade criada por um instrutor
struct Activity {
    int id{};
    std::string name;
    std::string date;     // ex.: "2025-10-04"
    std::string time;     // ex.: "14:30"
    std::string category; // ex.: "Trilha", "Palestra"
    std::string instructorUsername;      // dono (User instrutor)
    std::vector<std::string> participants; // usernames inscritos
};

#endif