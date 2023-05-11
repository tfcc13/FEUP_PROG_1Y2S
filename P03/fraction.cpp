/*
Consider a type for integer fractions defined by

struct fraction {
   int num; // Numerator
   int den; // Denominator
};

Write two C++ functions for fraction addition and multiplication, i.e.

fraction add(fraction a, fraction b)

and

fraction mul(fraction a, fraction b)

The returned fraction should be irreducible and its denominator should always be positive; you may assume fractions a and b given as arguments obey these conditions.

In your code you should include header file fraction.h (you need to download the file) that contains the declarations of the above functions and the fraction type, along with support from printing fractions using cout (used in tests).

Hint: The Euclidean algorithm for computing the greatest common divisor of two numbers can be helpful. It is expressed by the following recurrence:
gcd(a,b)={agcd(b,a%b), if b=0, if b≠0
*/


#include <iostream>
#include "fraction.h"

int gcd(int i, int j) {
    if (j == 0) return i;
    return gcd(j, i%j);
} 

fraction normalise(fraction x) {
    int g = gcd(x.num,x.den);
    x.num /= g;
    x.den /= g;

    if (x.den<0) {
        x.num = -x.num;
        x.den = -x.den;
    }
    return x;
}

fraction add(fraction a, fraction b){
    fraction res;
    res.num = a.num * (b.den) + b.num*(a.den);
    res.den =a.den*b.den;
    return normalise(res);
}

fraction mul(fraction a, fraction b) {
    fraction res;
    res.num = a.num*b.num;
    res.den = a.den * b.den;
    return normalise(res);

}

int main() {
      // public tests (1 point each)
  {
    fraction a { 0, 1 }, b { 2, 1};
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 2 0
  {
    fraction a { 1, 1 }, b { -1, 2};
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 1/2 -1/2
  {
    fraction a { -3, 2 }, b { 3, 2 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 0 -9/4
  {
    fraction a { -3, 2 }, b { -2, 3 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => -13/6 1
  {
    fraction a { -7, 24 }, b { 1, 3 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 1/24 -7/72
  {
    fraction a { -8, 25 }, b { 3, 4 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 43/100 -6/25
  {
    cout << add({7,4536},mul({-5,21},add({1,2}, mul({-2,3}, {1,9})))) << '\n';
  } // => -151/1512
  // private tests (1 point each)
  cout << '\n';
  {
    fraction a { 1, 30 }, b { -1, 15};
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => -1/30 -1/450
  {
    fraction a { 0, 1 }, b { 0, 1};
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 0 0
  {
    fraction a { 5, 12 }, b { -3, 8 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 1/24 -5/32
  {
    fraction a { 3, 2 }, b { -2, 3 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 5/6 -1
  {
    fraction a { -1, 8 }, b { -16, 33 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => -161/264 2/33
  {
    fraction a { 5, 1 }, b { 3, 4 };
    cout << add(a,b) << ' ' << mul(a,b) << '\n';
  } // => 23/4 15/4
  {
    cout << mul({7,4536},add({-5,21},mul({1,2}, add({-2,3}, {1,9})))) << '\n';
  } // => -65/81648

    return 0;
}