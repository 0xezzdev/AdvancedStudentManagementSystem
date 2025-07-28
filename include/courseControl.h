#ifndef COURSECONTROL_H
#define COURSECONTROL_H
#include "Repository.h"
#include "Course.h"
using namespace std;

class courseControl
{
    public:
        static int globalCId;
        void addCourse(Repository& repo);
        void deleteCourse(Repository& repo);
        void viewCourses(Course course);
        void addCourseToStudent(Repository& repo, int studentId, int courseId);
        void removeCourseFromStudent(Repository& repo, int studentId, int courseId);
};
#endif