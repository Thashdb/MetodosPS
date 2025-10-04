#ifndef ACTIVITY_REPOSITORY_H
#define ACTIVITY_REPOSITORY_H

#include <vector>
#include <string>
#include "../business/model/Activity.h"

class ActivityRepository {
    public:
        bool add(const Activity& a);                       // Create
        bool update(int id, const Activity& a);            // Update
        bool remove(int id);                               // Delete
        const std::vector<Activity>& listAll() const;      // Read (lista)
        int  nextId() const;
        size_t count() const;

        // Inscrição de usuário comum
        bool enroll(int activityId, const std::string& username);
    private:
        std::vector<Activity> store_;
};

#endif