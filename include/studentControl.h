#ifndef STUDENTCONTROL_H
#define STUDENTCONTROL_H
#include "Repository.h"
#include "Student.h"
#include "User.h"
using namespace std;

class studentControl
{
    public:
        static int globalId;
        void addUser(Repository& repo);
        void deleteUser(Repository& repo);
        void viewStudents(User user);
};

#endif