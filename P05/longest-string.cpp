/*
Write a C++ function const char* longest(const char* pa[]) that takes a nullptr-terminated array pa of pointers to C strings and returns the array element (a C string pointer) corresponding to the longest string. In case there is more than one C string with maximum length, the rightmost element should be returned. You may assume pa contains at least one element before nullptr.

Hint: All you need to do is return pa[k] where k is the position pointing to the string of interest. You should not allocate any dynamic memory. 
*/

#include <iostream>
using namespace std;

int length(const char* s) {
    int l=0;
    while(s[l] != '\0') {
        l++;
    }

    return l;
}

 const char* longest(const char* pa[]) {
    int max_length = 0;
    const char* res = nullptr;

    for (int i = 0; pa[i] != nullptr; i++) {
        int l = length(pa[i]);
        if (l >= max_length) {
            max_length = l;
            res = pa[i];
        }
    }
    return res;

 }

 int main() {
  // public tests (1 point each)
  {
    const char* pa[] = { "C++", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "C++"
  {
    const char* pa[] = { "", "0123", "Hello", "world", "!", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "world"
  {
    const char* pa[]  = { "Hello_world", "Hello", "Hello world", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "Hello world"
  {
    const char* pa[] = { "Hello world!", "Hello_world", "Hello world", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "Hello world!"
  {
    const char* pa[] = { "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "Typescript", "OCaml", "Fortran", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "Typescript"

  // private tests (1000 points each)
  cout << '\n';
  {
    const char* pa[] = { "", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> ""
  {
    const char* pa[] = { "X", "Y", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "Y"
  {
    const char* pa[] = { "Phi", "Theta", "Psi", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "Theta"
  {
    const char* pa[] = { "Typescript", "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "OCaml", "Fortran", "Javascript", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "Javascript"
  {
    const char* pa[] = { "Typescript", "C++", "Python", "Java", "C#", "Julia", "Rust", "Haskell", "OCaml", "Fortran", nullptr };
    cout << "\"" << longest(pa) << "\"\n";
  } // -> "Typescript"

  return 0;
}