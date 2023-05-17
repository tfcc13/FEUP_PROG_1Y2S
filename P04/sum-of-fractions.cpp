/*
Consider a type for integer fractions defined by

struct fraction {
   int num; // Numerator
   int den; // Denominator
}; 

Write a C++ function fraction sum(const fraction fa[], int n) that returns the sum of all n fractions stored in array fa. The returned fraction should be irreducible and its denominator should always be positive; you may assume all fractions stored in fa obey these conditions and that n > 0.

In your code you should include header file fraction.h (you need to download the file) that contains the fraction type, along with support for printing fraction values using cout (used in tests).

Hint: The Euclidean algorithm for computing the greatest common divisor of two numbers can be helpful. It is expressed by the following recurrence:

gcd(a,b)={agcd(b,a%b), if b=0, if b≠0
*/

#include <iostream>
#include "fraction.h"

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b,a%b);
}

fraction normalise(fraction& f) {

    
    int g = gcd(f.num,f.den);
    f.den = f.den/g;
    f.num = f.num/g;

    if (f.den<0) {
        f.den = -f.den;
        f.num = -f.num;
    }

    return f;

}

fraction add(fraction a, fraction b) {
    fraction r;
    r.num = a.num*b.den + b.num*a.den;
    r.den = a.den*b.den;
    return normalise(r);
}



fraction sum(const fraction fa[], int n) {
    
    fraction result = fa[0];

    for (int i = 1; i <n ; i++) {
        result = add(result, fa[i]);
    }
    
    return normalise(result);


}


int main() {
      cout << "\n// public tests (1 point each)\n";
  {
    const int n = 1;
    const fraction fa[n] { {1, 2} };
    cout << sum(fa, n) << '\n';
  } // => 1/2
  {
    const int n = 2;
    const fraction fa[n] { {1, 2}, {-1, 3}};
    cout << sum(fa, n) << '\n';
  } // => 1/6
  {
    const int n = 3;
    const fraction fa[n] { {1, 2}, {-1, 3}, {-3, 4} };
    cout << sum(fa, n) << '\n';
  } // => -7/12
  {
    const int n = 4;
    const fraction fa[n] { {-1, 4}, {1, 2}, {-1, 8}, {-1, 8} };
    cout << sum(fa, n) << '\n';
  } // => 0
  {
    const int n = 5;
    const fraction fa[n] { {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5}};
    cout << sum(fa, n) << '\n';
  } // => -13/60
  {
    const int n = 6;
    const fraction fa[n] { {133,60}, {0, 1}, {1, 2}, {-2, 3}, {3, 4}, {-4, 5}};
    cout << sum(fa, n) << '\n';
  } // => 2

  cout << "\n// private tests (1000 points each)\n";
  {
    const int n = 1;
    const fraction fa[n] { {-2, 17} };
    cout << sum(fa, n) << '\n';
  } // => -2/17
  {
    const int n = 2;
    const fraction fa[n] { {4, 15}, {-1, 5}};
    cout << sum(fa, n) << '\n';
  } // => 1/15
  {
    const int n = 3;
    const fraction fa[n] { {1, 7}, {-1, 5}, {-3, 4} };
    cout << sum(fa, n) << '\n';
  } // => -113/140
  {
    const int n = 4;
    const fraction fa[n] { {-1, 3}, {1, 5}, {-2, 7}, {-1, 9} };
    cout << sum(fa, n) << '\n';
  } // -167/315
  {
    const int n = 5;
    const fraction fa[n] { {0, 1}, {0, 1}, {0, 3}, {-1, 4}, {4, 5}};
    cout << sum(fa, n) << '\n';
  } // => 11/20
  {
    const int n = 5;
    const fraction fa[n] { {1, 40}, {-63, 40}, {0, 3}, {-1, 4}, {4, 5}};
    cout << sum(fa, n) << '\n';
  } // => -1
 
 
  return 0; 

}