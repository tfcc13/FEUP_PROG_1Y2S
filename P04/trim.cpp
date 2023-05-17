/*

Write a C++ function void trim(char s[]) that takes a C string s and removes all its leading and trailing spaces.

*/

#include <iostream> 
using namespace std;


 void trim(char s[]) {

    int i = 0;
    while (s[i] == ' ') {
        i++;
    }

    int j = 0;
    while (s[i]) {
        s[j] = s[i];
        j++;
        i++;
    }

    s[j] = '\0';
    j--;

    while (j >= 0 && s[j] == ' ') {
        s[j] = '\0';
        j--;
    }
 }

 int main() {

    // public tests (1 point each)
  {
    char s[] = " abc! def? ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // " abc! def? " => "abc! def?"
  {
    char s[] = "#abc";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "#abc" => "#abc"
  {
    char s[] = "    abc def";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "    abc def" => "abc def"
  {
    char s[] = "abc def.   ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "abc def.   " => "abc def."
  {
    char s[] = "   ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "   " => ""
  {
    char s[] = "";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "" => ""
  {
    char s[] = " abc  _  def  _  ghi ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // " abc  _  def  _  ghi " => "abc  _  def  _  ghi"
  {
    char s[] = "a           ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "a           " => "a"

  // private tests (1000 point each)
  cout << '\n';
  {
    char s[] = "  abc def ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "  abc def " => "abc def"
  {
    char s[] = " x ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // " x " => "x"
  {
    char s[] = "    x";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "    x" => "x"
  {
    char s[] = "x";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "x" => "x"
  {
    char s[] = "a    z";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // "a    z" => "a    z"
  {
    char s[] = " ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // " " => ""
  {
    char s[] = " abc_def_ghi xyz";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // " abc_def_ghi xyz" => "abc_def_ghi xyz"
  {
    char s[] = " C / C + + ! ? # ! ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } // " C / C + + ! ? # ! " => "C / C + + ! ? # !"

    return 0;
 }

