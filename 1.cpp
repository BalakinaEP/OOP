
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
    double getRe()const;
    double getIm()const;
    
    friend Complex operator*(const double coef,const Complex n);
    friend std::ostream& operator<<(std::ostream& os,const Complex n);
};

int main()
{
    Complex a (3,-1);
    Complex b (-3,-11);
    Complex c = a+b;
    
    std::cout<<c<<std::endl;
    c = a-b;
   std::cout<<c<<std::endl;
    c= 3*a;
    std::cout<<c<<std::endl;
    return 0;
}

Complex::Complex(const double re, const double im):re(re), im(im)
{
    
}

std::ostream& operator<<(std::ostream& os,const Complex n)
{
    os<<n.re;
    if (n.im>0)
    {
        os<<"+";
    }
    os<<n.im<<"i\n";
    return os;
}

Complex Complex::operator+(const Complex num2) const
{
    double re = this->re + num2.getRe();
    double im = this->im + num2.getIm();
    return Complex(re,im);
}

Complex Complex::operator-(const Complex num2) const
{
    double re = this->re - num2.getRe();
    double im = this->im - num2.getIm();
    return Complex(re,im);
}

Complex Complex::operator*(const double coef) const
{
    double re = this->re*coef;
    double im = this->im*coef;
    return Complex(re,im);
}

double Complex::getRe()const
{
    return re;
}

double Complex::getIm()const
{
    return im;
}

Complex operator*(const double coef,const Complex n)
{
    return n*coef;
}
