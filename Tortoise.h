// Tortoise.h
#pragma once
#include <string>
#include <cstdlib>
#include <ctime>

class Tortoise {
public:
    Tortoise() : square(1) {}
    void move();
    bool victor() const;
    void win() const;
    int square;
};

inline void Tortoise::move() {
    int x = 1 + rand() % 10;
    if (x >= 1 && x <= 5) {
        square += 3;
    }
    else if (x >= 6 && x <= 7) {
        square -= 6;
    }
    else {
        ++square;
    }
    if (square < 1) {
        square = 1;
    }
}

inline bool Tortoise::victor() const {
    return square >= 70;
}

inline void Tortoise::win() const {
    std::cout << "TORTOISE WINS!!! YAY!!!" << std::endl;
}

