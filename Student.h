// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    double gpa;
    int id;
public:
    Student(const std::string& name);

    double getGPA() const;
    int getID() const;
};

#endif // STUDENT_H