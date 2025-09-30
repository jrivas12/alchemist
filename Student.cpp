// Student.cpp
#include "Student.h"
#include <cstdlib>
#include <ctime>

Student::Student(const std::string& name) : Person(name) {
    gpa = (rand() % 401) / 100.0; 
    id = rand() % 9000 + 1000; 
}

double Student::getGPA() const {
    return gpa;
}

int Student::getID() const {
    return id;
}