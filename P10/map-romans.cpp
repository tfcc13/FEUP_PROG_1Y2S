/*
Write a C++ function unsigned roman_to_arab(const string& roman), that, given a valid roman numeral in the standard form (as a string), returns its corresponding decimal value (as an unsigned integer).

Use the following vector to map each individual roman symbol to its decimal value:

vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

Note: a pair<F,S> object is a template struct to represent pairs: it has fields first of type F and second of type S (std::pair). 
*/

#include <iostream>
#include <vector>

using namespace std;

unsigned roman_to_arab(const string& roman) {

unsigned result = 0;

vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

string::const_iterator it;
vector<pair<char,unsigned>>::const_iterator it2;

for (it = roman.cbegin(); it != roman.cend(); it++) {
    for (it2 = roman_to_int.begin(); it2 != roman_to_int.end(); it2++) {
        if (*it==it2->first) result += it2->second;
    }
    switch(*it) {
    case 'V':
            if  ((it-1) != roman.cbegin() && *(it-1) == 'I') result -= 1*2;
            break;
            
            case 'X':
            if ((it-1) != roman.cbegin() && *(it-1) == 'I') result -= 1*2;
            break;
            
            case 'L':
            if ((it-1) != roman.cbegin() && *(it-1) == 'I') result -= 1*2;
            if ((it-1) != roman.cbegin() && *(it-1) == 'X') result -= 10*2;
            break;

            case 'C':
            if ((it-1) != roman.cbegin() && (*it-1) == 'I') result -= 1*2;
            if ((it-1) != roman.cbegin() && *(it-1) == 'X') result -= 10*2;
            break;

            case 'D':
            if ((it-1) != roman.cbegin() && *(it-1) == 'I') result -= 1*2;
            if ((it-1) != roman.cbegin() &&*(it-1) == 'X') result -= 10*2;
            if ((it-1) != roman.cbegin() &&*(it-1) == 'C') result -= 100*2;
            break;

            case 'M':
            if (*(it-1) == 'I') result -= 1*2;
            if (*(it-1) == 'X') result -= 10*2;
            if (*(it-1) == 'C') result -= 100*2;
            break;

            default:
             break;
        }
}
 return result;
}
/* Alternativa
unsigned map_roman(char c)
{
  // the dictionary, local but created only once
  static vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

  unsigned result = 0;
  for (const auto &elem : roman_to_int) {
    if (elem.first == c) {
      result = elem.second;
      break;
    }
  }
  return result;
}

// Converts roman numbers to arabic numbers
unsigned roman_to_arab(const string& s) {
  // traverse the string and add the value of each char
  unsigned decimal = 0;
  for (size_t i = 0, n = s.length(); i < n; i++) {
    unsigned this_dec = map_roman(s[i]);
    // compare with the value of next char
    if (i < n - 1 and this_dec < map_roman(s[i + 1])) {
      decimal = decimal - this_dec + map_roman(s[i + 1]);
      i++;
    }
    else
      decimal += this_dec;
  }
  return decimal;
}
 */

int main() {
  // private tests (1 point each)
  {
    string r = "XV";
    cout << roman_to_arab(r) << '\n';
  }  // -> 15
  {
    string r = "LXXXIV";
    cout << roman_to_arab(r) << '\n';
  }  // -> 84
  {
    string r = "CMLXIV";
    cout << roman_to_arab(r) << '\n';
  }  // -> 964
  {
    string r = "MMMCMXCIX";
    cout << roman_to_arab(r) << '\n';
  }  // -> 3999
  {
    string r = "MMMDCCCLXXXVIII";
    cout << roman_to_arab(r) << '\n';
  }  // -> 3888
  cout << '\n';
  //private tests (1000 points each)
  {
    string r = "MCMLXVI";
    cout << roman_to_arab(r) << '\n';  
  } // -> 1966
  {
    string r = "MMCDVI";
    cout << roman_to_arab(r) << '\n';
  }  // -> 2406
  {
    string r = "MMXIX";
    cout << roman_to_arab(r) << '\n';
  }  // -> 2019
  {
    string r = "MCMXCV";
    cout << roman_to_arab(r) << '\n';
  }  // -> 1995
  {
    string r = "LXXIII";
    cout << roman_to_arab(r) << '\n';
  }  // -> 73

  return 0;
}