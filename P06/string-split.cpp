/*
Write a C++ function void split(const string& s, vector<string>& v) that places in vector v all strings that occur in s separated by one or more spaces.

Hints: The class string member functions find and substr may be useful:

    s.find(' ', pos) searches for the space character in s starting from position pos — it returns the position of the first space found, or the constant string::npos if the space character is not found;
    s.substr(pos, len) produces the substring of s that starts at position pos and has len characters.


*/

#include <iostream>
#include <vector>
#include <string>
#include "print_string.h"

using namespace std;

void split(const string& s, vector<string>& v) {
    
    size_t pos = 0;


    while( pos < s.length()) {
        if  (s[pos] == ' ') {
        pos++;
        }
        else {
            size_t end = s.find(' ',pos);
            if (end == string::npos) {
                end = s.length();
            }
        v.push_back(s.substr(pos,end-pos));
        pos = end;
        }

    }



    }


int main() {
  cout<<endl;
  // public tests (1 point each)
  {
    string s = "";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ ]
  {
    string s = "    ";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ ]
  {
    string s = "  a b  c ";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ "a" "b" "c" ]
  {
    string s = "C++ LEIC FCUP FEUP";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ "C++" "LEIC" "FCUP" "FEUP" ]
  {
    string s = "       C++        ";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ "C++" ]
  cout << "\n";
  // private tests (1000 points each)
  {
    string s = " ";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ ]
  {
    string s = "abc";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ "abc" ]
  {
    string s = "       C + +        ";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ "C" "+" "+" ]
  {
    string s = "C + +  L E I C  F C U P  F E U P";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ "C" "+" "+" "L" "E" "I" "C" "F" "C" "U" "P" "F" "E" "U" "P" ]
  {
    string s = "The quick brown fox jumps over the lazy dog";
    vector<string> v;
    split(s, v);
    print(v);
  } // -> [ "The" "quick" "brown" "fox" "jumps" "over" "the" "lazy" "dog" ]
  return 0;
}
