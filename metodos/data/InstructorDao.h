#ifndef INSTRUCTOR_DAO_H
#define INSTRUCTOR_DAO_H

#include <iostream>

class InstructorDao {
public:
    void persist() { std::cout << "Instrutor salvo no banco" << std::endl; }
};

#endif
