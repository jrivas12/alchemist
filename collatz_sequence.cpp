#include <iostream>
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RESET   "\x1b[0m"

using namespace std;


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

int main() {
    int input_value;

    cout << "Enter the starting point: " << GREEN << RESET << endl;
    cin >> input_value;

    sequence(input_value, 0);

    return 0;
}

