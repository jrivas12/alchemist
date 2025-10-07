// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Student.h"
using namespace std;

int main() {
    srand(time(nullptr));

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    vector<Student> students;
    students.reserve(numStudents);

    for (int i = 0; i < numStudents; ++i) {
        string name;
        cout << "Enter the name for student " << i + 1 << ": ";
        cin >> name;
        students.emplace_back(name);
    }

    cout << "\033[1;32m\nStudents:\n\033[0m";
    cout << "\033[1;33m|-------------------------------------|\n";
    cout << "\033[1;33m|  Name      |  Age  |   GPA  |  ID   |\n";
    cout << "\033[1;33m|-------------------------------------|\n\033[0m";
    for (const auto& student : students) {
        cout << "\033[1;34m| " << setw(10) << student.getName() << " | "
                  << setw(5) << student.getAge() << " | "
                  << setw(5) << fixed << setprecision(2) << student.getGPA() << " | "
                  << std::setw(5) << student.getID() << "  |\033[0m\n";
    }

    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getGPA() > b.getGPA();
    });

    cout << "\033[1;32m\nStudents (Sorted):\n\033[0m";
    cout << "\033[1;33m|-------------------------------------|\n";
    cout << "\033[1;33m|  Name      |  Age  |   GPA  |  ID   |\n"; 
    cout << "\033[1;33m|-------------------------------------|\n\033[0m"; 
    for (const auto& student : students) {
        cout << "\033[1;34m| " << setw(10) << student.getName() << " | "
                  << setw(5) << student.getAge() << " | "
                  << setw(5) << fixed << setprecision(2) << student.getGPA() << " | "
                  << std::setw(5) << student.getID() << "  |\033[0m\n";
    }

    return 0;
}