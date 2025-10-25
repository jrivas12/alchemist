#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <string>
#include <iomanip>
#include "Student.h"
using namespace std;

void swap(Student* &a, Student* &b);

void bubbleSort(Student* arr[], int n);

int main() {
    srand(time(nullptr));

    int numStudents;
    cout << "Enter the number of students: ";
    cin >> numStudents;

    Student** students = new Student*[numStudents];
    for (int i = 0; i < numStudents; ++i) {
        string name;
        cout << "Enter the name for student " << i + 1 << ": ";
        cin >> name;
        students[i] = new Student(name);
    }

    cout << "\033[1;32m\nStudents:\n\033[0m";
    cout << "\033[1;33m|-------------------------------------|\n";
    cout << "\033[1;33m|  Name      |  Age  |   GPA  |  ID   |\n";
    cout << "\033[1;33m|-------------------------------------|\n\033[0m";
    for (int i = 0; i < numStudents; ++i) {
        cout << "\033[1;34m| " << setw(10) << students[i]->getName() << " | "
                  << setw(5) << students[i]->getAge() << " | "
                  << setw(5) << fixed << setprecision(2) << students[i]->getGPA() << " | "
                  << setw(5) << students[i]->getID() << "  |\033[0m\n";
    }

    bubbleSort(students, numStudents);

    cout << "\033[1;32m\nStudents (Sorted):\n\033[0m";
    cout << "\033[1;33m|-------------------------------------|\n";
    cout << "\033[1;33m|  Name      |  Age  |   GPA  |  ID   |\n"; 
    cout << "\033[1;33m|-------------------------------------|\n\033[0m"; 
    for (int i = 0; i < numStudents; ++i) {
        cout << "\033[1;34m| " << setw(10) << students[i]->getName() << " | " 
                  << setw(5) << students[i]->getAge() << " | "
                  << setw(5) << fixed << setprecision(2) << students[i]->getGPA() << " | "
                  << setw(5) << students[i]->getID() << "  |\033[0m\n"; 
    }

    for (int i = 0; i < numStudents; ++i) {
        delete students[i];
    }
    delete[] students;

    return 0;
}

void swap(Student* &a, Student* &b) {
    Student* temp = a;
    a = b;
    b = temp;
}

void bubbleSort(Student* arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j]->getGPA() < arr[j + 1]->getGPA()) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
