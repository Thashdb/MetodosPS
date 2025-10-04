#ifndef ACTIVITY_INTERFACE_H
#define ACTIVITY_INTERFACE_H

#include <string>
#include "../business/model/User.h"

class ActivityInterface {
public:
    ActivityInterface(std::string username, UserRole role);
    void menu();

private:
    std::string currentUser_;
    UserRole currentRole_;
};


#endif
