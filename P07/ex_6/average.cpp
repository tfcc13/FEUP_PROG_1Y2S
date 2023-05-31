/*
Write a C++ function double average(const string& fname) such that average(fname) returns the average of the double values stored in a text file named fname. The file can contain characters that lead to errors when reading double values, and the function should recover from this by skipping one character at a time from the file input stream.

For example, if the file contents are

3.0 1.5 invalid_input3.0

then the average value computed should be 2.5 (the sum of the three numbers that occur in the file is 7.5).

To test your code download the ex6.zip archive containing the text files used in public tests (p6_test[1-5].txt).

Hints: You should use an ifstream object to read a file. In addition to the use of the extraction operator (>>) for reading double values, the following associated member functions in ifstream should be useful:

    eof() to test if the end of file has been reached;
    clear() to clear error flags in the ifstream object; and
    ignore() to skip a desired amount of characters.

*/

#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

double average(const string& fname){
    ifstream infile(fname);
    double res = 0;
    int count = 0;
   

    while (!infile.eof()) {
        double num;
        if (infile >> num) {
            res += num;
            count++;
        }
        else {
            infile.clear();
            infile.ignore(1);
        }

    }
    return res/count;
}


int main(int argc, char**argv) {
  // -> public tests (1 point each)
  {
    double m = average("p6_test1.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 2.50
  {
    double m = average("p6_test2.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 2.50
  {
    double m = average("p6_test3.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 0.75
  {
    double m = average("p6_test4.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 1.00
  {
    double m = average("p6_test5.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 3.50

  cout << '\n';
  // -> private tests (1000 points each)
  // download test files from https://moodle.up.pt/pluginfile.php/170067/mod_folder/content/0/07/ex6-p.zip?forcedownload=1
  {
    double m = average("p6_test6.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 2.56
  {
    double m = average("p6_test7.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 0.92
  {
    double m = average("p6_test8.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 3.76
  {
    double m = average("p6_test9.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 1.56
  {
    double m = average("p6_test10.txt"); 
    cout << fixed << setprecision(2) << m << '\n';
  } // -> 1.38

  return 0;
}
