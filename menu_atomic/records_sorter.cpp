#include "records_sorter.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

bool compareByGPA(const Student& s1, const Student& s2) {
    return s1.gpa < s2.gpa;
}

void loadStudentRecords(vector<Student>& students) {
    ifstream inputFile("students.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            string lastName, firstName;
            double gpa;
            if (getline(iss, lastName, ',') &&
                getline(iss, firstName, ',') &&
                iss >> gpa) {
                Student student;
                student.name = lastName + " " + firstName;
                student.gpa = gpa;
                students.push_back(student);
            } else {
                cout << "Error reading data for student: " << line << endl;
            }
        }
        inputFile.close();
    } else {
        cout << "Failed to open students.txt" << endl;
    }
}

void viewData(const vector<Student>& students) {
    cout << students.size() << endl;
    for (const auto& student : students) {
        cout << student.name << " " << student.gpa << endl;
    }
}

void merge(vector<Student>& students, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Student> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = students[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = students[mid + 1 + j];
        
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].gpa <= R[j].gpa) {
            students[k] = L[i];
            i++;
        } else {
            students[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        students[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        students[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Student>& students, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(students, left, mid);
        mergeSort(students, mid + 1, right);

        merge(students, left, mid, right);
    }
}

void mergeSortData(vector<Student>& students) {
    mergeSort(students, 0, students.size() - 1);
}

int partitionQuick(vector<Student>& students, int low, int high) {
    double pivot = students[high].gpa;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (students[j].gpa < pivot) {
            i++;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return (i + 1);
}

void quickSortData(vector<Student>& students, int low, int high) {
    if (low < high) {
        int pi = partitionQuick(students, low, high);

        quickSortData(students, low, pi - 1);
        quickSortData(students, pi + 1, high);
    }
}
