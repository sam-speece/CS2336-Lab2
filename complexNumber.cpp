#include "complexNumber.h"

using namespace std;

//default constructor that initializes real and imaginary to their defaults
complexNumber::complexNumber()
{
    real = 0;
    imaginary = 0;
    valid = true;
}

//overloaded constructor that takes in a real float number only
complexNumber::complexNumber(float r)
{
    real = r;
    imaginary = 0;
}

//overloaded constructor that takes in both the real and imaginary float numbers
complexNumber::complexNumber(float r, float i)
{
    real = r;
    imaginary = i;
}

//copy constructor that copies the elements from the complexNumber object to this one
complexNumber::complexNumber(complexNumber& num)
{
    real = num.getReal();
    imaginary = num.getImaginary();
}

//adds two complex numbers together
complexNumber complexNumber::operator+(complexNumber& num) const
{
    complexNumber sumNumber;

    sumNumber.setReal(real + num.getReal());
    sumNumber.setImaginary(imaginary + num.getImaginary());

    return sumNumber;
}

//subtracts two complex numbers from each other
complexNumber complexNumber::operator-(complexNumber& num) const
{
    complexNumber subNumber;

    subNumber.setReal(real - num.getReal());
    subNumber.setImaginary(imaginary - num.getImaginary());

    return subNumber;
}

//multiplies two complex numbers together
complexNumber complexNumber::operator*(complexNumber& num) const
{
    complexNumber productNumber, firstNumber, secondNumber;

    firstNumber.setReal(real * num.getReal());
    firstNumber.setImaginary(real * num.getImaginary());
    secondNumber.setImaginary(imaginary * num.getReal());
    secondNumber.setReal(imaginary * num.getImaginary() * -1);

    productNumber = firstNumber + secondNumber;
    return productNumber;
}

//divides two complex numbers together
complexNumber complexNumber::operator/(complexNumber& num) const
{
    complexNumber quotientNumber, numeratorFirstNumber, numeratorSecondNumber;
    float denomNumber;

    //first multiply by the conjugate by flipping the imaginary number and multiplying numerator and denominator
    numeratorFirstNumber.setReal(real * num.getReal());
    numeratorFirstNumber.setImaginary(real * num.getImaginary() * -1);
    numeratorSecondNumber.setReal(imaginary * num.getImaginary());
    numeratorSecondNumber.setImaginary(imaginary * num.getReal());

    denomNumber = (real * real) - (imaginary * imaginary);

    //now add the numerator to simplify
    quotientNumber = numeratorFirstNumber + numeratorSecondNumber;
    quotientNumber.setReal(quotientNumber.getReal() / denomNumber);
    quotientNumber.setImaginary(quotientNumber.getImaginary() / denomNumber);

    return quotientNumber;
}

//compares if the first number is bigger than the second number
bool complexNumber::operator>(complexNumber& num) const
{
    if((real + imaginary) > (num.getReal() + num.getImaginary()))
       return true;
    return false;
}

//compares if the first number is less than the second number
bool complexNumber::operator<(complexNumber& num) const
{
    if((real + imaginary) < (num.getReal() + num.getImaginary()))
        return true;
    return false;
}

//compares if the numbers are equal
bool complexNumber::operator==(complexNumber& num) const
{
    if(real == num.getReal() && imaginary == num.getImaginary())
        return true;
    return false;
}

//compares if the numbers are not equal
bool complexNumber::operator!=(complexNumber& num) const
{
    if(real != num.getReal() || imaginary != num.getImaginary())
        return true;
    return false;
}

//determine if the number is a valid number then put the real and imaginary parts into the correct places
istream& operator>>(istream& input, complexNumber& num)
{
    bool check = true;
    string number, number1, number2;
    input >> number;

    //validates input
    for(int i = 0; i < number.length(); i++)
    {
        if(number[i] != 'i' && number[i] != '0' && number[i] != '1' && number[i] != '2' && number[i] != '3' && number[i] != '4'
            && number[i] != '5' && number[i] != '6' && number[i] != '7' && number[i] != '8' && number[i] != '9' && number[i] != '+'
                && number[i] != '-')
        {
            num.setValid(false);
        }
    }

    //separates the complex numbers when it encounters a + or -
    for(int i = 0; i < number.length(); i++)
    {
        if(number[i] == '+')
        {
            number1 = number.substr(0, i);
            number2 = number.substr(i + 1, number.length() - 1);
            check = false;
        }else if(number[i] == '-')
        {
            number1 = number.substr(0, i);
            number2 = "-" + number.substr(i + 1, number.length() - 1);
            check = false;
        }
    }

    //if there is only a real or only an imaginary number set the other to default
    if(check && number[number.length() - 1] != 'i')
    {
        number1 = number;
        number2 = "0";
    }else if(check && number[number.length() - 1] == 'i')
    {
        number2 = number.substr(0, number.length() - 1);
        number1 = "0";
    }

    float real = atof(number1.c_str());
    float imaginary = atof(number2.c_str());
    num.setReal(real);
    num.setImaginary(imaginary);

    return input;
}

//output the real and imaginary parts of the complexNumber
ostream& operator<<(ostream& output, complexNumber& num)
{
    output << fixed << showpoint << setprecision(2) << num.getReal();
    if(num.getImaginary() < 0)
    {
        output << num.getImaginary() << "i";
        return output;
    }else if(num.getImaginary() > 0)
    {
        output << "+" << num.getImaginary() << "i";
        return output;
    }

    return output;
}
