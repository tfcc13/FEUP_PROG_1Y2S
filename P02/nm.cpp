/*

A Mersenne number is a number of the form Mn=2n−1 for some positive integer n≥0

.

Write a C++ function unsigned long next_mersenne(unsigned long n) that returns the lowest Mersenne number greater or equal to n.

You cannot use the pow or other cmath functions. 

*/

#include <iostream>
using namespace std;

unsigned long mn_calc(unsigned long exp) {
    unsigned long dos_calc = 1;
    unsigned long new_mars;
    for (unsigned long i = 0; i <= exp; i++) {
        dos_calc *= 2;
    } 

    new_mars = dos_calc -1;

    return new_mars;

    
}

unsigned long next_mersenne(unsigned long n) {

    unsigned long mn;
    unsigned long count= 0;

while (true) {

    mn = mn_calc(count);
    count++;

    if (mn >= n) break;
    

}

    return mn;

}

int main() {
  // public tests (1 point each)
  cout << next_mersenne(0) << '\n'; // => 0
  cout << next_mersenne(1) << '\n'; // => 1
  cout << next_mersenne(2) << '\n'; // => 3
  cout << next_mersenne(4) << '\n'; // => 7
  cout << next_mersenne(128) << '\n'; // => 255
  cout << next_mersenne(4294967296UL) << '\n'; // => 8589934591
  cout << '\n';
  // private tests (1000 point each)
  cout << next_mersenne(3) << '\n'; // => 3
  cout << next_mersenne(8) << '\n'; // => 15
  cout << next_mersenne(1923) << '\n'; // => 2047
  cout << next_mersenne(1125899906842624UL) << '\n'; // => 2251799813685247
  cout << next_mersenne(9223372036854775806UL) << '\n'; // 9223372036854775807
  cout << next_mersenne(9223372036854775807UL) << '\n'; // 9223372036854775807

  return 0; 
}
