#ifndef RECORDS_SORTER_H
#define RECORDS_SORTER_H

#include <vector>
#include <string>
using namespace std;

struct Student {
    std::string name;
    double gpa;
};

bool compareByGPA(const Student& s1, const Student& s2);

void loadStudentRecords(std::vector<Student>& students);

void viewData(const std::vector<Student>& students);

void mergeSortData(std::vector<Student>& students);

void quickSortData(std::vector<Student>& students, int low, int high);

#endif /* RECORDS_SORTER_H */
