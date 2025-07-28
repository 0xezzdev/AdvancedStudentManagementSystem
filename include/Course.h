#ifndef COURSE_H
#define COURSE_H
using namespace std;

class Course
{
    public:
        int id,credits;
        string name;
        Course(int id,string name,int credits){
            this->id=id;
            this->name=name;
            this->credits=credits;
        }
};

#endif