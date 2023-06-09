/*
Write the C++ code for two template functions to_string and replace, declared as:

template <typename Itr> 
string to_string(Itr start, Itr end)

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b)

such that:

    to_string(start, end) takes two iterators start and end associated with the same container and yields a string representation of the form "[ elem_1 elem_2 ... elem_n ]" of all elements of the container between start and end, including start but excluding end; and
    replace(start, end, a, b) traverses all elements between start and end, including start but excluding end, replacing values of a by values of b, and returns the number of elements that were replaced.

Hints:

    Consider the use of the following iterator operators: ++, != and *.
    Use an ostringstream object in to_string() to build the string result.

*/

#include <string>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;


template <typename Itr> 
string to_string(Itr start, Itr end) {
    ostringstream out;

    Itr itr = start;

    out << '[' ;

    while (itr != end) {

        out << ' ' << *itr;
        itr++;
    } 

    out << ' ' << ']';

    return out.str();
}


template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b) {

    Itr itr = start;

    size_t count = 0;

    while (itr != end) {
        if (*itr == a) {
            *itr = b;
            count++;
        }
        itr++;
    }
    return count;
}



int main() {
  // public tests (1 point each)
   {
      vector<int> v;
      cout << replace(v.begin(), v.end(), 0, 1) << ' '
           << to_string(v.cbegin(), v.cend()) << '\n';
   } // -> 0 [ ]
   {
      vector<int> v { 1, 2, 3, 3, 4 };
      cout << replace(v.begin(), v.end(), 3, 0) << ' '
           << to_string(v.cbegin(), v.cend()) << '\n';
   } // -> 2 [ 1 2 0 0 4 ]
   {
      vector<int> v { 5, 1, 2, 3, 4, 5 };
      cout << replace(v.begin() + 1, v.end() - 1, 5, 0) << ' '
           << to_string(v.cbegin(), v.cend()) << '\n';
   } // -> 0 [ 5 1 2 3 4 5 ]
   {
      list<string> l { "C++", "Java", "C++", "Python", "Rust", "C" } ;
      cout << replace(l.begin(), l.end(), string("C++"), string("Rust")) << ' '
           << replace(l.begin(), l.end(), string("C"), string("Rust")) << ' '
           << to_string(l.cbegin(), l.cend()) << '\n';
   } // -> 2 1 [ Rust Java Rust Python Rust Rust ]
   {
      string s = "Hello world";
      cout << replace(s.begin(), s.end(), 'l', 'L') << ' '
           << to_string(s.cbegin(), s.cend()) << ' ' 
           << replace(s.rbegin(), s.rend(), 'o', 'O') << ' '
           << to_string(s.crbegin(), s.crend()) <<  ' '
           << to_string(s.cbegin(), s.cend()) << '\n';
   } // -> 3 [ H e L L o   w o r L d ] 2 [ d L r O w   O L L e H ] [ H e L L O   w O r L d ]
  cout << '\n';
  // Private tests (1000 points each) 
   {
      vector<int> v;
      cout << replace(v.begin(), v.end(), 6, 9) << ' '
           << to_string(v.cbegin(), v.cend()) << '\n';
   } // -> 0 [ ]
   {
      vector<int> v { 1, 2, 2, 3, 2, 4 };
      cout << replace(v.begin(), v.end(), 2, 0) << ' '
           << to_string(v.cbegin(), v.cend()) << '\n';
   } // -> 3 [ 1 0 0 3 0 4 ]
   {
      vector<int> v { 9, 5, 4, 3, 2, 1, 9 };
      cout << replace(v.begin() + 1, v.end() - 1, 9, 0) << ' '
           << to_string(v.cbegin(), v.cend()) << '\n';
   } // -> 0 [ 9 5 4 3 2 1 9 ]
   {
      list<string> l { "C++", "Java", "C++", "Python", "Rust", "C", "Java" } ;
      cout << replace(l.begin(), l.end(), string("C++"), string("Python")) << ' '
           << replace(l.begin(), l.end(), string("C"), string("Python")) << ' '
           << to_string(l.cbegin(), l.cend()) << '\n';
   } // -> 2 1 [ Python Java Python Python Rust Python Java ]
   {
      string s = "Monty Python Fly";
      cout << replace(s.begin(), s.end(), 'y', 'i') << ' '
           << to_string(s.cbegin(), s.cend()) << ' ' 
           << replace(s.rbegin(), s.rend(), 'o', 'O') << ' '
           << to_string(s.crbegin(), s.crend()) <<  ' '
           << to_string(s.cbegin(), s.cend()) << '\n';
   } // -> 3 [ M o n t i   P i t h o n   F l i ] 2 [ i l F   n O h t i P   i t n O M ] [ M O n t i   P i t h O n   F l i ]

  return 0;
}