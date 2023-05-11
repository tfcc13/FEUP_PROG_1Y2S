/*Pell numbers P0,P1,P2,… are given by P0=0, P1=1 and Pn=2Pn−1+Pn−2 for n≥2

.

Write a C++ function unsigned long pell(unsigned long n) to compute Pell numbers.

Note: Use an iterative implementation, not a recursive one. A  "direct" recursive implementation will result in an exponential number of recursive calls and trigger a "Time Limit Exceeded" evaluation error. */


#include <iostream>

using namespace std;


unsigned long pell(unsigned long n) {

    if (n== 0) return 0;
    if (n==1) return 1;

    unsigned long tmp_1 = 0;
    unsigned long tmp_2 = 1;
    unsigned long pell;

    for (unsigned long i = 2; i <= n; i++) {

    pell = 2*tmp_2 + tmp_1;
    tmp_1 = tmp_2;
    tmp_2 = pell;

    }
    return pell;


}

int main() {
      // public tests (1 point each)
  cout << pell(0) << '\n'; // => 0
  cout << pell(1) << '\n'; // => 1
  cout << pell(2) << '\n'; // => 2
  cout << pell(3) << '\n'; // => 5
  cout << pell(5) << '\n'; // => 29
  cout << pell(50) << '\n'; // => 4866752642924153522
  
  // private tests (1000 points each)
  cout << '\n';
  cout << pell(4) << '\n'; // => 12
  cout << pell(6) << '\n'; // => 70
  cout << pell(10) << '\n'; // => 2378
  cout << pell(22) << '\n'; // => 93222358
  cout << pell(33) << '\n'; // => 1513744654945
  cout << pell(49) << '\n'; // => 2015874949414289041

     
    return 0;
}