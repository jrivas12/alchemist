#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle {
public:
    Rectangle(double length,
        double width)
        : length(length),
        width(width) {}

    double get_length() const {
        return length;
    }

    double get_width() const {
        return width;
    }

    double get_perimeter() const {
        return ((length * 2) + (width * 2));
    }

    double get_area() const {
        return (length * width);
    }

    void resize(double factor) {
        length  *= factor;
        width *= factor;
    }

    friend ostream&
        operator <<(ostream& os,
        const Rectangle& rectangle) {
        os << "Rectangle [length="
           << rectangle.length << ",width="
           << rectangle.width << "]\n";
        return os;
    }

private:
    double width;
    double length;
};

int main() {

    Rectangle r1(20.52, 12.5);
    Rectangle r2(5.27, 2.4);
    Rectangle r3(38.7, 22.89);

    cout << setw(5) << r1;
    cout << setw(5) << r2;
    cout << setw(5) << r3;


    cout << "\nLength is: "  << fixed  << setprecision(2);
    cout << setw(18) << r1.get_length()<< endl;
    cout << "Width is: " << fixed  << setprecision(2)<< setw(19) << r1.get_width() << endl;
    cout << "Area is: "      << fixed  << setprecision(2) << setw(21) << r1.get_area()  << endl;
    cout << "Perimeter is: " << fixed  << setprecision(2) << setw(15) << r1.get_perimeter() << endl;

    return 0;
}
