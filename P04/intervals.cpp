/*

Consider types time_of_day and interval to represent the time of day with a precision of minutes, and time intervals defined by start and end times, as follows:

struct time_of_day {
  unsigned char h; // hours
  unsigned char m; // minutes
};
struct interval {
  time_of_day start; // start time
  time_of_day end;   // end time
};

Consider that an interval value il includes all times that are equal to or later than il.start and (strictly) earlier than il.end. For instance, if il.start = {12, 30} (representing time 12:30) and il.end = {14, 30} (14:30), then {12, 30} and {12, 31} are part of the interval but {14, 30} and {14, 31} are not.

Write a C++ function

int search_intervals(time_of_day t, const interval a[], int n, interval& u)

that searches for all n intervals stored in array a, and:

    If there are no intervals that contain t, then the function assigns u with { t, t } and returns 0.
    If there are intervals that contain t, it assigns u to the union of all these intervals and returns the total duration of u in minutes.

In your code you should include header file interval.h (you need to download the file) that contains the time_of_day and interval types, along with support for printing interval values using cout (used in tests). 

*/


#include <iostream>
#include "interval.h"
using namespace std;
bool earlier_then(time_of_day a, time_of_day b) {
        return (a.h  < b.h || a.h == b.h && a.m <= b.m );
    }

int search_intervals(time_of_day t, const interval a[], int n, interval& u) {

    
    int count = 0;
    for (int i =0; i < n; i++) {
        if (earlier_then(a[i].start ,t)&&  !earlier_then(a[i].end,t)) {
            count++;
            if (count == 1) {
            u = a[i];
            }
            else {
                if (earlier_then(a[i].start,u.start)) {
                    u.start = a[i].start;
                }
                if (earlier_then(t,u.end) && (earlier_then(u.end, a[i].end))) {
                    u.end = a[i].end;
                }    
        }
        }

    }

    if (count == 0) {
        u = {t,t};
    }
    return (u.end.h - u.start.h)*60 + u.end.m-u.start.m;

    




}

int main() {
    cout << "\n// public tests (1 point each)\n";
  {
    const int n = 1;
    const time_of_day t = { 13, 00 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  } // --> 120 [12:30,14:30[
  {
    const int n = 2;
    const time_of_day t = { 14, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                    { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  } // -> 60 [14:30,15:30[
  {
    const int n = 2;
    const time_of_day t = { 12, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                    { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  } // --> 120 [12:30,14:30[
  {
    const int n = 2;
    const time_of_day t = { 15, 30 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                    { { 14, 30 }, { 15, 30 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  }  // -> 0 [15:30,15:30[
  {
    const int n = 5;
    const time_of_day t = { 15, 15 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                    { { 14, 30 }, { 15, 30 } }, 
                    { { 15, 10 }, { 16, 10 } }, 
                    { {  9, 30 }, { 15, 15 } }, 
                    { {  9, 45 }, { 15, 16 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  }  // --> 385 [9:45,16:10[

  cout << "\n// private tests (1000 points each)\n";
  {
    const int n = 2;
    const time_of_day t = { 16, 20 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                    { { 15, 15 }, { 16, 21 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  } // -> 66 [15:15,16:21[
  {
    const int n = 2;
    const time_of_day t = { 16, 20 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                    { { 15, 15 }, { 16, 20 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  } // -> 0 [16:20,16:20[
  {
    const int n = 5;
    const time_of_day t = { 12, 12 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                    { { 14, 30 }, { 15, 30 } }, 
                    { { 15, 10 }, { 16, 10 } }, 
                    { {  9, 25 }, { 15, 15 } }, 
                    { {  9, 45 }, { 15, 16 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  }  // --> 351 [9:25,15:16[
  {
    const int n = 5;
    const time_of_day t = { 8, 27 };
    const interval a[n] { { { 3, 29 }, { 9, 53 } }, 
                    { { 10, 00 }, { 13, 30 } }, 
                    { { 1, 24 }, { 6, 13 } }, 
                    { { 5, 25 }, { 7, 05 } }, 
                    { { 7, 30 }, { 11, 55 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  }  // --> 506 [3:29,11:55[
  {
    const int n = 5;
    const time_of_day t = { 16, 27 };
    const interval a[n] { { { 12, 29 }, { 13, 53 } }, 
                    { { 13, 54 }, { 14, 30 } }, 
                    { { 15, 21 }, { 16, 27 } }, 
                    { { 16, 28 }, { 17, 15 } }, 
                    { { 11, 30 }, { 13, 55 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';
  }  // --> 0 [16:27,16:27[
}