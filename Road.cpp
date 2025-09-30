// Road.cpp
#include "Road.h"
#include <iostream>
#include <limits>

Road::Road() : lanes(0), speedLimit(0) {}

Road::Road(const std::string& name, int lanes, int speedLimit)
    : name(name), lanes(lanes), speedLimit(speedLimit) {}

Road::~Road() {}

void Road::input() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter lanes: ";
    while (!(std::cin >> lanes)) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Invalid input. Please enter a valid number for lanes: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter speed limit: ";
    while (!(std::cin >> speedLimit)) {
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Invalid input. Please enter a valid number for speed limit: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void Road::display() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Lanes: " << lanes << "\n";
    std::cout << "Speed limit: " << speedLimit << "\n";
}

Toll::Toll() : tollFee(0) {}

Toll::Toll(const std::string& name, int lanes, int speedLimit, int tollFee)
    : Road(name, lanes, speedLimit), tollFee(tollFee) {}

void Toll::input() {
    Road::input();
    std::cout << "Enter toll fee: ";
    while (!(std::cin >> tollFee) || tollFee < 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a valid toll fee: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Toll::display() const {
    Road::display();
    std::cout << "Toll fee: " << tollFee << "\n";
}
