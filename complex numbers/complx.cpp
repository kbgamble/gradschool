/* cs519 hw3 Kyle Gamble 2/14/2013
 * programming project 3 page 364
 * This program will construct complex numbers and perform arithmetic
 * operations using overloaded operators. Complex numbers will be displayed
 * as (a,b) where a is the real part and b is the imaginary part.
 */
// This is the implementation file complx.cpp
#include <iostream>
#include <cstdlib>
#include "complx.h"
using namespace std;

// initialize default constructor, sets object to 0
complx::complx():real(0), imaginary(0)
{}

// initialize constructor to any two doubles
complx::complx(double real, double imaginary):real(real), imaginary(imaginary)
{}

// initialize real number and set imaginary to zero
complx::complx(double realPart):real(realPart), imaginary(0)
{}

// overloaded + operator
const complx operator +(const complx& number1, const complx& number2)
{
   int realSum = number1.real + number2.real;
   int imaginarySum = number1.imaginary + number2.imaginary;

return complx(realSum, imaginarySum);
}

// overloaded - operator
const complx operator -(const complx& number1, const complx& number2)
{
   int realDifference = number1.real - number2.real;
   int imaginaryDifference = number1.imaginary - number2.imaginary;

return complx(realDifference, imaginaryDifference);
}

// overloaded - operator to negate
const complx operator -(const complx& number)
{
   return complx(-number.real, -number.imaginary);
}

// overloaded == operator
bool operator ==(const complx& number1, const complx& number2)
{
   return ((number1.real == number2.real) 
   && (number1.imaginary == number2.imaginary));
}

// overloaded * operator
const complx operator *(const complx& number1, const complx& number2)
{
   int realProduct = ((number1.real * number2.real) 
                - (number1.imaginary * number2.imaginary));
   int imaginaryProduct = ((number1.real * number2.imaginary)
                + (number1.imaginary * number2.real)); 

return complx(realProduct, imaginaryProduct);
}

// overloaded output operator function defintion
ostream& operator <<(ostream& outputStream, const complx& number)
{
   outputStream << "(" << number.real << "," << number.imaginary << ")";

return outputStream;
}

// overloaded input operator function definition
istream& operator >>(istream& inputStream, complx& number)
{
   char comma; // capture comma between real and imaginary numbers
 
   inputStream >> number.real; // read in real number
   inputStream >> comma; // read in comma
   inputStream >> number.imaginary; // read in imaginary number
   
return inputStream;
}

