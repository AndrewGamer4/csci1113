#include <iostream>
#include <iomanip>

#include "Complex.hpp"

using namespace std;

Complex::Complex()
    : real(0)
    , imag(0)
{
    
}


void Complex::input(istream& in)
{
    in >> real;
    in >> imag;
}

void Complex::output(ostream& out)
{
    out << fixed << setprecision(1) << real << " + " << fixed << setprecision(1) << imag << "i";
}

double Complex::getReal()
{
    return real;
}

double Complex::getImag()
{
    return imag;
}

void Complex::setReal(double r)
{
    real = r;
}

void Complex::setImag(double i)
{
    imag = i;
}









