#ifndef USER_H
#define USER_H
#include <vector>
#include "Course.h"
using namespace std;

// Make a Abstract class for student and admid
class User 
{
    
    public:
        vector <Course> courses;
        int ID;
        string name;
        string password;
        bool isLoggedIn;
        string type;
};

#endif