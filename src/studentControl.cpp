#include<iostream>
#include "../include/studentControl.h"
#include "../include/Repository.h"
#include "../include/Student.h"
using namespace std;

// فكرت كثير في موضوع الـ id عملته استاتيك عشان ميتكررش
int studentControl::globalId =1;

void studentControl::addUser(Repository& repo)
{
    cout << "Adding a new student..." << endl;
    cout << "***********************************" << endl;
    cout << endl;
    string name,pass;

    cout<<"Enter Student Name: ";
    getline(cin>>ws,name);
    cout<<"Enter Password for Student: ";
    getline(cin>>ws,pass);

    repo.users.emplace_back(Student(globalId,name,pass));
    cout << "Student added successfully." << endl;
    globalId++;
    cout<<endl;
}

void studentControl::deleteUser(Repository& repo)
{
    cout << "Deleting a student..." << endl;
    cout << "***********************************" << endl;
    cout << endl;
    int id;
    cout << "Enter Student ID to delete: ";
    cin>>id;
    if (id==0)
    {
        cout << "Cannot delete admin user." << endl;
        cout << endl;
    }else
    {
    
        for (auto it=repo.users.begin();it!=repo.users.end(); it++)
        {
            if (it->ID == id) {
                repo.users.erase(it);
                cout << "Student deleted." << endl;
                cout << endl;
                return;
            }
        }
        cout <<"Student not found." << endl;
        cout << endl;
    }
}

void studentControl::viewStudents(User user)
{
    cout<< "Student ID: " << user.ID << " , Name: " << user.name << endl;
}