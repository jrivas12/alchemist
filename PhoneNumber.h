// PhoneNumber.h

#ifndef PhoneNumber_H
#define PhoneNumber_H

#include <iostream>
#include <string> // Add this line

class PhoneNumber {
    friend std::ostream& operator<<(std::ostream&, const PhoneNumber&);
    friend std::istream& operator>>(std::istream&, PhoneNumber&); // Change ifstream to istream
private:
    std::string areaCode;
    std::string exchange;
    std::string line; // Change Time to line
};

#endif
