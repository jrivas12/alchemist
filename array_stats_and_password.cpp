#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ArrayStats.h"

using namespace std;

void generatePassword(char* array, int size) {
    const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = charset[rand() % (sizeof(charset) - 1)]; // Exclude null terminator
    }
}

void randomizeDoubles(double* array, int size) {
    srand(time(nullptr));
    for (int i = 0; i < size; ++i) {
        array[i] = (rand() % 10000) / 100.0; // Random doubles between 0.00 and 99.99
    }
}

int main() {
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

    return 0;
}
