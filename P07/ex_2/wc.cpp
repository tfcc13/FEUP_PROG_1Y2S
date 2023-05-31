/*
Write a C++ function wcresult wc(const string& filename) that reads a file and computes statistics that are similar to those computed by the “wc” Linux command line utility: the total number of lines, total number of words, and number of bytes. Any sequence of non-blank characters is considered a word, and wcresult is defined as:

struct wcresult {
  unsigned int lines;
  unsigned int words;
  unsigned int bytes;
};

In your code you should include the header file wc.h (you need to download the file) that contains the declaration of the above wcresult type.

To test your code download the ex2.zip archive containing the text files used in public tests (p2_test[1-5].txt). You may assume that the only blank characters contained in files are the space and newline character.

Hints: You should use an ifstream object to read a file and getline to read entire lines onto string objects. Employing istringstream may also be useful to break a line into words. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include "wc.h"
using namespace std;

wcresult wc(const string& filename) {
    wcresult res = {0,0,0};
    ifstream infile(filename);
    string line;

    while ( getline(infile,line))  {
        res.lines++;
        res.bytes += line.size()+1;
        istringstream iss(line);
        string word;
        while (iss>>word) {
            res.words++;
    }
    }

    return res;
    }


int main(int argc, char**argv) {
  // -> public testes (1 point each)
  {
    wcresult r = wc("p2_test1.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 1 0 1
  {
    wcresult r = wc("p2_test2.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 6 13 92
  {
    wcresult r = wc("p2_test3.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 1 9 44
  {
    wcresult r = wc("p2_test4.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 4 9 51
  {
    wcresult r = wc("p2_test5.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 39 188 1051

  cout << '\n';
  // -> private tests (1000 points each)
  // download test files from https://moodle.up.pt/pluginfile.php/170067/mod_folder/content/0/07/ex2-p.zip?forcedownload=1
  {
    wcresult r = wc("p2_test6.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 1 14 94
  {
    wcresult r = wc("p2_test7.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 14 74 419
  {
    wcresult r = wc("p2_test8.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 9 125 830
  {
    wcresult r = wc("p2_test9.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 3335 26443 144390
  {
    wcresult r = wc("p2_test10.txt"); 
    cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n';
  } // -> 34 223 1106

  return 0;
}
