/*
Bell numbers B0,B1,B2,… count the possible partitions of a set, i.e., the number or partitions for a set with n≥0 elements is given by Bn, where B0=B1=1 and for n≥2

Bn=∑n−1k=0(n−1k)Bk

Write a C++ function unsigned long bell(unsigned long n) to compute Bell numbers.
Hint: Note that binomial coefficients are used in the definition above. Reuse the code of the previous exercise to compute them.
*/

#include <iostream>

using namespace std;

 unsigned long bc(unsigned long n, unsigned long k){
    unsigned long num = 1, den = 1;

    for (unsigned long i = 1; i<=k; i++) {
        num *= (n-i+1);
        den *= i;
    }

    return num/den;
 }

unsigned long bell(unsigned long n) {
    
    unsigned long res = 0;

    if (n <= 1 ) return 1;

    else {

        for (unsigned long i = 0 ; i <n ; i++) {
            res += bc(n-1,i)*bell(i);
        }
    
    }
    return res;

}


int main() {
  // public tests (1 point each)
  cout << bell(0) << '\n'; // 1
  cout << bell(1) << '\n'; // 1
  cout << bell(2) << '\n'; // 2
  cout << bell(3) << '\n'; // 5
  cout << bell(4) << '\n'; // 15
  cout << bell(6) << '\n'; // 203 

  // private test(s (1000 points each)
  cout << '\n';
  cout << bell(5) << '\n'; // => 52
  cout << bell(7) << '\n'; // => 877
  cout << bell(9) << '\n'; // => 21147
  cout << bell(10) << '\n'; // => 115975
  cout << bell(11) << '\n'; // => 678570
  cout << bell(15) << '\n'; // => 1382958545

  return 0;
}
