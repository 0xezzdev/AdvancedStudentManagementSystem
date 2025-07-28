#include <iostream>
#include "../include/SaveDataControl.h"
#include "../include/Repository.h"
#include <fstream>
#include <string>
using namespace std;

void SaveDataControl::saveAllData(Repository repo, const string& path) {
    ofstream file(path);
    int counter = 0;

    file <<"*****************************" << endl;
    file << "Advanced Student Management System" << endl;
    file << "*****************************" << endl;
    file <<endl;
    file << "All Students and Courses Data:" << endl;
    file << "Total Students: " << repo.users.size() - 1 << endl;
    file << "-----------------------------" << endl;
    file << endl;
    for (auto it = repo.users.begin(); it != repo.users.end(); ++it) {
        if ((*it).type == "Admin") continue; // عشان ميطبعش الادمن
        counter++;
        file << "Student ID: " << (*it).ID << ", Name: " << (*it).name<<endl;
        file << "-----------------------------" << endl;
        file << "Courses Enrolled: " << endl;
        if ((*it).courses.empty())
            {
                file << "No courses available." << endl;
            }else
            {
                for(auto cIt = (*it).courses.begin(); cIt != (*it).courses.end(); ++cIt) {
                    file << "Course ID: " << (*cIt).id << ", Name: " << (*cIt).name << ", Credits: " << (*cIt).credits << endl;
                }
            }
        file << endl;
    }
    if (counter == 0)
    {
        file << "No students available." << endl;
    }
    
    file.close();
    cout << "All data saved successfully to " << path << endl;
}

void SaveDataControl::saveUserData(User user, const string& path) {
    ofstream file(path);
    
    file <<"*****************************" << endl;
    file << "Advanced Student Management System" << endl;
    file << "*****************************" << endl;
    file <<endl;
    file << "Student Details:" << endl;
    file << "----------------------------" << endl;
    file << endl;
    file << "User ID: " << user.ID << endl;
    file << "Name: " << user.name << endl;
    file << "----------------------------" << endl;
    file << "Courses Enrolled: " << endl;
    if (user.courses.empty())
    {
        file << "No courses available." << endl;
    }
    else
    {
        for (auto it = user.courses.begin(); it != user.courses.end(); ++it) {
            file << "Course ID: " << (*it).id << ", Name: " << (*it).name << ", Credits: " << (*it).credits << endl;
        }   
    }
    file.close();
    cout << "User data saved successfully to " << path << endl;
}

void SaveDataControl::saveCourseData(Repository repo, const string& path) {
    ofstream file(path);
    
    file <<"*****************************" << endl;
    file << "Advanced Student Management System" << endl;
    file << "*****************************" << endl;
    file <<endl;
    file << "Course Details:" << endl;
    file << "----------------------------" << endl;
    file << endl;
    if (repo.courses.empty()) {
        file << "No courses available." << endl;
        file.close();
        cout << "No courses to save." << endl;
        return;
    }else
    {
        for(auto i = repo.courses.begin(); i != repo.courses.end(); i++) {
            file << "Course ID: " << (*i).id << endl;
            file << "Name: " << (*i).name << endl;
            file << "Credits: " << (*i).credits << endl;
            file<< endl;
        }
        file.close();
        cout << "Course data saved successfully to " << path << endl;
    }
    
}

