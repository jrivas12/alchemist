#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

struct Student {
    std::string name;
    double gpa;
};

bool compareByGPA(const Student& s1, const Student& s2) {
    return s1.gpa < s2.gpa;
}

void loadStudentRecords(std::vector<Student>& students) {
    std::ifstream inputFile("students.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string lastName, firstName;
            double gpa;
            if (std::getline(iss, lastName, ',') &&
                std::getline(iss, firstName, ',') &&
                iss >> gpa) {
                Student student;
                student.name = lastName + " " + firstName;
                student.gpa = gpa;
                students.push_back(student);
            } else {
                std::cout << "Error reading data for student: " << line << std::endl;
            }
        }
        inputFile.close();
    } else {
        std::cout << "Failed to open students.txt" << std::endl;
    }
}

void viewData(const std::vector<Student>& students) {
    std::cout << students.size() << std::endl;
    for (const auto& student : students) {
        std::cout << student.name << " " << student.gpa << std::endl;
    }
}

void merge(std::vector<Student>& students, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Student> L(n1), R(n2);

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

void mergeSort(std::vector<Student>& students, int left, int right) {
    std::cout << "mergeSort called with left=" << left << " right=" << right << std::endl;
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(students, left, mid);
        mergeSort(students, mid + 1, right);

        merge(students, left, mid, right);
    }
}

void mergeSortData(std::vector<Student>& students) {
    std::cout << "mergeSortData called" << std::endl;
    mergeSort(students, 0, students.size() - 1);
}

void quickSortData(std::vector<Student>& students, int low, int high);

int partitionQuick(std::vector<Student>& students, int low, int high) {
    double pivot = students[high].gpa;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (students[j].gpa < pivot) {
            i++;
            std::swap(students[i], students[j]);
        }
    }
    std::swap(students[i + 1], students[high]);
    return (i + 1);
}

void quickSortData(std::vector<Student>& students, int low, int high) {
    if (low < high) {
        int pi = partitionQuick(students, low, high);

        quickSortData(students, low, pi - 1);
        quickSortData(students, pi + 1, high);
    }
}

int main() {
    std::vector<Student> students;
    int option;
    int low, high; 

    do {
        std::cout << "|---------------------------------------|" << std::endl;
        std::cout << "|         Student Records Sorter        |" << std::endl;
        std::cout << "|---------------------------------------|" << std::endl;
        std::cout << "|Option | Description                   |" << std::endl;
        std::cout << "|-------|-------------------------------|" << std::endl;
        std::cout << "| 1     | Load student records          |" << std::endl;
        std::cout << "| 2     | View data                     |" << std::endl;
        std::cout << "| 3     | MergeSort data                |" << std::endl;
        std::cout << "| 4     | QuickSort data                |" << std::endl;
        std::cout << "| 5     | Exit                          |" << std::endl;
        std::cout << "|---------------------------------------|" << std::endl;
        std::cout << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;
        std::cout << std::endl;

        switch (option) {
            case 1:
                std::cout << "Loading Student Data...";
                loadStudentRecords(students);
                break;
            case 2:
                viewData(students);
                break;
            case 3:
                mergeSortData(students);
                viewData(students);
                break;
            case 4:
                low = 0;
                high = students.size() - 1;
                quickSortData(students, low, high);
                viewData(students);
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }

        std::cout << std::endl;
    } while (option != 5);

    return 0;
}
