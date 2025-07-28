#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
#include <string>
using namespace std;

class Admin : public User
{
    public:
    Admin(int id, string username, string pass);
};

//set attributes for Admin
Admin::Admin(int id, string username, string pass)
{
    this->ID = id;
    this->name = username;
    this->password = pass;
    this->type = "Admin";
    this->isLoggedIn = false;

}

#endif