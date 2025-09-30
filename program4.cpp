#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Coin {
private:
    string sideUp;

public:
    Coin() {
        srand(static_cast<unsigned int>(time(nullptr)));
        int toss = rand() % 2;
        if (toss == 0) {
            sideUp = "heads";
        }
        else {
            sideUp = "tails";
        }
    }

    string getSideUp() {
        return sideUp;
    }

    void toss() {
        int toss = rand() % 2;
        if (toss == 0) {
            sideUp = "heads";
        }
        else {
            sideUp = "tails";
        }
    }
};

int main() {
    int headCount = 0;
    int tailCount = 0;
    Coin c;
    vector<string> tossResults;
    cout << "Coin has '" << c.getSideUp() << "' facing up." << endl;
    tossResults.push_back(c.getSideUp());

    cout << "Randomizing coin toss, 20 times:" << endl;
    for (int i = 0; i < 20; i++) {
        c.toss();
        tossResults.push_back(c.getSideUp());
    }

    for (size_t i = 0; i < tossResults.size(); i++) {
        cout << i + 1 << ". " << tossResults[i] << endl;
        if (tossResults[i] == "heads") {
            headCount++;
        }
        else if (tossResults[i] == "tails") {
            tailCount++;
        }
    }

    cout << "Heads was facing up: " << headCount << endl;
    cout << "Tails was facing up: " << tailCount << endl;

    cout << "Press Enter to exit...";
    cin.get(); // Wait for user input (Enter key) before exiting

    return 0;
}