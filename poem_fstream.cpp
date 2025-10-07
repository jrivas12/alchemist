#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string poem_output = "poem.txt";
    ifstream vector(poem_output);

    if (vector.is_open()) {
        string line;
        while (getline(vector, line)) {
            cout << line << endl;
        }
        vector.close();
    } else {
        cout << "Failed to open the poem." << endl;
    }
    return 0;
}
