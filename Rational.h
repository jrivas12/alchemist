// Rational.h
#ifndef _RATIONAL_H_
#define _RATIONAL_H_

class Rational {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b);

public:
    Rational(int num = 0, int denom = 1); 
    Rational add(const Rational& other) const;
    Rational subtract(const Rational& other) const;
    Rational multiply(const Rational& other) const;
    Rational divide(const Rational& other) const;
    std::string toRationalString() const;
    void display() const;
    double toDouble() const;
};

#endif