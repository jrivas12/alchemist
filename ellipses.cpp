#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double h, k; // Center coordinates (h, k)
    double numX, numY; // Numerators for (x - h)^2 and (y - k)^2

    // Get user input for ellipse parameters
    cout << "Enter the center coordinates (h, k): ";
    cin >> h >> k;
    cout << "Enter the numerator for (x - h)^2: ";
    cin >> numX;
    cout << "Enter the numerator for (y - k)^2: ";
    cin >> numY;

    // Calculate the semi-major and semi-minor axes
    double a = sqrt(numX);
    double b = sqrt(numY);

    // Calculate values of 'c' and 'e' (eccentricity)
    double c = sqrt(a * a - b * b);
    double e = c / a;

    // Calculate domain and range
    double domain = h + a;
    double range = k + b;

    // Calculate vertices
    double vertex1_x = h - a;
    double vertex1_y = k;
    double vertex2_x = h + a;
    double vertex2_y = k;

    // Calculate foci
    double focus1_x = h - c;
    double focus1_y = k;
    double focus2_x = h + c;
    double focus2_y = k;

    // Calculate endpoints of major and minor axes
    double endpoint1_x = h;
    double endpoint1_y = k - b;
    double endpoint2_x = h;
    double endpoint2_y = k + b;

    // Output the ellipse equation in standard form
    cout << "\nEllipse Equation (Standard Form):" << endl;
    cout << fixed << setprecision(2) << "(x - " << h << ")^2 / " << numX << " + (y - " << k << ")^2 / " << numY << " = 1\n";

    // Output ellipse properties in a table
    cout << "\nEllipse Properties:" << endl;
    cout << left << setw(20) << "Center (h, k):" << "(" << h << ", " << k << ")" << endl;
    cout << left << setw(20) << "Numerator for (x - h)^2:" << numX << endl;
    cout << left << setw(20) << "Numerator for (y - k)^2:" << numY << endl;
    cout << left << setw(20) << "Semi-major axis 'a':" << a << endl;
    cout << left << setw(20) << "Semi-minor axis 'b':" << b << endl;
    cout << left << setw(20) << "Value of 'c':" << c << endl;
    cout << left << setw(20) << "Eccentricity 'e':" << e << endl;
    cout << left << setw(20) << "Domain:" << "x ≤ " << domain << endl;
    cout << left << setw(20) << "Range:" << "y ≤ " << range << endl;
    cout << left << setw(20) << "Vertices:" << "(" << vertex1_x << ", " << vertex1_y << "), (" << vertex2_x << ", " << vertex2_y << ")" << endl;
    cout << left << setw(20) << "Foci:" << "(" << focus1_x << ", " << focus1_y << "), (" << focus2_x << ", " << focus2_y << ")" << endl;
    cout << left << setw(20) << "Endpoints:" << "(" << endpoint1_x << ", " << endpoint1_y << "), (" << endpoint2_x << ", " << endpoint2_y << ")" << endl;

    return 0;
}