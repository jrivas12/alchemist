// Person.h
#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string name;
    int age;
public:
    Person(const std::string& name);

    std::string getName() const;
    int getAge() const;
};

#endif // PERSON_H
