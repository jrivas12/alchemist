// Hare.h
#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

class Hare {
public:
    Hare() : square(1) {}
    void move();
    bool victor() const;
    void win() const;
    int square;
};

inline void Hare::move() {
    int x = 1 + rand() % 10;
    if (x >= 1 && x <= 2) {
        square += 0;
    }
    else if (x >= 3 && x <= 4) {
        square += 9;
    }
    else if (x == 5) {
        square -= 12;
    }
    else if (x >= 6 && x <= 8) {
        ++square;
    }
    else {
        square -= 2;
    }
    if (square < 1) {
        square = 1;
    }
}

inline bool Hare::victor() const {
    return square >= 70;
}

inline void Hare::win() const {
    std::cout << "HARE WINS!!! YAY!!!" << std::endl;
}