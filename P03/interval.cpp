/*
Consider types time_of_day and interval to represent the time of day with a precision of minutes, and time intervals defined by start and end times, as follows:

struct time_of_day {
  unsigned char h; // Hours [0,23]
  unsigned char m; // Minutes [0,59]
};
struct interval {
  time_of_day start; // Start time
  time_of_day end;   // End time
};

Consider that an interval value il includes all times that are equal to or later than il.start and (strictly) earlier than il.end. For instance, if il.start = {12, 30} (representing time 12:30) and il.end = {14, 30} (14:30), then {12, 30} and {12, 31} are part of the interval but {14, 30} and {14, 31} are not.

Write a C++ function

interval intersection(interval a, interval b)

to compute the intersection of intervals. When the intersection is empty, the function should return the interval with the start time and the end time both equal to { 0, 0 }.

In your code you should include header file interval.h (you need to download the file) that contains the declaration of the above function and the time_of_day and interval types, along with support for printing interval values using cout (used in tests).

Hint: it may be convenient to define an auxiliary function to check if a < b for times a and b represented by time_of_day. 
*/

#include <iostream>
#include "interval.h"

using namespace std;

bool aux_comp(time_of_day a, time_of_day b) {
    if(a.h < b.h) {return true ;}
    else if(a.h == b.h && a.m < b.m ) {return true;}
    else {return false;} 

}

interval intersection(interval a, interval b) {

    interval il;
    



    if (aux_comp(b.start, a.end) && aux_comp(a.start,b.end)) {
        
        if (aux_comp(a.start,b.start)) {
            if (aux_comp(a.end,b.end)) {
        il.start = b.start;
        il.end = a.end;
        }
        else {
        il.start = b.start;
        il.end = b.end;
        }
        }
        else if (aux_comp(b.start,a.start)) {
            if (aux_comp(b.end,a.end)) {
                il.start = a.start;
                il.end = b.end;
            }
            else {
                il.start = a.start;
                il.end = a.end;

            }
        }
    }
    else {
        il.start = {0,0};
        il.end = {0,0};
    }

    return il;

}

/*
SOLUCAO ALTERNATIVA MAIS PRATICA

bool earlier_than(time_of_day a, time_of_day b) {
  return a.h < b.h || (a.h == b.h && a.m < b.m);
}

interval intersection(interval a, interval b) {
  interval r;
  if (earlier_than(b.start, a.end) &&
      earlier_than(a.start, b.end)) {
    r.start = earlier_than(a.start, b.start) ? b.start : a.start;
    r.end   = earlier_than(a.end, b.end) ? a.end : b.end;
  } else {
    r = { { 0, 0}, { 0, 0 } };
  }
  return r;
}

*/

int main() {
  // public tests (1 point each)
  cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 17, 30 }, { 18, 30 } } ) << '\n'; // => [00:00,00:00[
  cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 14, 30 }, { 18, 30 } } ) << '\n'; // => [00:00,00:00[
  cout << intersection( { { 12, 30 }, { 14, 31 } },
                        { { 14, 30 }, { 18, 30 } } ) << '\n'; // => [14:30,14:31[
  cout << intersection( { { 14, 30 }, { 15, 59 } },
                        { { 11, 30 }, { 14, 31 } } ) << '\n'; // => [14:30,14:31[
  cout << intersection( { {  4, 30 }, {  7, 59 } },
                        { {  4,  0 }, {  7, 29 } } ) << '\n'; // => [04:30,07:29[
  cout << intersection( { { 23,  0 }, { 23, 58 } },
                        { { 22, 45 }, { 23, 59 } } ) << '\n'; // => [23:00,23:58[

  // private tests (1000 points each)
  cout << '\n';
  cout << intersection( { { 23, 57 }, { 23, 59 } },
                        { { 23, 58 }, { 23, 59 } } ) << '\n'; // => [23:58,23:59[
  cout << intersection( { { 23, 58 }, { 23, 59 } },
                        { { 23, 56 }, { 23, 58 } } ) << '\n'; // => [00:00,00:00[
  cout << intersection( { { 19,  0 }, { 19, 29 } },
                        { {  0, 30 }, { 18, 30 } } ) << '\n'; // => [00:00,00:00[
  cout << intersection( { { 17, 30 }, { 23, 59 } },
                        { { 17, 31 }, { 23, 58 } } ) << '\n'; // => [17:31,23:58[
  cout << intersection( { {  4, 30 }, {  4, 59 } },
                        { {  4,  0 }, {  7, 29 } } ) << '\n'; // => [04:30,04:59[
  cout << intersection( { { 23,  0 }, { 23, 58 } },
                        { { 23, 45 }, { 23, 59 } } ) << '\n'; // => [23:45,23:58[
    return 0;
}