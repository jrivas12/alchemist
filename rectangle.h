#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle {
public:
        Rectangle(double length, double width);
        double get_perimeter() const;
        double get_area() const;
        double get_length() const;
        double get_width() const;
        friend ostream& operator<<(ostream& os, const Rectangle& rectangle);

private:
        double length;
        double width;
};

#endif