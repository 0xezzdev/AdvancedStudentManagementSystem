#include<iostream>
#include "../include/User.h"
#include "../include/Repository.h"
#include "../include/Authentication.h"
using namespace std;

//logIn function
void Authentication::logIn(User& user)
{
    user.isLoggedIn = true;
    cout << user.type << " logged in successfully.\n";
    cout<<endl;
}

//LogOut function
void Authentication::logOut(User& user)
{
    user.isLoggedIn = false;
    cout << user.type << " logged out successfully.\n";
    cout<<endl;
}

bool Authentication::chek(User user)
{
    if (user.isLoggedIn)
    {
        currentUserId = user.ID;
        currentUserName = user.name;
        currentUserType = user.type;
        return true;
    }else
    {
        return false;
    }
    
    
}

