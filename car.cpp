#include <iostream>
#include <string>
using namespace std;

class Car {

private:
    int year;
    string make;
    string model;
    int speed = 0;

public:
    void setYear(int);
    void setMake(string);
    void setModel(string);
    void setSpeed(int);
    int getYear();
    string getMake();
    string getModel();
    int getSpeed();
    void accelerate();
    void brake();
};

void Car::setYear(int x) {
    year = x;
}

int Car::getYear() {
    return year;
}

void Car::setMake(string y) {
    make = y;
}

string Car::getMake() {
    return make;
}

void Car::setModel(string z) {
    model = z;
}

string Car::getModel() {
    return model;
}

void Car::setSpeed(int spd) {
    speed = spd;
}

int Car::getSpeed() {
    return speed;
}

void Car::accelerate() {
    speed += 5;
}

void Car::brake() {
    if (speed > 5) {
        speed -= 5;
    } else {
        speed = 0;
    }
}

int main() {
    Car myCar;
    int Year = 0;
    string Make, Model;
    cout << "Please enter the year of the vehicle: ";
    cin >> Year;
    cout << "Please enter the make of the vehicle: ";
    cin >> Make;
    cout << "Please enter the model of the vehicle: ";
    cin >> Model;

    myCar.setYear(Year);
    cout << "You entered the year of the car as " << myCar.getYear() << endl;
    myCar.setMake(Make);
    cout << "You entered the make of the car as " << myCar.getMake() << endl;
    myCar.setModel(Model);
    cout << "You entered the model of the car as " << myCar.getModel() << endl;

    for (int i = 0; i < 5; ++i) {
        myCar.accelerate();
        cout << "Accelerating. The current speed of the car is: " << myCar.getSpeed() << endl;
    }

    for (int j = 0; j < 5; ++j) {
        myCar.brake();
        cout << "Decelerating. The current speed of the car is: " << myCar.getSpeed() << endl;
    }

    return 0;
}