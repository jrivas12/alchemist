#include "Tortoise.h"
#include <iostream>

Tortoise::Tortoise() {
    square = 1;
}

bool Tortoise::victor() {
    return square >= 70;
}

void Tortoise::win() {
    std::cout << "TORTOISE WINS!!!" << std::endl;
}

void Tortoise::fastPlod() {
    square += 3;
    if (square > 70)
        square = 70;
}

void Tortoise::slip() {
    square -= 6;
    if (square < 1)
        square = 1;
}

void Tortoise::slowPlod() {
    square += 1;
}
