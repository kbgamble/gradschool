/* cs519 hw3 Kyle Gamble 2/14/2013
 * programming project 3 page 364
 * This program will construct complex numbers and perform arithmetic
 * operations using overloaded operators. Complex numbers will be displayed
 * as (a,b) where a is the real part and b is the imaginary part.
 */
// This is the driver file hw3.cpp
#include <iostream>
#include <cstdlib>
#include "complx.h"
using namespace std;

int main()
{
   // initialize complx objects
   complx myNumber(5,9), yourNumber;
   cout << "Enter a complex number in the format a,b: ";
   cin >> yourNumber;
   cout << "Your complex number is: " << yourNumber << endl;
   cout << "My complex number is: " << myNumber << endl;

   // use the overloaded == operator to check if our amounts are equal
   if (myNumber == yourNumber)
      cout << "Your number is equal to my number.\n";
   else
      cout << "Your number is not equal to my number.\n";

   // add our numbers together and display to the screen
   complx ourNumber = myNumber + yourNumber;
   cout << myNumber << " + " << yourNumber << " equals " << ourNumber << endl;

   // subtract mynumber from ourNumber
   cout << ourNumber << " - " << myNumber << " equals ";
   ourNumber = ourNumber - myNumber;
   cout << ourNumber << endl;

   // negate yourNumber
   cout << "Your number negated: " << -yourNumber << endl;

   // find the product of our numbers
   complx product = myNumber * yourNumber;
   cout << "The product of " << myNumber << " and " << yourNumber
        << " is " << product << endl;

return 0;
}
