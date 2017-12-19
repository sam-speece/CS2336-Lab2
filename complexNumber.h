#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

class complexNumber
{
    public:
        //constructors
        complexNumber();
        complexNumber(float);
        complexNumber(float, float);
        complexNumber(complexNumber&);

        //accessors and mutators
        float getReal() {return real;};
        void setReal(float r) {real = r;};
        float getImaginary() {return imaginary;};
        void setImaginary(float i) {imaginary = i;};
        bool getValid() {return valid;};
        void setValid(bool v) {valid = v;};

        //overloaded operators
        complexNumber operator+(complexNumber&) const;
        complexNumber operator-(complexNumber&) const;
        complexNumber operator*(complexNumber&) const;
        complexNumber operator/(complexNumber&) const;
        bool operator>(complexNumber&) const;
        bool operator<(complexNumber&) const;
        bool operator==(complexNumber&) const;
        bool operator!=(complexNumber&) const;

        friend istream& operator>>(istream&, complexNumber&);
        friend ostream& operator<<(ostream&, complexNumber&);

    protected:

    private:
        float real;
        float imaginary;
        bool valid;
};

#endif // COMPLEXNUMBER_H
