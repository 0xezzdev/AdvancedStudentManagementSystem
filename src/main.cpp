#include<iostream>
#include <vector>
#include "../include/User.h"
#include "../include/Student.h"
#include "../include/Admin.h"
#include "../include/Repository.h"
#include "../include/Authentication.h"
#include "../include/studentControl.h"
#include "../include/courseControl.h"
#include "../include/Course.h"
#include "../include/SaveDataControl.h"


using namespace std;


int main()
{
    Repository repository;
    Authentication check;
    studentControl control;
    courseControl courseControl;
    SaveDataControl saveDataControl;

    int choice,id;
    string loginpasswordCheck;
    bool isLogged = false;
    repository.users.emplace_back(Admin(0,"admin","admin"));

    while (true)
    {
        cout << "*************************************" << endl;
        cout << "--Advanced Student Management Menu --" << endl;
        cout << "*************************************" << endl;
        cout<<endl;

        for (auto i = repository.users.begin(); i!=repository.users.end(); i++)
        {
            if (!(check.chek(*i)))
            {
                isLogged = false;
            }else
            {
                isLogged = true;
                check.currentUserName = i->name;
                break;
            }
        }
        if (isLogged)
        {
            if (check.currentUserType == "Admin")
            {
                cout << "----------Admin Dashboard----------" << endl;
                cout << "Your ID is: " << check.currentUserId << endl;
                cout << "***********************************" << endl;
                cout << endl;

                cout << "1.Add Student" << endl;
                cout << "2.Add Course" << endl;
                cout << "3.Enroll Student in Course" << endl;
                cout << "4.Show Students Details" << endl;
                cout << "5.Show Courses Details" << endl;
                cout << "6.Remove Course from student" << endl;
                cout << "7.Delete Student" << endl;
                cout << "8.Delete Course" << endl;
                cout << "0.Log out" << endl;
                cout << endl;
                cout << "***********************************" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cout << "***********************************" << endl;
                cout << endl;

                switch (choice)
                {
                case 1:
                    control.addUser(repository);
                    break;
                case 2:
                    courseControl.addCourse(repository);
                    break;
                case 3:
                    int studentId, courseId;
                    bool chekCourseExists;
                    chekCourseExists = false;
                    do
                    {
                        cout << "Enter Student ID: ";
                        cin >> studentId;
                        if (studentId == 0)
                        {
                            cout << "You cannot enroll a course to Admin!" << endl;
                            continue;
                        }else{
                            break;
                        }
                        
                    } while (true);
                    cout << "Enter Course ID: ";
                    cin >> courseId;
                    cout << endl;
                    for (auto it = repository.users[studentId].courses.begin(); it != repository.users[studentId].courses.end(); it++)
                    {
                        if ((*it).id == courseId)
                        {
                            chekCourseExists = true;
                            break;
                        }else
                        {
                            chekCourseExists = false;
                        }
                        
                    }
                    if (chekCourseExists)
                    {
                        cout << "This course is already enrolled by the student!" << endl;
                        cout << "Please choose another course or remove this course from student.\n" << endl;
                        break;
                    }else
                    {
                        courseControl.addCourseToStudent(repository, studentId, courseId);
                        break;
                    }
                    
                case 4:
                    int counterForStudent;
                    counterForStudent = 0;
                    
                    cout <<"Students Details:" << endl;
                    cout << "***********************************" << endl;
                    cout << endl;
                    
                    for (auto i = repository.users.begin(); i != repository.users.end(); i++)
                    {
                        if (i->type == "Student")
                        {
                            control.viewStudents(*i);
                            counterForStudent++;
                            cout << "----------------------------------" << endl;
                            cout << "Courses Enrolled: "<<endl;
                            if ((*i).courses.empty())
                            {
                                cout << "No courses available." << endl;
                                cout << endl;
                                
                            }else{
                                for (auto j = (*i).courses.begin(); j != (*i).courses.end(); j++)
                                {
                                
                                    courseControl.viewCourses(*j);
                                
                                }
                                cout << "************************************" << endl;
                                cout << endl;
                                
                            }
                        }
                        
                    }
                    if (counterForStudent == 0)
                    {
                        cout << "No students available." << endl;
                    }
                    cout << endl;
                    cout << "Do you want to save this student's data? (y/n): ";
                                char saveChoice;
                                cin >> saveChoice;
                                if (saveChoice == 'y' || saveChoice == 'Y')
                                {
                                    string path = "Data/All_Student_Details.txt";
                                    saveDataControl.saveAllData(repository, path);
                                }else if (saveChoice == 'n' || saveChoice == 'N')
                                {
                                    cout << "Data not saved, returning to main menu." << endl;
                                }else{
                                    cout << "Invalid choice, returning to main menu." << endl;
                                }
                    
                    break;
                case 5:
                    cout <<"Courses Details:" << endl;
                    cout << "***********************************\n" << endl;
                    //chek if there are courses
                    if (repository.courses.empty())
                    {
                        cout << "No courses available." << endl;
                        cout << endl;
                        break;
                    }else
                    {
                        for (auto i = repository.courses.begin(); i != repository.courses.end(); i++)
                    {
                        
                        courseControl.viewCourses(*i);
                        
                    }
                    cout << "\n***********************************" << endl;
                    cout << endl;

                    cout << "Do you want to save all courses data? (y/n): ";
                    char saveChoice;
                    cin >> saveChoice;
                    if (saveChoice == 'y' || saveChoice == 'Y')
                    {
                        string path = "Data/Course_Details.txt";
                        saveDataControl.saveCourseData(repository, path);
                    }else if (saveChoice == 'n' || saveChoice == 'N')
                    {
                        cout << "Data not saved, returning to main menu." << endl;
                    }else{
                        cout << "Invalid choice, returning to main menu." << endl;
                    }

                    break;
                    }
                    
                case 6:
                    int studentIdToRemove, courseIdToRemove;
                    cout << "Enter Student ID: ";
                    cin >> studentIdToRemove;
                    cout << "Enter Course ID: ";
                    cin >> courseIdToRemove;
                    courseControl.removeCourseFromStudent(repository, studentIdToRemove, courseIdToRemove);
                    break;
                case 7:
                    control.deleteUser(repository);
                    break;
                case 8:
                    courseControl.deleteCourse(repository);
                    break;
                case 0:
                    check.logOut(repository.users[check.currentUserId]);
                    isLogged = false;
                    cout << "Loging out......" << endl;
                    cout << "***********************************" << endl;
                    cout << endl;
                    break;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
            else{
                cout << "----------Student Dashboard----------" << endl;
                cout << "Your ID is: " << check.currentUserId << " Name: " << check.currentUserName << endl;
                cout << "***********************************" << endl;
                cout << endl;
                cout << "1.View Available Courses" << endl;
                cout << "2.Enroll in a Course" << endl;
                cout << "3.Remove Course" << endl;
                cout << "4.Show My Details" << endl;
                cout << "0.Log out" << endl;
                cout << endl;
                cout << "***********************************" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                cout << "***********************************" << endl;
                cout << endl;

                switch (choice)
                {
                case 1:
                    cout << "Available Courses:" << endl;
                    cout << "***********************************" << endl;
                    if (repository.courses.empty())
                    {
                        cout << "No courses available." << endl;
                        cout << endl;
                        break;
                    }else{
                        for (auto i = repository.courses.begin(); i != repository.courses.end(); i++)
                        {
                            courseControl.viewCourses(*i);
                        }
                        cout << "***********************************\n" << endl;
                        break;
                    }
                    
                case 2:
                    int courseIdToEnroll;
                    bool chekCourseExists;
                    chekCourseExists = false;
                    cout << "Enter Course ID to enroll: ";
                    cin >> courseIdToEnroll;
                    cout << endl;
                    for (auto it = repository.users[check.currentUserId].courses.begin(); it != repository.users[check.currentUserId].courses.end(); it++)
                    {
                        if ((*it).id == courseIdToEnroll)
                        {
                            chekCourseExists = true;
                            break;
                        }else
                        {
                            chekCourseExists = false;
                        }
                        
                    }
                    if (chekCourseExists)
                    {
                        cout << "This course is already enrolled by the student!" << endl;
                        cout << "Please choose another course or remove this course from student.\n" << endl;
                        break;
                    }else
                    {
                        courseControl.addCourseToStudent(repository, check.currentUserId, courseIdToEnroll);
                        break;
                    }
                    
                case 3:
                    int courseIdToRemove;
                    cout << "Enter Course ID to remove: ";
                    cin >> courseIdToRemove;
                    courseControl.removeCourseFromStudent(repository, check.currentUserId, courseIdToRemove);
                    break;
                case 4:
                    cout << "Your Details:" << endl;
                    cout << "***********************************" << endl;
                    cout << "ID: " << check.currentUserId << endl;
                    cout << "Name: " << check.currentUserName << endl;
                    cout << "-----------------------------------" << endl;
                    cout << endl;
                    cout << "Courses Enrolled: " << endl;
                    if (repository.users[check.currentUserId].courses.empty())
                    {
                        cout << "No courses available." << endl;
                        cout << endl;
                    }else
                    {
                        for (auto i = repository.users[check.currentUserId].courses.begin(); i != repository.users[check.currentUserId].courses.end(); i++)
                        {
                            courseControl.viewCourses(*i);
                        }
                    }
                    
                    
                    cout << endl;
                    cout << "Do you want to save your data? (y/n): ";
                    char saveChoice;
                    cin >> saveChoice;
                    if (saveChoice == 'y' || saveChoice == 'Y')
                    {
                        string path = "Data/Student_Details.txt";
                        saveDataControl.saveUserData(repository.users[check.currentUserId], path);
                        cout << endl;
                    }else if (saveChoice == 'n' || saveChoice == 'N')
                    {
                        cout << "Data not saved, returning to main menu." << endl;
                    }else{
                        cout << "Invalid choice, returning to main menu." << endl;
                    }
                    break;
                case 0:
                    check.logOut(repository.users[check.currentUserId]);
                    isLogged = false;
                    cout << "Loging out......" << endl;
                    cout << "***********************************" << endl;
                    cout << endl;
                    break;
                
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            }
            
        }else
        {
            cout<<"1.Log in"<<endl;
            cout<<"0.Exit"<<endl;
            cout<<endl;
            cout << "***********************************" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            cout << "***********************************" << endl;
            cout << endl;

            switch (choice)
            {
                case 1:
                    cout << "Enter your ID: ";
                    cin >> id;
                    for (auto i = repository.users.begin(); i != repository.users.end(); i++)
                    {
                        if (i->ID == id)
                        {
                            
                            do
                            {
                                cout << "Enter your password: ";
                                getline(cin >> ws, loginpasswordCheck);
                                cout<< loginpasswordCheck << endl;
                                if (i->password == loginpasswordCheck)
                                {
                                    check.logIn(*i);
                                    break;
                                }
                                else
                                {
                                    cout << "Incorrect password! Please try again." << endl;
                                }
                            } while (true);
                            
                        }
                        
                    }
                    if (!isLogged)
                    {
                        cout<<"User not found!\n"<<endl;
                    }
                    
                    break;

                case 0:
                    return 0;

                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        }
        
        
    }
    

}
