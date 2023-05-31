/*
Write a C++ function int count(const string& fname, const string& word) such that count(fname, word) returns the number of occurrences of the word in the file named fname, where word is a string that does not contain blank characters (e.g., spaces, tabs, line breaks). The word count should be case insensitive (e.g. "string" and "STRING" should be considered equivalent).

To test your code download the ex1.zip archive containing 2 text files used in public tests (p1_test_a.txt and p2_test_b.txt).

Hint: you need to use an ifstream object in conjunction with the >> operator (the extraction operator) to read strings from the file ( >> skips over blank characters automatically). You may use toupper or tolower to convert characters to uppercase or lowercase respectively.


*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int count(const string& fname, const string& word) {

    ifstream in(fname);
    string nword;
    string tmp;
    int count = 0;
    for (char k:word) {
        k = tolower(k);
        nword += k;
    }

    while(in >> tmp) {
        for (char& c:tmp) {
            c = tolower(c);
        }
        if (tmp == nword) {
            count++;
        }
    }
    return count;


}


int main() {
  // public tests (1 point each)
  cout << count("p1_test_a.txt", "THE") << '\n';      // -> 4
  cout << count("p1_test_a.txt", "0") << '\n';        // -> 1
  cout << count("p1_test_a.txt", "code") << '\n';     // -> 0
  cout << count("p1_test_b.txt", "Collider") << '\n'; // -> 6
  cout << count("p1_test_b.txt", "you") << '\n';      // -> 21

  cout << '\n';
  // private (1000 points each)
  cout << count("p1_test_a.txt", "exerCISE") << '\n';  // -> 1
  cout << count("p1_test_b.txt", "feeling") << '\n';   // -> 0
  cout << count("p1_test_b.txt", "feelings") << '\n';  // -> 1
  cout << count("p1_test_b.txt", "i") << '\n';         // -> 5
  cout << count("p1_test_b.txt", "lOvE") << '\n';      // -> 4

  return 0;
}
