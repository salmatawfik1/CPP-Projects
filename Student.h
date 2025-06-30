

#ifndef S11_20225016_20225042_20235063_STUDENT_H
#define S11_20225016_20225042_20235063_STUDENT_H
#include <iostream>
#include "Course.h"
using namespace std;

class Student{
protected:
    int level;
    int noofcourses;
    double grades[6];
    Course* courselist[6];
    string name, id;
    int inputcourses;
public:
    Student() {
        noofcourses = 0;
        for (int i = 0; i < 6; ++i) {
            courselist[i] = nullptr;
            grades[i] = 0;
        }
    }

    void setinputcourses(int no) {
        inputcourses = no;
    }
    void setNoOfRegistered(int no) {
        noofcourses = no;
    }
    void setlevel(int l) {
        level = l;
    }
    void setname(string& n){
        name = n;
    }
    void setID(string& Id){
        id = Id;
    }
    string getname(){
        return name;
    }
    string getid(){
        return id;
    }
    int getLevel(){
        return level;
    }
    void setgrades(double g[6]){
        for(int i=0; i<6; i++){
            grades[i] = g[i];
        }
    }

    void printregistercourse(){
        for(int i=0;i<inputcourses;i++)
        {
            cout<<*courselist[i]<<endl;
            cout<<"Grade for this course: "<<grades[i]<<"\n\n";
        }
    }
    virtual float calculateexpenses()=0;

    virtual bool registercourse(Course* course) {
         if (inputcourses >= 1 && inputcourses <= 6)  {
             courselist[inputcourses - 1] = new Course(course->getName(), course->getMinLevel(), course->getHours());
            noofcourses++;
            return true;
        }
         else
             return false;
    }

   void setRegisteredCourses(Course* courses[], string search[]) {
       for (int i = 0; i < inputcourses; i++) {
           if (inputcourses >= 1 && inputcourses <= 6) {
               if (courselist[i] != nullptr) {
                   delete courselist[i];
               }
               courselist[i] = new Course(courses[i]->getName(), courses[i]->getMinLevel(), courses[i]->getHours());
               courselist[i]->setCode(search[i]);
           }
       }
   }

    double getTotalGPA(){
        double Sum=0.0;
        double Sumhours=0.0;
        for (int i=0;i<noofcourses;i++){
            Sum+=(getgpa(grades[i]))*courselist[i]->getHours();
            Sumhours+=courselist[i]->getHours();
        }
        return Sum/Sumhours;
    }

    double getgpa(double g){
        double gpa;

        if(g>=98&&g<=100){
            gpa=4.00;
        }
        if(g>=93&&g<=97){
            gpa=4.00;
        }
        if(g>=90&&g<=92){
            gpa=3.70;
        }
        if(g>=87&&g<=89){
            gpa=3.30;
        }
        if(g>=83&&g<=86){
            gpa=3.00;
        }
        if(g>=80&&g<=82){
            gpa=2.70;
        }
        if(g>=77&&g<=79){
            gpa=2.30;
        }
        if(g>=73&&g<=76){
            gpa=2.00;
        }
        if(g>=70&&g<=72){
            gpa=1.70;
        }
        if(g>=67&&g<=69){
            gpa=1.30;
        }
        if(g>=63&&g<=66){
            gpa=1.00;
        }
        if(g>=60&&g<=62){
            gpa=0.70;
        }
        if(g<60){
            gpa=0.00;
        }
        return gpa;
    }
    virtual ~Student() {
        for (int i = 0; i < inputcourses; ++i) {
            delete courselist[i];
        }
    }
};

#endif //S11_20225016_20225042_20235063_STUDENT_H
