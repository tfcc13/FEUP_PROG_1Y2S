/*
A character sequence in some alphabet is called a pangram if it contains every letter in the alphabet. For instance, "The quick brown fox jumps over the lazy dog" is a pangram in English since it contains all letters A to Z.

Write a C++ function bool pangram(const string& s, string& m) such that:

    s is a string containing uppercase or lowercase letter characters (‘A’ to ‘Z’, ‘a’ to ‘z’) and also the space character (‘ ‘) — spaces should be ignored and a lowercase character (e.g. ‘a’) should be considered equivalent to the corresponding uppercase letter (e.g., ‘A’);
    the function returns true if and only if the given string s is a pangram, that is, it contains all letters A to Z in lowercase or uppercase form; and
    on return, m is a lowercase string containing all letters that are missing in s, ordered alphabetically (m will be the empty string if s is a pangram).

Hint: there are 26 letters in the alphabet. Use an internal array of length 26 to keep track of the letters that occur in s.


*/

#include <iostream>
#include <string>
using namespace std;

bool pangram(const string& s, string& m)  {

    int a[26] = {0};
    for (int i = 0; s[i] != '\0';i++) {
        char low = tolower(s[i]);
        if(low >= 'a' && low <= 'z') {
            a[low - 'a']++;
            

        }
    }
    bool flag = true;
    for (int i = 0; i<26; i++) {
        if (a[i] == 0) {
            m += 'a'+i;
            flag = false;
            
        }
    }
    return flag;
    

}

int main() {
      cout<<endl;
  // public tests (1 point each)
  {
    string s = "";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" "
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> "" false "abcdefghijklmnopqrstuvwxyz"
  {
    string s = "The quick brown fox jumps over the lazy dog";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> "The quick brown fox jumps over the lazy dog" true ""
  {
    string s = "A quick brown fox jumps over a classy dog";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> "A quick brown fox jumps over a classy dog" false "htz"
  {
    string s = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> " abC dEf GhI jKl MnO pQr StU vWx yZ " true ""
  {
    string s = " Stu yZ abC GhI MnO pQr   ";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> " Stu yZ abC GhI MnO pQr   " false "defjklvwx"
 
  cout<<endl;
  // private tests (1000 points each)
  {
    string s = "Cwm fjord bank glyphs vext quiz";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> "Cwm fjord bank glyphs vext quiz" true ""
  {
    string s = "The five boxing wizards jump quickly";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> "The five boxing wizards jump quickly" true ""
  {
    string s = "Pack my box with five dozen liquor jugs";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> "Pack my box with five dozen liquor jugs" true ""
  {
    string s = "Cwm fford bbnk glyphs vext quiqui";
    string m = "";
    bool r = pangram(s, m);
    cout << '\"' << s << "\" " 
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> "Cwm fford bbnk glyphs vext quiqui" false "ajz"
  {
    string s = "Hi";
    string m = "";
    bool r = pangram(s, m);                                                                                                                                                                                                                                                     
    cout << '\"' << s << "\" "
         << boolalpha << r << " \"" << m << "\"\n";
  } // -> "Hi" false "abcdefgjklmnopqrstuvwxyz"

  return 0;
}