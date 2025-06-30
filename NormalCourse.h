

#ifndef S11_20225016_20225042_20235063_NORMALCOURSE_H
#define S11_20225016_20225042_20235063_NORMALCOURSE_H
#include "Course.h"

class NormalCourse : public Course {
public:
    NormalCourse(){}

    NormalCourse (const string &name, int level, int ch): Course(name, level, ch) {
        Code = name + "_" + "N" + to_string(level);
    }

};

#endif //S11_20225016_20225042_20235063_NORMALCOURSE_H
