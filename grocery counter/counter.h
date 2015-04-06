/* cs519 hw2 Kyle Gamble 2/1/2013
 * programming project 3 page 316
 * This program will simulate the behavior of a grocery store counter.
 * This counter is used to keep track of potential money spent while in
 * the store.
 */
// This is the header file counter.h
#ifndef COUNTER_H
#define COUNTER_H

class Counter
{
   public:
      Counter(int maxCount);
      Counter(); // default constructor
      // function resets the counter to 0
      void reset();
      // function selects which incr function to use
      void increment();
      // function detects overflow
      bool overflow();
      // function increments the counter by 1
      void incr1();
      // function increments the counter by 10
      void incr10();
      // function increments the counter by 100
      void incr100();
      // function increments the counter by 1000
      void incr1000();
      // function to request incremental input	
      void input();
   private:
      //int currentCount; // value of counter
      int maximumCount; // max value counter can store
      int penny; // increment by penies
      int dime; //increment by dimes
      int dollar; // increment by dollars
      int tenDollar; // increment by tens of dollars
      int digit; // current key & digit pressed by user
      char key;	
};

#endif // COUNTER_H
