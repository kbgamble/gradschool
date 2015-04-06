/* cs519 hw3 Kyle Gamble 2/14/2013
 * programming project 3 page 364
 * This program will construct complex numbers and perform arithmetic
 * operations using overloaded operators. Complex numbers will be displayed
 * as (a,b) where a is the real part and b is the imaginary part.
 */
// This is the header file complx.h
#ifndef COMPLX_H
#define COMPLX_H

#include <iostream>
using std::istream;
using std::ostream;

class complx
{
   public:
      complx(); // default constructor    
      complx(double real, double imaginary);
      complx(double realPart);
      // friendly overloaded operator functions
      friend const complx operator +(const complx& number1, 
                                     const complx& number2);
      friend const complx operator -(const complx& number1,
                                     const complx& number2);
      friend const complx operator -(const complx& number); // negate
      friend bool operator ==(const complx& number1,
                              const complx& number2);
      friend const complx operator *(const complx& number1,
                                     const complx& number2);
      friend ostream& operator <<(ostream& outputStream,
                                  const complx& number);
      friend istream& operator >>(istream& inputStream,
                                  complx& number); 
   private:
      double real;
      double imaginary;
};

#endif // COMPLX_H
