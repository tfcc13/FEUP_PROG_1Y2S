/*Consider a type for the time of day expressed in hours and minutes defined as:

struct time_of_day {
  unsigned char h; // Hours [0,23]
  unsigned char m; // Minutes [0,59]
};

Write a C++ function

time_of_day tick(time_of_day t)

such that the result of tick(t) represents the elapse of one minute over a given t.

In your code you should include header file time_of_day.h (you need to download the file) that contains the declaration of the above function and the time_of_day type, along with support for printing time_of_day values using cout (used in tests). */

#include <iostream>
#include "time_of_day.h"

using namespace std;


time_of_day tick(time_of_day t) {
    t.m = t.m+1;

    if (t.m > 59) {
        t.h += 1 ;
        if (t.h>23) {
            t.h = 0;
        }
        t.m = 0;
    }

   return t;

}

int main() {
      // public tests (1 point each) 
  cout << tick({ 0, 0 }) << '\n';   // => 00:01
  cout << tick({ 12, 30 }) << '\n'; // => 12:31
  cout << tick({ 12, 59 }) << '\n'; // => 13:00
  cout << tick({ 23, 59 }) << '\n'; // => 00:00
  cout << tick(tick(tick({ 23, 59 }))) << '\n'; // => 00:02

  // private tests (1000 points each) 
  cout << '\n';
  cout << tick({ 22, 59 }) << '\n'; // => 23:00
  cout << tick({ 17, 21 }) << '\n'; // => 17:22
  cout << tick({ 12, 29 }) << '\n'; // => 12:30
  cout << tick({ 23, 33 }) << '\n'; // => 23:34
  cout << tick(tick(tick({ 23, 58 }))) << '\n'; // => 00:01


    return 0;
}