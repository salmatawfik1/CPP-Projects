

#ifndef S11_20225016_20225042_20235063_SUMMERCOURSE_H
#define S11_20225016_20225042_20235063_SUMMERCOURSE_H
#include "Course.h"

class SummerCourse:public Course{
public:
    SummerCourse(){}

    SummerCourse(const string& name ,int level, int CH): Course(name, level,CH) {
        Code = name+"_"+"S"+to_string(level);
    }

};

#endif //S11_20225016_20225042_20235063_SUMMERCOURSE_H
