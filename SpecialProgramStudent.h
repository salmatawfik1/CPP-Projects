

#ifndef S11_20225016_20225042_20235063_SPECIALPROGRAMSTUDENT_H
#define S11_20225016_20225042_20235063_SPECIALPROGRAMSTUDENT_H
#include "Student.h"
class SpecialProgramStudent : public Student {
public:
    SpecialProgramStudent(){}
    bool registercourse(Course* C){
        if(Student::registercourse(C)){
            return true;
        }
        else
            return false;
    }
    float calculateexpenses(){
        int sum = 0;
        for(int i=0; i<inputcourses; i++){
            sum += courselist[i]->getHours();
        }
        return sum*500.0;
    }
    ~SpecialProgramStudent(){}
};

#endif //S11_20225016_20225042_20235063_SPECIALPROGRAMSTUDENT_H
