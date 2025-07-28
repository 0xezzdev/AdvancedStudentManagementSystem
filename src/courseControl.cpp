#include <iostream>
#include "../include/courseControl.h"
#include "../include/Repository.h"
#include "../include/Course.h"
#include <vector>
#include "../include/User.h"
using namespace std;

int courseControl::globalCId = 0;

void courseControl::addCourse(Repository& repo)
{
    cout << "Adding a new course..." << endl;
    cout << "***********************************" << endl;
    cout << endl;
    string name;
    int credits;

    cout << "Enter Course Name: ";
    getline(cin >> ws, name);
    cout << "Enter Course Credits: ";
    cin >> credits;
    repo.courses.emplace_back(Course(globalCId, name,credits));
    cout << "Course added successfully." << endl;
    globalCId++;
    cout << endl;
}

void courseControl::deleteCourse(Repository& repo)
{
    bool courseFound = false;
    cout << "Deleting a course..." << endl;
    cout << "***********************************" << endl;
    cout << endl;
    int idcheck;
    cout << "Enter Course ID to delete: ";
    cin >> idcheck;

    for (auto it = repo.courses.begin(); it != repo.courses.end(); )
    {
        if ((*it).id == idcheck) {
            courseFound = true;
            it = repo.courses.erase(it);
            cout << "Course deleted." << endl;
            cout << endl;
        } else {
            ++it;
        }
    }
    for (auto i = repo.users.begin(); i != repo.users.end(); ++i)
    {
        for (auto j = (*i).courses.begin(); j != (*i).courses.end(); )
        {
            if ((*j).id == idcheck)
            {
                j = (*i).courses.erase(j);
            }
            else
            {
                ++j;
            }
        }
    }
    if (!courseFound)
    {
        cout << "Course not found." << endl;
        cout << endl;
    }
}

void courseControl::viewCourses(Course course)
{

    cout << "Course ID: " << course.id << ", Name: " << course.name << ", Credits: " << course.credits << endl;
}

void courseControl::addCourseToStudent(Repository& repo, int studentId, int courseId)
{
    cout << "Adding course to student: " << endl;
    cout << "***********************************" << endl;
    cout << endl;

    for (auto& user : repo.users) {
        if (user.ID == studentId) {
            for (const auto& course : repo.courses) {
                if (course.id == courseId) {
                    user.courses.emplace_back(course);
                    cout << "Course added to student successfully." << endl;
                    return;
                }
            }
            cout << "Course not found." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void courseControl::removeCourseFromStudent(Repository& repo, int studentId, int courseId)
{
    cout << "Removing course from student..." << endl;
    cout << "***********************************" << endl;
    cout << endl;

    for (auto i = repo.users.begin(); i != repo.users.end(); i++)
    {
        if ((*i).ID == studentId)
        {
            for (auto j = (*i).courses.begin(); j != (*i).courses.end(); ++j)
            {
                if (j->id == courseId)
                {
                    (*i).courses.erase(j);
                    cout << "Course removed from student successfully." << endl;
                    return;
                }
            }
            cout << "Course not found for this student." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}