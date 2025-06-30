

#ifndef S11_20225016_20225042_20235063_GENERALPROGRAMSTUDENT_H
#define S11_20225016_20225042_20235063_GENERALPROGRAMSTUDENT_H
#include "Course.h"
#include "Student.h"
class GeneralProgramStudent : public Student {
public :
    GeneralProgramStudent(){}
    bool registercourse (Course* B) {
        int minLevel = B->getMinLevel();
        if (Student::registercourse(B) && level >= minLevel)
            return true;
        else{
            return false;
        }
    }

    float calculateexpenses(){
        return level*1000;
    }
};

#endif //S11_20225016_20225042_20235063_GENERALPROGRAMSTUDENT_H
