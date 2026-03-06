#pragma once
#include <iostream>

class Complex
{
private:
    double re;
    double im;
public:
    Complex(const double re = 0, const double im = 0);

    Complex operator+(const Complex num2) const;
    Complex operator-(const Complex num2) const;
    Complex operator*(const double coef) const;
    Complex operator*(const Complex num2) const;
    Complex operator/(const double coef) const;
    Complex operator/(const Complex num2) const;
    double getRe()const;
    double getIm()const;

    friend Complex operator*(const double coef, const Complex n);
    friend std::ostream& operator<<(std::ostream& os, const Complex n);
};
