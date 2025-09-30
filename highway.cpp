// main.cpp
#include "Road.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits> 

void writeToFile(const Road& road, const std::string& filename, char type) {
    std::ofstream file(filename, std::ios::app);
    if (file.is_open()) {
        file << type << "," << road.name << "," << road.lanes << "," << road.speedLimit;
        if (type == 'T') {
            file << "," << static_cast<const Toll&>(road).tollFee;
        }
        file << "\n";
        file.close();
    } else {
        std::cerr << "Error opening file: " << filename << "\n";
    }
}

std::vector<Road*> readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    char type;
    std::string name;
    int lanes, speedLimit, tollFee; 
    std::vector<Road*> roads;

    if (file.is_open()) {
        while (file >> type) {
            file.ignore();

            std::getline(file, name, ',');
            file >> lanes;
            file.ignore();

            file >> speedLimit;
            file.ignore(); 

            if (type == 'T') {
                file >> tollFee; 
                Toll* toll = new Toll(name, lanes, speedLimit, tollFee);
                roads.push_back(toll);
            } else {
                Road* road = new Road(name, lanes, speedLimit);
                roads.push_back(road);
            }
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // move to the next line
        }
        file.close();
    } else {
        std::cerr << "Error opening file: " << filename << "\n";
    }
    return roads;
}

int main() {
    std::vector<Road*> roads;
    int choice;

    do {
        std::cout << "1. Enter a new Road\n2. Enter a new Toll\n3. View current Roads and Tolls\n4. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Road road;
                road.input();
                roads.push_back(new Road(road));
                writeToFile(road, "roads.csv", 'R');
                break;
            }
            case 2: {
                Toll toll;
                toll.input();
                roads.push_back(new Toll(toll));
                writeToFile(toll, "roads.csv", 'T');
                break;
            }
            case 3: {
                std::vector<Road*> roadsFromFile = readFromFile("roads.csv");
                for (const auto& road : roadsFromFile) {
                    road->display();
                }
                for (auto& road : roadsFromFile) {
                    delete road;
                }
                break;
            }
            case 4:
                for (auto& road : roads) {
                    delete road;
                }
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
    } while (choice != 4);

    return 0;
}