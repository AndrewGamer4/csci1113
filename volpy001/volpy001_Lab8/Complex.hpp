#ifndef COMPLEX
#define COMPLEX
#include <iostream>

class Complex
{
private:
    double real;
    double imag;
public:
    Complex();
    void input(std::istream&);
    void output(std::ostream&);
    double getReal();
    double getImag();
    void setReal(double);
    void setImag(double);
};








#endif COMPLEX