

#ifndef S11_20225016_20225042_20235063_COURSE_H
#define S11_20225016_20225042_20235063_COURSE_H
#include <iostream>
using namespace std;

class Course {
protected:
    string Name, Code;
    int MinStudentLevel, CreditHours;
public:
    Course(): Name(" "), Code(" "), MinStudentLevel(0), CreditHours(0){}

    Course(const string &name, int level, int creditHours){
        Name = name;
        MinStudentLevel = level;
        CreditHours = creditHours;
    }
    int getHours(){
        return CreditHours;
    }
    int getMinLevel(){
        return MinStudentLevel;
    }
    string getCode(){
        return Code;
    }
    string getName(){
        return Name;
    }
    void setName(string& n){
        Name = n;
    }
    void setMinLevel(int l){
        MinStudentLevel = l;
    }
    void setHours(int h){
        CreditHours = h;
    }
    void setCode(string& coursecode) {
        Code = coursecode;
    }
    friend ostream& operator<<(ostream& op, Course& c1);
};
ostream& operator<<(ostream& op, Course& c1){
    op<<"Course Name: "<<c1.Name<<endl<<"Course code: "<<c1.Code<<endl;
    op<<"Minimum student level required to register the course: "<<c1.MinStudentLevel<<endl<<"Course Number of credit hours: "
      <<c1.CreditHours;
    return op;
}

#endif //S11_20225016_20225042_20235063_COURSE_H
