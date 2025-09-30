#include <iostream>
using namespace std;

int main() {
    const int SIZE = 20;
    int numbers[SIZE];
    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        int num;
        bool occurrence = false;
        cout << "Enter a number between 1 and 20: ";
        cin >> num;

        while (num < 1 || num > 20) {
            cout << "Fatal error! Please try again: ";
            cin >> num;
        }

        for (int j = 0; j < count; j++) {
            if (numbers[j] == num) {
                occurrence = true;
                break;
            }
        }

        if (!occurrence) {
            numbers[count] = num;
            count++;
        }
    }

    cout << "Here's your ordered dictionary of numbers: \n";
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
