#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "ArrayStats.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "records_sorter.h"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

using namespace std;

// Forward declarations for program_option1 and program_option2
void program_option1();
void program_option2();
void program_option3();
void program_option4();
void generatePassword(char* array, int size);
void randomizeDoubles(double* array, int size);

// Define MainMenu class
class MainMenu {
private:
    std::map<std::string, std::pair<std::string, void(*)()>> topics;

public:
    MainMenu() {
        topics = {
            {"1", {"\033[94mProgram1", &program_option1}},
            {"2", {"\033[93mProgram2", &program_option2}},
            {"3", {"\033[93mProgram3", &program_option3}},
            {"4", {"\033[93mProgram4", &program_option4}},
            // Add other topics here...
        };
    }

    void display() {
        std::cout << "\033[96m=== Main Menu ===\033[0m" << std::endl;
        for (const auto& topic : topics) {
            std::cout << topic.first << ". " << topic.second.first << std::endl;
        }
        std::cout << "0. Exit" << std::endl;
    }

    void selectTopic(const std::string& choice) {
        if (topics.find(choice) != topics.end()) {
            topics[choice].second();
        } else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }
};

// Define program_option1 function
void program_option1() {
    try {
        int size;
        cout << "Enter the size of the arrays: ";
        cin >> size;

        ArrayStats<int> intArray(size, 10);
        intArray.randomizeValues();
        cout << "\033[1;32mMax value in intArray: \033[0m" << intArray.findMax() << endl;
        cout << "\033[1;33mMin value in intArray: \033[0m" << intArray.findMin() << endl;

        ArrayStats<double> doubleArray(size, 10.5);
        randomizeDoubles(doubleArray.getArray(), size);
        cout << "\033[1;34mMax value in doubleArray: \033[0m" << doubleArray.findMax() << endl;
        cout << "\033[1;35mMin value in doubleArray: \033[0m" << doubleArray.findMin() << endl;

        ArrayStats<char> charArray(8, ' '); // Password-like string of up to 8 characters
        generatePassword(charArray.getArray(), 8);
        cout << "\033[1;36mPassword-like string in charArray: \033[0m";
        for (int i = 0; i < 8; ++i) {
            cout << charArray.getArray()[i];
        }
        cout << endl;
    } catch (const invalid_argument& e) {
        cerr << "\033[1;38mError: \033[0m" << e.what() << endl;
    }
}
void sequence(int n, int steps) {
    if (n == 1 || steps >= n) {
        cout << "n              = " << GREEN << n << RESET << endl;
        cout << "Number of steps = " << YELLOW << steps << RESET << endl;
        return;
    }
    cout << "n              = " << GREEN << n << RESET << endl;
    if (n % 2 == 0) {
        cout << "n * 3 + 1      = " << YELLOW << n * 3 + 1 << RESET << endl;
        sequence(n / 2, steps + 1);
    } else {
        cout << "n / 2          = " << YELLOW << n / 2 << RESET << endl;
        sequence(3 * n + 1, steps + 1);
    }
}
// Define program_option2 function
void program_option2() {
    // Implement program_option2 logic here
    int input_value;

    cout << "Enter the starting point: " << GREEN << RESET << endl;
    cin >> input_value;

    sequence(input_value, 0);
}
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << "\033[1;36m" << setw(4) << num << "\033[0m";
    }
    cout << endl;
}

vector<int>::iterator findMinIndex(vector<int>::iterator start, vector<int>::iterator end) {
    return min_element(start, end);
}

void selectionSortRecursive(vector<int>& arr, vector<int>::iterator start, vector<int>::iterator end) {
    if (start == end) {
        return;
    }
    auto minIndex = findMinIndex(start, end);
    if (minIndex != start) {
        iter_swap(minIndex, start);
    }
    selectionSortRecursive(arr, start + 1, end);
}

void program_option3() {
    srand(time(nullptr));

    const int SIZE = 20;
    const int MAX_RANDOM_VALUE = 100;
    vector<int> arr(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % MAX_RANDOM_VALUE;
    }

    cout << "\nUnsorted array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    sort(arr.begin(), arr.end());

    cout << "\nSorted array:" << endl;
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
// Define generatePassword function
void generatePassword(char* array, int size) {
    const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = charset[rand() % (sizeof(charset) - 1)]; // Exclude null terminator
    }
}

// Define randomizeDoubles function
void randomizeDoubles(double* array, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = (rand() % 10000) / 100.0; // Random doubles between 0.00 and 99.99
    }
}

void program_option4() {
    // Implement program_option2 logic here
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
}

int main() {
    // Instantiate MainMenu object
    MainMenu menu;
    std::string choice;

    // Main menu loop
    do {
        menu.display();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == "0") {
            break;
        }

        menu.selectTopic(choice);
    } while (true);

    return 0;
}
