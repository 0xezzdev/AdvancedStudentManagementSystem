#ifndef SAVEDATACONTROL_H
#define SAVEDATACONTROL_H
#include "Repository.h"
#include <iostream>
#include <fstream>

class SaveDataControl 
{
    public:
        void saveAllData(Repository repo,const string& path);
        void saveUserData(User user,const string& path);
        void saveCourseData(Repository repo,const string& path);
};

#endif