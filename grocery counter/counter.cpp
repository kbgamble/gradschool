/* cs519 hw2 Kyle Gamble 2/1/2013
 * programming project 3 page 316
 * This program will simulate the behavior of a grocery store counter.
 * This counter is used to keep track of potential money spent while in
 * the store.
 */
// This is the implementation file counter.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "counter.h"
using namespace std;

// initialize constructor with valid maximum count from input
Counter::Counter(int maxCount)
      : maximumCount(maxCount), penny(0), dime(0), dollar(0), tenDollar(0)
{
   // if counter overflows, exit program
   if (overflow())
   {
      cout << "The counter has overflowed!\n"
           << "Run the program again, using a number less than 10000"
           << "\n\n";
           exit(1);
   }
}
// initialize default constructor with allowed maximum
Counter::Counter() : maximumCount(9999), penny(0), dime(0), dollar(0),
			tenDollar(0)
{}

// detect if the counter has gone over it's set maximum
bool Counter::overflow()
{
   // get current count
   int currentCount = penny + (dime * 10) + (dollar * 100) + (tenDollar * 1000);

   // if the current count is greater than the max, it overflowed
   if (currentCount > maximumCount)
   {
      cout << "Counter has overflowed!\n";
      return true;
   }
   else if (maximumCount > 9999)
   {
      cout << "You entered a maximum greater than 9999!\n";
      return true;
   }
// else return false
return false;
}

// resets the counter's count back to zero
void Counter::reset()
{
   penny = 0;
   dime = 0;
   dollar = 0;
   tenDollar = 0;
}

// provide the user with directions and ask the user to input amount to 
// increment by
void Counter::input()
{
   string input; // original input

   // directions
   cout << "Below are the keys to use when entering the cost of items "
        << "to the counter:\n"
        << "Press a for cents, followed by a digit 1 to 9\n"
        << "Press s for dimes, followed by a digit 1 to 9\n"
        << "Press d for dollars, followed by a digit 1 to 9\n"
        << "Press f for tens of dollars, followed by a digit 1 to 9\n"
        << "Press the Return key after each entry (one of asdf followed "
        << "by 1 to 9)\n"
        << "To see if your counter has overflowed, press o0, followed by "
        << "the Return key.\n"
        << "Reset the counter by pressing r0, followed by the Return key."
        << "\n\n"
        << "Counter balance: $" << tenDollar << dollar << "."
        << dime << penny
        << "\n\n"
        << "Enter item cost: ";

   // record input
   cin >> key;
   cin >> digit;
	
   cout << "\n";
}

// function decides which increment function to call
void Counter::increment()
{
   switch (key)
   {
      case 'a':
              for (int i=0; i<digit; i++) incr1(); 
              break;
      case 's':
              for (int i=0; i<digit; i++) incr10();
	      break;
      case 'd':
              for (int i=0; i<digit; i++) incr100();
	      break;
      case 'f':
              for (int i=0; i<digit; i++) incr1000();
	      break;
      case 'o':
              overflow();
	      cout << "No overflow\n\n";
	      break;
      case 'r':
              reset(); break;
      default:
              cout << "You have entered an invalid key/digit pair.\n";
	      exit(1);
   }
}

// function increments one's place
void Counter::incr1()
{
   penny++;
   if (penny==10) 
   {
      penny = 0;
      incr10();
   }
}

// function increments the ten's place
void Counter::incr10()
{
  dime++;
  if (dime==10)
  { 
     dime = 0;
     incr100();
  }
}

// function increments the hundred's place
void Counter::incr100()
{
   dollar++;
   if (dollar==10)
   {
      dollar = 0;
      incr1000();
   }
}

// function increments the thousand's place
void Counter::incr1000()
{
   tenDollar++;
   if (overflow())
   {
      exit(1);
   }
}
