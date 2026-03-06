#include <cmath>
#include "Complex.h"

Complex::Complex(const double re, const double im) :re(re), im(im)
{

}

std::ostream& operator<<(std::ostream& os, const Complex n)
{
    os << n.re;
    if (n.im > 0)
    {
        os << "+";
    }
    os << n.im << "i\n";
    return os;
}

Complex Complex::operator+(const Complex num2) const
{
    double re = this->re + num2.getRe();
    double im = this->im + num2.getIm();
    return Complex(re, im);
}

Complex Complex::operator-(const Complex num2) const
{
    double re = this->re - num2.getRe();
    double im = this->im - num2.getIm();
    return Complex(re, im);
}

Complex Complex::operator*(const double coef) const
{
    double re = this->re * coef;
    double im = this->im * coef;
    return Complex(re, im);
}

Complex Complex::operator*(const Complex num2) const
{
    double re = this->re * num2.getRe() - this->im*num2.getIm();
    double im = this->im * num2.getRe() + this->re * num2.getIm();
    return Complex(re, im);
}

Complex Complex::operator/(const double coef) const
{
    double re = this->re / coef;
    double im = this->im / coef;
    return Complex(re, im);
}

Complex Complex::operator/(const Complex num2) const
{
    double re = (this->re * num2.getRe() + this->im * num2.getIm())
        /(pow(num2.getRe(), 2)+ pow(num2.getIm(),2));
    double im = (this->im * num2.getRe() - this->re * num2.getIm())
        /(pow(num2.getRe(), 2)+ pow(num2.getIm(),2));
    return Complex(re, im);
}

double Complex::getRe()const
{
    return re;
}

double Complex::getIm()const
{
    return im;
}

Complex operator*(const double coef, const Complex n)
{
    return n * coef;
}
