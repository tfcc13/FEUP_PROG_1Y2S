/*
Write a C++ function

int nrl(const char s[], char low[])

such that:

    s is a string containing uppercase or lowercase letter characters (‘A’ to ‘Z’, ‘a’ to ‘z’) and also the space character (‘ ‘) — spaces should be ignored and a lowercase character (e.g. ‘a’) should be considered equivalent to the corresponding uppercase letter (e.g., ‘A’);
    the function returns the number of non-repeated letters in s, that is, the number of letters that occur only once in s; and
    on return, low is a lowercase string containing all letters that occur only once in s, ordered alphabetically (remember that, as usual, C strings must be null-terminated).

Hint: there are 26 letters in the alphabet. Use an int array of length 26 to keep track of the frequency count of all letters that occur in s. 
*/


#include <iostream>
#include <string>
using namespace std;

int nrl(const char s[], char low[]) {

    int arr [26] ={0};
    int j;
    for (int k = 0 ; s[k] != '\0';k++) {
        j = (int) (tolower(s[k]) - 'a');
        arr[j]++;
    }
    int count=0;
    for (int i = 0; i <26; i++) {
        if (arr[i] == 1) {
            low +=  'a'+i;
            count++;
        }
    }

    return count;

}

int main() {
      // public tests (1 point each)
  {
    const char s[] = "";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> "" 0 ""
  {
    const char s[] = "  F C U P  F E U P  Porto  ";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> "  F C U P  F E U P  Porto  " 4 "cert"
  {
    const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> " abC dEf GhI jKl MnO pQr StU vWx yZ " 26 "abcdefghijklmnopqrstuvwxyz"
  {
    const char s[] = " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> " abC dEf GhI jKl MnO pQr StU vWx yZ ABc DeF gHi JkL mNo PqR sTu VwX Yz" 0 ""
  {
    const char s[] = "The quick brown fox jumps over the lazy dog";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> "The quick brown fox jumps over the lazy dog" 20 "abcdfgijklmnpqsvwxyz"

  cout << '\n'; 
  // private tests (1000 points each)
  {
    const char s[] = " a ";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> " a " 1 "a"
  {
    const char s[] = "A quick brown fox jumps over a classy dog";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> "A quick brown fox jumps over a classy dog" 17 "bdefgijklmnpqvwxy"
  {
    const char s[] = "wwm fjord bank glyphs vext Quixiz";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> "wwm fjord bank glyphs vext Quixiz" 22 "abdefghjklmnopqrstuvyz"
  {
    const char s[] = "The five boxing wizards jump quickly";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> "The five boxing wizards jump quickly" 23 "abcdfghjklmnopqrstvwxyz"
  {
    const char s[] = " ZYXWVUTSRQPONMLKJIHGFEDCBA abcdefghijklmnopqrstuvwxyz ";
    char l[27] = { -1 };
    int r = nrl(s, l);
    cout << '\"' << s << "\" "
         << r << " \"" << l << "\"\n";
  } // -> " ZYXWVUTSRQPONMLKJIHGFEDCBA abcdefghijklmnopqrstuvwxyz " 0 ""

    return 0;

}