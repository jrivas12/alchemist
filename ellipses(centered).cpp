#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Initialize variables
    double a, b, c;
    
    // Get user input for semi-major axis 'a' and semi-minor axis 'b'
    cout << "Enter the value of semi-major axis 'a': ";
    cin >> a;
    cout << "Enter the value of semi-minor axis 'b': ";
    cin >> b;
    
    // Calculate semi-focal distance 'c' using the relationship c^2 = a^2 - b^2
    c = sqrt(a * a - b * b);
    
    // Calculate domain, range, vertices, and endpoints
    double domain = a; // Domain is along the x-axis
    double range = b; // Range is along the y-axis
    
    // Vertices are (a, 0) and (-a, 0)
    double vertex1_x = a;
    double vertex1_y = 0;
    double vertex2_x = -a;
    double vertex2_y = 0;
    
    // Endpoints of the major axis are (a, 0) and (-a, 0)
    double major_endpoint1_x = a;
    double major_endpoint1_y = 0;
    double major_endpoint2_x = -a;
    double major_endpoint2_y = 0;
    
    // Endpoints of the minor axis are (0, b) and (0, -b)
    double minor_endpoint1_x = 0;
    double minor_endpoint1_y = b;
    double minor_endpoint2_x = 0;
    double minor_endpoint2_y = -b;
    
    // Foci are located at (c, 0) and (-c, 0)
    double focus1_x = c;
    double focus1_y = 0;
    double focus2_x = -c;
    double focus2_y = 0;
    
    // Output the ellipse equation in a table
    cout << "\nEllipse Properties:" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Semi-Major Axis (a): " << a << endl;
    cout << "Semi-Minor Axis (b): " << b << endl;
    cout << "Semi-Focal Distance (c): " << c << endl;
    cout << "Domain: [-" << domain << ", " << domain << "]" << endl;
    cout << "Range: [-" << range << ", " << range << "]" << endl;
    cout << "Vertices:" << endl;
    cout << "  Vertex 1: (" << vertex1_x << ", " << vertex1_y << ")" << endl;
    cout << "  Vertex 2: (" << vertex2_x << ", " << vertex2_y << ")" << endl;
    cout << "Endpoints of Major Axis:" << endl;
    cout << "  Endpoint 1: (" << major_endpoint1_x << ", " << major_endpoint1_y << ")" << endl;
    cout << "  Endpoint 2: (" << major_endpoint2_x << ", " << major_endpoint2_y << ")" << endl;
    cout << "Endpoints of Minor Axis:" << endl;
    cout << "  Endpoint 1: (" << minor_endpoint1_x << ", " << minor_endpoint1_y << ")" << endl;
    cout << "  Endpoint 2: (" << minor_endpoint2_x << ", " << minor_endpoint2_y << ")" << endl;
    cout << "Foci:" << endl;
    cout << "  Focus 1: (" << focus1_x << ", " << focus1_y << ")" << endl;
    cout << "  Focus 2: (" << focus2_x << ", " << focus2_y << ")" << endl;
    cout << "---------------------------------------------------------" << endl;
    
    return 0;
}