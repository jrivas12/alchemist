//Rational.cpp
#include <iostream>
#include <string>
#include "Rational.h"
using namespace std;

int Rational::gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

Rational::Rational(int num, int denom) {
    int common = gcd(num, denom);
    numerator = num / common;
    denominator = denom / common;
}

Rational Rational::add(const Rational& other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Rational(num, denom);
}

Rational Rational::subtract(const Rational& other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Rational(num, denom);
}

Rational Rational::multiply(const Rational& other) const {
    int num = numerator * other.numerator;
    int denom = denominator * other.denominator;
    return Rational(num, denom);
}

Rational Rational::divide(const Rational& other) const {
    int num = numerator * other.denominator;
    int denom = denominator * other.numerator;
    return Rational(num, denom);
}

std::string Rational::toRationalString() const {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
}

void Rational::display() const {
    std::cout << toRationalString();
}

double Rational::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}
