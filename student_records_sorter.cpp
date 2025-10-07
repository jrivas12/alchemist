#include "records_sorter.h"
#include <iostream>
using namespace std;

int main() {
    vector<Student> students;
    int option;

    do {
        cout << "|---------------------------------------|" << endl;
        cout << "|         Student Records Sorter        |" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "|Option | Description                   |" << endl;
        cout << "|-------|-------------------------------|" << endl;
        cout << "| 1     | Load student records          |" << endl;
        cout << "| 2     | View data                     |" << endl;
        cout << "| 3     | MergeSort data                |" << endl;
        cout << "| 4     | QuickSort data                |" << endl;
        cout << "| 5     | Exit                          |" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << endl;
        cout << "Choose an option: ";
        cin >> option;
        cout << endl;

        switch (option) {
            case 1:
                cout << "Loading Student Data...";
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
                quickSortData(students, 0, students.size() - 1);
                viewData(students);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (option != 5);

    return 0;
}

