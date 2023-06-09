/*
Write a C++ function void replace(const map<char, char>& r, string& s), that replaces all characters in s according to the character replacement dictated by r, i.e., a character c in s should be replaced by r[c] if c is a key in r. 
*/

#include <iostream>
#include <map>
#include <string>

using namespace std;



void replace(const map<char, char>& r, string& s) {
    for (char &c :s) {
        if ( r.find(c) != r.end()) {
            c = r.find(c)->second;
        }
    }
}

#include <iostream>
int main() {
  // public tests (1 point each)
  {
    string s = "C / C++ @ LEIC";
    replace({ {'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s);
    cout << s << '\n';
  } // -> z / z-- @ XEIz
  {
    string s = "C / C++ @ LEIC";
    replace({ }, s);
    cout << s << '\n';
  } // -> C / C++ @ LEIC
  {
    string s = "A B C D E F";
    replace({ {' ', '_'}}, s);
    cout << s << '\n';
  } // -> A_B_C_D_E_F
  {
    string s = "A B C D E F";
    replace({ {'_', ' '}, {'A', '?'}, {'?', '!'}, {'F', '!'}}, s);
    cout << s << '\n';
  } // -> ? B C D E !

  cout << '\n';
  // private tests (1000 points each)
  {
    string s = "C / C++ @ LEIC / C++ @ LEIC";
    replace({ {'C', 'W'}, {'*', '-'}, {'L', 'Y'}}, s);
    cout << s << '\n';
  } // -> W / W++ @ YEIW / W++ @ YEIW
  {
    string s = "C / C++ @ LEIC / C++ @ LEIC";
    replace({ }, s);
    cout << s << '\n';
  } // -> C / C++ @ LEIC / C++ @ LEIC
  {
    string s = "A B C D E F G H W X Z";
    replace({ {' ', '-'}}, s);
    cout << s << '\n';
  } // -> A-B-C-D-E-F-G-H-W-X-Z
  {
    string s = "A B C D E F G H W Z X Z";
    replace({ {'_', ' '}, {'A', '-'}, {'?', '+'}, {'F', '*'}}, s);
    cout << s << '\n';
  } // -> - B C D E * G H W Z X Z

  return 0;
}

