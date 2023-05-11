/*

Write a C++ function void advance(int delta, int& d, int& m, int& y) to update a date, implicitly defined by d/m/y, by delta days.

You can assume that delta is greater or equal to 0 and that the values of d, m, and y define a valid date when the function is called. On exit, d, m, and y should represent an elapse of delta days over the original date.

Note that you should account for leap years: y is a leap year (“bissexto'') if it is divisible by 4, except when it is divisible by 100 but not 400 (e.g., 2004 and 2000 are leap years, but 2100 is not). 

*/

#include <iostream>

using namespace std;

    bool check_leap(int y) {
        if ((y % 4 == 0 && y%100 != 0 ) || y%400 == 0   ) {
            return true;
        }
        return false;
    }

    int last_day(int m, int y) {
        int d;
        
        switch (m)
        {
        case 2:
            d = check_leap(y) ? 29 : 28;
            break;
        case 4: case 6: case 9: case 11:
            d = 30;
            break;
        default:
            d = 31;
            break;
        }
        return d;
    }


void advance(int delta, int& d, int& m, int& y) {
     int ldim = last_day(m,y);

    for (int i = 0; i <delta; i++){
        if (d < ldim) {
            d++;
        }
        else {
            d = 1;
            m++;
            if (m>12) {
                m = 1;
                y++;
            }
            ldim = last_day(m,y);
           
        }
    }

}


int main () {
     // public tests (1 points each)
  {
    int d = 1, m = 1, y = 2022; 
    advance(0, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 1 1 2022
  {
    int d = 1, m = 10, y = 2022; 
    advance(10, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 11 10 2022
  {
    int d = 2, m = 6, y = 2022; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 3 7 2022
  {
    int d = 2, m = 7, y = 2022; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 2 8 2022
  {
    int d = 25, m = 2, y = 2000; 
    advance(4, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 29 2 2000
  {
    int d = 25, m = 2, y = 2001; 
    advance(4, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 1 3 2001
  {
    int d = 2, m = 12, y = 1900; 
    advance(365 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 7 12 1901
  {
    int d = 31, m = 3, y = 1903; 
    advance(365 + 366 + 30 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 5 5 1905
  
  // private test(s (1000 points each)
  cout << '\n';
  {
    int d = 1, m = 1, y = 2022; 
    advance(364, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 31 12 2022
  {
    int d = 1, m = 9, y = 2022; 
    advance(30 + 31 + 30 + 31 + 11, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 12 1 2023
  {
    int d = 2, m = 2, y = 2021; 
    advance(31, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 5 3 2021
  {
    int d = 1, m = 11, y = 2019; 
    advance(30, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 1 12 2019
  {
    int d = 29, m = 2, y = 2000; 
    advance(14, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 14 3 2000
  {
    int d = 28, m = 2, y = 2001; 
    advance(87, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 26 5 2001
  {
    int d = 31, m = 12, y = 1901; 
    advance(365 + 5, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 5 1 1903
  {
    int d = 30, m = 4, y = 1904; 
    advance(1234, d, m, y); 
    cout << d << ' ' << m << ' ' << y << '\n'; 
  } // => 16 9 1907

    return 0;
}