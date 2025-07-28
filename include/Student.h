#ifndef STUDENT_H
#define STUDENT_H
#include "User.h"
#include "Course.h"
#include <string>
#include <vector>
using namespace std;

class Student : public User
{
    public:
        
        Student(int id, string username, string pass)
        {
            this->ID = id;
            this->name = username;
            this->password = pass;
            this->type = "Student";
            this->isLoggedIn = false;
        }
};

#endif