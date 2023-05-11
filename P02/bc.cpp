/*Binomial coefficients occur in many areas of mathematics. A possible formulation of binomial coefficients is as follows for n>=0 and 0≤k≤n

:

(nk)=n×(n−1)×…×(n−k+1)k×(k−1)×…×1

Write a C++ function unsigned long bc(unsigned long n, unsigned long k) to compute binomial coefficients.

Hint: be careful to use only unsigned long variables to avoid numerical overflows.

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


 int main() {
  // public tests
  cout << bc(5, 0) << '\n'; // => 1
  cout << bc(5, 1) << '\n'; // => 5
  cout << bc(5, 5) << '\n'; // => 1
  cout << bc(5, 2) << '\n'; // => 10
  cout << bc(12, 7) << '\n'; // => 792
  cout << bc(20, 10) << '\n'; // => 184756
  
  // private tests
  cout << '\n';
  cout << bc(13, 13) << '\n'; // => 1
  cout << bc(9, 2) << '\n'; // => 36
  cout << bc(20, 14) << '\n'; // => 38760
  cout << bc(16, 14) << '\n'; // => 120
  cout << bc(13, 6) << '\n'; // => 1716
  cout << bc(20, 13) << '\n'; // => 77520
 
  return 0; 
}
