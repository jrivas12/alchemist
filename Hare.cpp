#include "Hare.h"
#include <iostream>

Hare::Hare() {
    square = 1;
}

bool Hare::victor() {
    return square >= 70;
}

void Hare::win() {
    std::cout << "HARE WINS?" << std::endl;
}

void Hare::bigHop() {
    square += 9;
    if (square > 70)
        square = 70;
}

void Hare::bigSlip() {
    square -= 12;
    if (square < 1)
        square = 1;
}

void Hare::smallHop() {
    square += 1;
}

void Hare::smallSlip() {
    square -= 2;
    if (square < 1)
        square = 1;
}
