/*

Write a C++ function int adigits(int a, int b, int c) that receives 3 integers, each one with a single decimal digit and returns the highest integer number that can be assembled with the 3 digits given as parameters.

*/

#include <iostream>
using namespace std;

int adigits(int a, int b, int c) {
    int res = 0;
    if (a>=b && a>=c) {
        if (b>=c) {
            res = a*100 +b*10+c;
        }        
        else res = a*100 + c*10 +b;
    }
    else if (b>=a && b>=c) {
        if (c >= a){
        res = b*100+c*10+a;
        }
        else {
            res = b*100 +a*10 +c;
        }
    }
    
    else  {
        if (a>= b){
            res = c*100+a*10+b;
    }
        else {
            res = c*100+b*10+a;
        }
}
    return res;
}

int main() {
  // public tests (1 points each)
  cout << adigits(4, 2, 5) << '\n'; // 542
  cout << adigits(9, 1, 9) << '\n'; // 991
  cout << adigits(1, 2, 3) << '\n'; // 321
  cout << adigits(1, 0, 0) << '\n'; // 100

  // private test(s (1000 points each)
  cout << adigits(7, 1, 4) << '\n'; // 741
  cout << adigits(6, 7, 2) << '\n'; // 762
  cout << adigits(7, 7, 7) << '\n'; // 777
  cout << adigits(5, 5, 8) << '\n'; // 855

  return 0;
}