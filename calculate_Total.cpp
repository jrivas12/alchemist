#include <iostream>
using namespace std;

int main () {
        int total {0};
        unsigned int gradeCounter{1};

while (gradeCounter <= 10) {
        cout << "Enter grade: ";
        int grade;
        cin  >> grade;
        total = total + grade;
        gradeCounter = gradeCounter + 1;
}

int average{total / 10};

cout << "\nTotal of all 10 grades is " << total;
cout << "\nClass average is "          << average << endl;
}                                                                                                                 