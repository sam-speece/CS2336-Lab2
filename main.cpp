/*Project_2 - Whovian Numbers
Sam Speece - sds160130
CS 2336.004
September 21, 2016*/

#include <fstream>
#include <string>
#include "complexNumber.h"

using namespace std;

int main()
{
    //declare variables
    char inputOperator;
    bool compare;
    complexNumber number1, number2, number3;
    ifstream inData("complex.txt");
    ofstream outData("results.txt");

    //check if the file exists
    if(inData.is_open())
    {
        //parse while file is not at the end
        while(!inData.eof())
        {
            inData >> number1;
            if(number1.getValid())
                inData >> inputOperator >> number2;

            //check if the numbers are valid then determine which operator to use
            if(number1.getValid() && number2.getValid() && inputOperator == '+')
            {
                number3 = number1 + number2;
                outData << number1 << " " << inputOperator << " " << number2 << "   " << number3 << endl;
            }else if(number1.getValid() && number2.getValid() && inputOperator == '-')
            {
                number3 = number1 - number2;
                outData << number1 << " " << inputOperator << " " << number2 << "   " << number3 << endl;
            }else if(number1.getValid() && number2.getValid() && inputOperator == '*')
            {
                number3 = number1 * number2;
                outData << number1 << " " << inputOperator << " " << number2 << "   " << number3 << endl;
            }else if(number1.getValid() && number2.getValid() && inputOperator == '/')
            {
                number3 = number1 / number2;
                outData << number1 << " " << inputOperator << " " << number2 << "   " << number3 << endl;
            }else if(number1.getValid() && number2.getValid() && inputOperator == '<')
            {
                compare = number1 < number2;
                outData << number1 << " " << inputOperator << " " << number2 << "   ";
                if(compare)
                    outData << "true" << endl;
                else
                    outData << "false" << endl;
            }else if(number1.getValid() && number2.getValid() && inputOperator == '>')
            {
                compare = number1 > number2;
                outData << number1 << " " << inputOperator << " " << number2 << "   ";
                if(compare)
                    outData << "true" << endl;
                else
                    outData << "false" << endl;
            }else if(number1.getValid() && number2.getValid() && inputOperator == '/=')
            {
                compare = number1 != number2;
                outData << number1 << " " << inputOperator << " " << number2 << "   ";
                if(compare)
                    outData << "true" << endl;
                else
                    outData << "false" << endl;
            }else if(number1.getValid() && number2.getValid() && inputOperator == '=')
            {
                compare = number1 == number2;
                outData << number1 << " " << inputOperator << " " << number2 << "   ";
                if(compare)
                    outData << "true" << endl;
                else
                    outData << "false" << endl;
            }
            //resets all the variables and objects
            number1.setReal(0);
            number1.setImaginary(0);
            number1.setValid(true);
            number2.setReal(0);
            number2.setImaginary(0);
            number2.setValid(true);
            number3.setReal(0);
            number3.setImaginary(0);
            inputOperator = ' ';
        }

    }else
        cout << "file not found";

    inData.close();
    outData.close();

    return 0;
}
