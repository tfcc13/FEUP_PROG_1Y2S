/*
Write a C++ template function

  template <typename T>
  void normalise(vector<T>& v, const T& min, const T& max)

such that a call to normalise(v, min, max) “normalises” all values x contained in vector v as follows:

    If x < min then x should be replaced by min;
    If x > max then x should be replaced by max; and
    Otherwise the value of x should be unchanged.

To run the provided tests, you need to include a header file named print_vector.h (download) that contains an utility function print for printing vector with elements of type T. 
*/

#include <iostream>
#include <vector>
#include "print_vector.h"
using namespace std;


template<typename T>
 void normalise(vector<T>& v, const T& min, const T& max) {
    for (size_t i = 0; i< v.size(); i++) {
        if (v[i] < min) {
            v[i] = min;
        }
        if (v[i] > max) {
            v[i] = max;
        }
    }
 }



int main() {
  // public tests (1 point each) 
  {
    vector<int> v { };
    normalise(v, 0, 1);
    print(v);
  } // -> [ ]
  {
    vector<int> v { 1, 2, 3, 4, 5 };
    normalise(v, 1, 5);
    print(v);
  } // -> [ 1 2 3 4 5 ]
  {
    vector<int> v { 1, 2, 3, 4, 5 };
    normalise(v, 3, 4);
    print(v);
  } // -> [ 3 3 3 4 4 ]
  {
    vector<double> v { -1.2, 2.2, -3.5, 4.3, 5.2 };
    normalise(v, 0.5, 5.1);
    print(v);
  } // -> [ 0.5 2.2 0.5 4.3 5.1 ]
  {
    vector<string> v { "Diego", "Afonso", "Antonio", "Bernardo", "Tolentino", "Zeferino", "Xavier" };
    normalise(v, string("Antonio"), string("Zacarias"));
    print(v);
  } // -> [ Diego Antonio Antonio Bernardo Tolentino Zacarias Xavier ]

  cout << "\n";
  // private tests (1000 points each)
  {
    vector<int> v { 5 };
    normalise(v, 0, 10);
    print(v);
  } // -> [ 5 ]
  {
    vector<int> v { 1, 2, 3, 4, 5 };
    normalise(v, 3, 3);
    print(v);
  } // -> [ 3 3 3 3 3 ]
  {
    vector<double> v { 2.2, -1.2, 2.2, -3.5, 4.3, 5.2, 7.5, 3.4 };
    normalise(v, 0.5, 5.1);
    print(v);
  } // -> [ 2.2 0.5 2.2 0.5 4.3 5.1 5.1 3.4 ]
  {
    vector<char> v { 'a', 'f', 'h', 'x', 'b', 'c', 'd', 'x', 'e', 'f', 'g', 'z' };
    normalise(v, 'f', 'i');
    print(v);
  } // -> [ f f h i f f f i f f g i ]
  {
    vector<string> v { "Always", "Look", "on", "the", "Bright", "Side", "of", "Life" };
    normalise(v, string("Cleese"), string("Palin"));
    print(v);
  } // -> [ Cleese Look Palin Palin Cleese Palin Palin Life ]

  return 0;
}
