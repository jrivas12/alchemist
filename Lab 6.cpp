#include <iostream>
#include <iomanip>
using namespace std;

void kirchhoffs_law();

int main() {
    cout << "\033[1m\033[32mKirshhoffs Circuit Law: Lab 6\n\033[0m";
    kirchhoffs_law();
    return 0;
}

void kirchhoffs_law() {
    double R1, R2, R3, R4, R5;
    double V1, V2;
    double I1, I2;

    cout << "\033[36m\033[1m\nEnter the values for the resistances in Ω:\033[0m" << endl;
    cout << "\033[34mResistance 1 (R1): \033[0m";
    cin >> R1;
    cout << "\033[34mResistance 2 (R2): \033[0m";
    cin >> R2;
    cout << "\033[34mResistance 3 (R3): \033[0m";
    cin >> R3;
    cout << "\033[34mResistance 4 (R4): \033[0m";
    cin >> R4;
    cout << "\033[34mResistance 5 (R5): \033[0m";
    cin >> R5;

    cout << "\033[36m\033[1m\nEnter the values for the voltages in V:\033[0m" << endl;
    cout << "\033[32mVoltage 1 (V1): \033[0m";
    cin >> V1;
    cout << "\033[32mVoltage 2 (V2): \033[0m";
    cin >> V2;

    I1 = (V1 * R2 + V1 * R4 + V1 * R5 - V2 * R4) / (R1 * (R2 + R4 + R5) + R4 * (R2 + R5 + R3) + R3 * (R2 + R5));
    I2 = (V2 - I1 * R4) / (R2 + R4 + R5);

    cout << "\033[33m\nThe calculated currents are:\033[0m" << endl;
    cout << "\033[31mI1 = \033[0m" << fixed << setprecision(3) << I1 << "\033[31m A\033[0m" << endl;
    cout << "\033[31mI2 = \033[0m" << fixed << setprecision(3) << I2 << "\033[31m A\033[0m" << endl;

    cout << "\033[0;37m        +---------+                +---------+           \n";
    cout << "\033[0;37m   +----| " << setw(7) << fixed << setprecision(3) << R1 << " |--["
        << setw(6) << fixed << setprecision(3) << I1 << " A]----| " << setw(7) << R2 << " |----+      \n";
    cout << "\033[0;37m   |    +---------+             |  +---------+    |      \n";
    cout << "\033[0;37m   |                            |                 |      \n";
    cout << "\033[0;37m  [ " << setw(5) << V1 << "V ]                    |               ["
        << setw(6) << I2 << " A]   \n";
    cout << "\033[0;37m   |                   +---------+                |      \n";
    cout << "\033[0;37m   |                   | " << setw(7) << R3 << " |        +---------+\n";
    cout << "\033[0;37m   |                   +---------+        | " << setw(7) << R4 << " |\n";
    cout << "\033[0;37m   |                       |              +---------+\n";
    cout << "\033[0;37m   |      +---------+      |                      |      \n";
    cout << "\033[0;37m   +------| " << setw(7) << R5 << " |------+--[ " << setw(5) << V2 << "V ]----------+      \n";
    cout << "\033[0;37m          +---------+                                \033[0m\n";
}
