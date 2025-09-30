// Person.cpp
#include "Person.h"
#include <cstdlib>
#include <ctime>

Person::Person(const std::string& name) : name(name) {
    age = rand() % 13 + 20;
}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}