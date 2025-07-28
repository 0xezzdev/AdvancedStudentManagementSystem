#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <vector>
#include "User.h"
#include "Course.h"
using namespace std;

class Repository
{
    public:
        vector<User>users;
        vector<Course>courses;
};

#endif