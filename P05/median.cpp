/*
The median of a sequence of n sorted values v[0], . . . , v[n-1] is:

    v[n/2], if n is odd; or
    (v[ n / 2 - 1] + v[ n / 2]) / 2, if n is even.

Write a C++ function int median(const int a[], int n) that returns the median value of n values contained in an arbitrary array a. Note that a is not guaranteed to be sorted and must not be changed by the function.

To implement the function, the following steps are suggested:

    Create a temporary array tmp of size n allocated using new.
    Copy the values of a onto tmp.
    Sort the temporary array using the std::sort library function declared in the <algorithm> system header using a call of the form: sort(tmp, tmp + n);
    Compute the median value as explained above.
    Before returning, don't forget to release the memory associated with tmp using delete (since the array is no longer necessary).

*/

#include <iostream>
#include <algorithm>
using namespace std;

int median(const int a[], int n) {
    int* b = new int[n];

    
    for (int i = 0 ; i< n; i++) {
        b[i] = a[i];
    }

    std::sort(b, b+n);

    if (n %2 == 0) {
        return (b[n/2]+b[n/2-1])/2;
    }
    else {
    return b[n/2];
    } 
    

}
int main() {
  // -> public testes (1 point each)
  {
    const int n = 5; 
    int a[n] { 10, -10, 0, 12, 11 };
    cout << median(a, n) << '\n';
  } // -> 10
  {
    const int n = 6; 
    int a[n] { 30, 10, 0, -20, 14, 20 };
    cout << median(a, n) << '\n';
  } // -> 12
  {
    const int n = 1; 
    int a[n] { 99 };
    cout << median(a, n) << '\n';
  } // -> 99
  {
    const int n = 2; 
    int a[n] { 101, 99 };
    cout << median(a, n) << '\n';
  } // -> 100

  // -> private testes (1000 points each)
  {
    const int n = 5; 
    int a[n] { 50, -60, 0, 22, 44 };
    cout << median(a, n) << '\n';
  } // -> 22
  {
    const int n = 6; 
    int a[n] { 33, 12, 0, -24, 18, 28 };
    cout << median(a, n) << '\n';
  } // -> 15
  {
    const int n = 1; 
    int a[n] { 999 };
    cout << median(a, n) << '\n';
  } // -> 999
  {
    const int n = 2; 
    int a[n] { 1001, 999 };
    cout << median(a, n) << '\n';
  } // -> 1000

  return 0;
}