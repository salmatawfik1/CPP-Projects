#include <iostream>
#include "Course.h"
#include "NormalCourse.h"
#include "SummerCourse.h"
#include "Student.h"
#include "GeneralProgramStudent.h"
#include "SpecialProgramStudent.h"
using namespace std;

Course* COURSES [] = {new NormalCourse("Math", 1, 2),
                      new NormalCourse("Programming_1", 1, 3),
                      new NormalCourse("Technical_Writing", 1, 3),
                      new NormalCourse("Electronics", 2, 4),
                      new NormalCourse("Data_Structures", 2, 3),
                      new NormalCourse("OOP", 2, 3),
                      new NormalCourse("Algorithms", 3, 2),
                      new NormalCourse("Operating_Systems", 3, 3),
                      new NormalCourse("Databases", 3, 3),
                      new NormalCourse("Machine_Learning", 4, 3),
                      new NormalCourse("Compilers", 4, 4),
                      new NormalCourse("Programming_Concepts", 4, 4),
                      new SummerCourse("Math", 1, 2),
                      new SummerCourse("Compilers", 4, 4),
                      new SummerCourse("Algorithms", 3, 2),
                      new SummerCourse("OOP", 2, 3)
};
Course*searchCourse(const string& code){
    for(int i=0; i<16; i++){
        if(COURSES[i]->getCode() == code){
            return COURSES[i];
        }
    }
    return nullptr;
}
int main() {
    int n, choice, a=0, l;
    string Name, id;
    cout << "Enter the students number: " << endl;
    cin >> n;
    Student *students[n];
    for (int j = 0; j < n; j++) {
        cout << "Enter student type (0: general, 1: special): " << endl;
        cin >> choice;
        switch (choice) {
            case 0: {
                students[j] = new GeneralProgramStudent;
                break;
            }
            case 1: {
                students[j] = new SpecialProgramStudent;
                break;
            }
            default:
                cout << "Invalid choice.\n";
                break;
        }
        cout << "enter the name: " << endl;
        cin.ignore();
        getline(cin, Name);
        students[j]->setname(Name);
        cout << "enter the id: " << endl;
        cin >> id;
        students[j]->setID(id);
        cout << "enter the student level: " << endl;
        cin >> l;
        students[j]->setlevel(l);
        cout << "enter the courses number: " << endl;
        cin >> a;
        while (a > 6) {
            cout << "Error: You can't register in more than 6 courses. Please enter again: " << endl;
            cin >> a;
        }
        students[j]->setinputcourses(a);
        double grades[a];
        Course* foundCourses[a];
        string coursecodes[6];
        for (int i = 0; i < a; i++) {
            cout << "enter the course code for course number " << i + 1 << ": ";
            cin >> coursecodes[i];
            foundCourses[i] = searchCourse(coursecodes[i]);
            if (foundCourses[i] != nullptr) {
                bool registerdone = students[j]->registercourse(foundCourses[i]);
                if (registerdone) {
                    cout << "enter grade for this course: ";
                    cin >> grades[i];
                    students[j]->getgpa(grades[i]);
                } else {
                    if(students[j]->getLevel()<foundCourses[i]->getMinLevel() && choice == 0){
                        cout<<"Error: You can't register in this course. Please enter another course"<<endl;
                    }
                    if(a>6){
                        cout << "Error: You cannot register in more than 6 courses" << endl;
                    }
                    i--;
                }
            } else {
                cout << "Course not found. Please re-enter the code" << endl;
                i--;
            }
        }
        cout<<endl;
        students[j]->setNoOfRegistered(a);
        students[j]->setRegisteredCourses(foundCourses, coursecodes);
        students[j]->setgrades(grades);
    }
    for (int i = 0; i < n; i++) {
        cout << "Student name: " << students[i]->getname() << endl;
        cout << "ID: " << students[i]->getid() << endl;
        cout << "Level: " << students[i]->getLevel() << endl;
        cout << "Registered Courses: " << endl << endl;
        students[i]->printregistercourse();
        cout << "Overall GPA: "<< students[i]->getTotalGPA() << endl;
        cout << "Student expenses: "<< students[i]->calculateexpenses() << endl << endl;
    }
    for (int i = 0; i < 16; i++) {
        delete COURSES[i];
    }
    for (int i = 0; i < n; i++) {
        delete students[i];
    }
    return 0;
}