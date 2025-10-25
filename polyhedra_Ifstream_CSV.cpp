#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stack>
#include <queue>

using namespace std;

class Polyhedra {
public:
    string name;
    string wythoff;
    string symbol;
    string c_num;
    string w_num;
    string u_num;
    string k_num;
    int vertices;
    int edges;
    int faces;
    string faces_by_type;

    void display(int longest_line_length) const {
        cout << setw(longest_line_length) << left << name << " ";
        cout << setw(17) << left << wythoff << " ";
        cout << setw(6) << left << symbol << " ";
        cout << setw(8) << left << c_num << " ";
        cout << setw(6) << left << w_num << " ";
        cout << setw(6) << left << u_num << " ";
        cout << setw(6) << left << k_num << " ";
        cout << setw(6) << left << vertices << " ";
        cout << setw(8) << left << edges << " ";
        cout << setw(6) << left << faces << " ";
        cout << setw(10) << left << faces_by_type << "\n";
    }
};

int main() {
    vector<Polyhedra> data;
    ifstream inputFile("polyhedra.csv");
    if (inputFile) {
        string line;
        while (getline(inputFile, line)) {
            stringstream ss(line);
            Polyhedra polyhedron;
            getline(ss, polyhedron.name, ',');
            getline(ss, polyhedron.wythoff, ',');
            getline(ss, polyhedron.symbol, ',');
            getline(ss, polyhedron.c_num, ',');
            getline(ss, polyhedron.w_num, ',');
            getline(ss, polyhedron.u_num, ',');
            getline(ss, polyhedron.k_num, ',');
            ss >> polyhedron.vertices;
            ss.ignore();
            ss >> polyhedron.edges;
            ss.ignore();
            ss >> polyhedron.faces;
            ss.ignore();
            getline(ss, polyhedron.faces_by_type, '\n');
            data.push_back(polyhedron);
        }
        inputFile.close();
    } else {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int longest_line_length = 0;
    for (const auto& polyhedron : data) {
        if (polyhedron.name.length() > longest_line_length) {
            longest_line_length = polyhedron.name.length();
        }
    }

    stack<Polyhedra> myStack;
    queue<Polyhedra> myQueue;

    for (const auto& polyhedron : data) {
        myStack.push(polyhedron);
        myQueue.push(polyhedron);
    }

    int choice = 0;
    while (choice != 4) {
        cout << "\nMenu:\n";
        cout << "1. List Original Data\n";
        cout << "2. Report of Stack of Data\n";
        cout << "3. Report of Queue of Data\n";
        cout << "4. End Program\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nOriginal Data:\n";
                cout << setw(longest_line_length) << left << "Name" << " ";
                cout << setw(17) << left << "Wythoff" << " ";
                cout << setw(6) << left << "Symbol" << " ";
                cout << setw(8) << left << "C#" << " ";
                cout << setw(6) << left << "W#" << " ";
                cout << setw(6) << left << "U#" << " ";
                cout << setw(6) << left << "K#" << " ";
                cout << setw(6) << left << "Vertices" << " ";
                cout << setw(8) << left << "Edges" << " ";
                cout << setw(6) << left << "Faces" << " ";
                cout << setw(10) << left << "Faces by Type" << "\n";
                for (const auto& polyhedron : data) {
                    polyhedron.display(longest_line_length);
                }
                break;
            case 2:
                cout << "\nStack of Data:\n";
                while (!myStack.empty()) {
                    Polyhedra polyhedron = myStack.top();
                    polyhedron.display(longest_line_length);
                    myStack.pop();
                }
                break;
            case 3:
                cout << "\nQueue of Data:\n";
                while (!myQueue.empty()) {
                    Polyhedra polyhedron = myQueue.front();
                    polyhedron.display(longest_line_length);
                    myQueue.pop();
                }
                break;
            case 4:
                cout << "\nExiting program.\n";
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
