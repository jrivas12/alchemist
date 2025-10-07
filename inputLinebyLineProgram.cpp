#include <iostream>
#include <fstream>
using namespace std;

void write_appendPoem();

int main() {
    write_appendPoem();

    return 0;
}
void write_appendPoem() {
    ofstream poem_input("poem_input.txt", ios::app);

    if (!poem_input) {
        cerr << "Failed to open the poem." << endl;
        return;
    }
    cout << "Please enter a poem (-1 to end input)" << endl;
    string line;
    while (true) {
        cout << "Enter new line: ";
        getline(cin, line);

        if (line == "-1")
            break;

        poem_input << line << endl;
    }

    poem_input.close();
}
