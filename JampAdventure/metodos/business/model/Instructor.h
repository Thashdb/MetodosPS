#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <string>

class Instructor {
private:
    std::string name;
public:
    Instructor(std::string n = "") : name(n) {}
    std::string getName() { return name; }
};

#endif
