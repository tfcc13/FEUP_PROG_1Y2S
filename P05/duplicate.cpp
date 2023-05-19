/*
Write a C++ function char* duplicate(const char s[]) that returns a pointer to a dynamically allocated C string with the same contents as s. The result string should be allocated using new. 
*/

#include <iostream>
#include <string>
using namespace std;

char* duplicate(const char s[]) {
    int n = 0;
    while(s[n] != '\0') {
        n++;
    }

    char* res_str = new char[n+1];

    for (int i = 0; i< n; i++) {
        res_str[i] = s[i];
    } 

    res_str[n] = '\0';
    return res_str;

}

int main() {
  // public tests (1 point each) 
  {
    char* s = duplicate("");
    cout << "\"" << s << "\"\n";
    delete [] s;
  } // -> ""
  {
    char* s = duplicate("a");
    cout << "\"" << s << "\"\n";
    delete [] s;
  } // -> "a"
  {
    char* s = duplicate("C++");
    cout << "\"" << s << "\"\n";
    delete [] s;
  } // -> "C++"
  {
    char* s = duplicate("0123 456 789 @ abc");
    cout << "\"" << s << "\"\n";
    delete [] s;
  } // -> "0123 456 789 @ abc"
  
  // private tests (1000 points each) 
  cout << '\n';
  {
    char* s = duplicate("xy");
    cout << "\"" << s << "\"\n";
    delete [] s;
  } // -> "xy"
  {
    char* s = duplicate("0");
    cout << "\"" << s << "\"\n";
    delete [] s;
  } // -> "0"
  {
    char* s = duplicate("z++ y-- k**");
    cout << "\"" << s << "\"\n";
    delete [] s;
  } // -> "z++ y-- k**"
  {
    char* s = duplicate("How many s.trings must a pointer walk down .. the answer my friend is blowing in the wind.");
    cout << "\"" << s << "\"\n";
    delete [] s;
  } // -> "How many s.trings must a pointer walk down .. the answer my friend is blowing in the wind."

  return 0; 
}
