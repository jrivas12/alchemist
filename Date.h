#include <string>

#ifndef DATE_H
#define DATE_H

class Date { // Change "Data" to "Date"
public:
    static const unsigned int monthsPerYear{12};
    explicit Date(unsigned int mn = 1, unsigned int dy = 1, unsigned int yr = 1990);
    std::string toString() const;
    ~Date();

private:
    unsigned int month;
    unsigned int day;
    unsigned int year;

    unsigned int checkDay(int) const;
};
#endif
