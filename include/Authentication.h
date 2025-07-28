//ده كلاس لتسجيل الدخول و الخروج

#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include "User.h"
using namespace std;

class Authentication
{
    public:
    int currentUserId;
    string currentUserType;
    string currentUserName;
    
    void logIn(User&);
    void logOut(User&);
    bool chek(User);
};

#endif