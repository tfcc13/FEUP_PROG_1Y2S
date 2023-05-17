//Write a C++ function int max(const int a[], int n) that returns the maximum value of all n > 0 elements stored in array a. 

#include <iostream>
using namespace std;

int max(const int a[], int n) {
    int max_fun = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max_fun) {
            max_fun = a[i];
        }

    }
    return max_fun;
}


int main() {

  // public test cases (1 points each) 
  {
    const int n = 1;
    const int a[n] = { -123 };
    cout << max(a,n) << '\n';
  } // => -123
  { 
    const int n = 3; 
    const int a[n] = { -3, -2, -1 };
    cout << max(a, n) << '\n';
  } // => -1
  { 
    const int n = 4; 
    const int a[n] = { 4, -2, 3, 1 };
    cout << max(a, n) << '\n';
  } // => 4
  { 
    const int n = 9;
    const int a[n] = { 10, 20, 30, -2, 50, 3, 1, 50, 49 };
    cout << max(a, n) << '\n';
  } // => 50

  // private test cases (1000 points each) 
  cout << '\n';
  {
    const int n = 7;
    const int a[n] = { 123, 456, -789, 101112, 987, -654, 321 };
    cout << max(a,n) << '\n';
  } // => 101112
  { 
    const int n = 2; 
    const int a[n] = { 2, 1 };
    cout << max(a, n) << '\n';
  } // => 2
  { 
    const int n = 4; 
    const int a[n] = { -4, -2, -3, 1 };
    cout << max(a, n) << '\n';
  } // => 1
  { 
    const int n = 9;
    const int a[n] = { 59, 10, 20, 30, -2, 50, 3, 1, 50 };
    cout << max(a, n) << '\n';
  } // => 59

    return 0;
}