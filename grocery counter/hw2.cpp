/* cs519 hw2 Kyle Gamble 2/1/2013
 * programming project 3 page 316
 * This program will simulate the behavior of a grocery store counter.
 * This counter is used to keep track of potential money spent while in
 * the store.
 */
// This is the application file hw2.cpp
#include <iostream>
#include "counter.h"
using namespace std;

int main()
{
   // request count as user input
   int count;
   cout << "Enter a maximum whole number less than 10000 for your "
        << "counter: ";
   cin >> count;
   cout << "\n";
   // instantiate grocery counter using user input 
   Counter groceryCounter(count);
	
   // keep requesting input while counter is less than it's max
   while (groceryCounter.overflow() == false)
   {
      // get input from user
      groceryCounter.input();

      // increment counter
      groceryCounter.increment();
   }

return 0;
}
