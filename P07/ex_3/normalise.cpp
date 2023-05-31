/*
Write a C++ function void normalise(const string& input_fname, const string& output_fname) that normalises the contents of input file named input_fname and writes them onto an output file named output_fname. The input file contents should be converted to the output file as follows:

    Lines that contain only space characters should not be written to the output file;
    Leading and trailing spaces in a line should be erased;
    All characters should be uppercased.

To run the provided tests, you need to include a header file named print.h (download the file) that contains an utility function print for printing file contents. You also need to download the ex3.zip archive containing the text files used in public tests (p3_test[1-5].txt). You may assume that the only blank characters contained in files are the space and newline character.

Hints: You should use an ofstream object to write the output file. You may use toupper to convert characters to uppercase. 
*/

#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include "print.h"

void normalise(const string& input_fname, const string& output_fname) {
    ifstream infile(input_fname);
    ofstream outfile(output_fname);
    string line;

    while(getline(infile,line)) {
        line.erase(0,line.find_first_not_of(' '));
        line.erase(line.find_last_not_of(' ') + 1);

        for (char& c: line) {
            c = toupper(c);
        }
        if (line.length() >0 ) {
            outfile << line << '\n';
        }
    }

}

int main(int argc, char**argv) {
  // -> public testes (1 point each)
  {
    normalise("p3_test1.txt", "p3_test1_out.txt"); 
    print("p3_test1_out.txt");
  } /* ->
1 |WORD ONE|
2 |WORD TWO|
3 |WORD THREE SPACES FOLLOW|
4 |AND ONE FINAL EMPTY LINE|
    */
  {
    normalise("p3_test2.txt", "p3_test2_out.txt"); 
    print("p3_test2_out.txt");
  } /* -> 
1 |C++|
2 |LEIC UP|
3 |PYTHON 3|
4 |PYTHON 2|
    */
  {
    normalise("p3_test3.txt", "p3_test3_out.txt"); 
    print("p3_test3_out.txt");
  } /* ->
1 |THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG|
  */
  {
    normalise("p3_test4.txt", "p3_test4_out.txt"); 
    print("p3_test4_out.txt");
  } /* ->
1 |T H E|
2 |Q U I C K  B R O W N|
3 |F O X  J U M P S  O V E R  T H E|
4 |L A Z Y|
5 |D|
6 |O|
7 |G|
  */
  {
    normalise("p3_test5.txt", "p3_test5_out.txt"); 
    print("p3_test5_out.txt");
  } /* ->
1 |ABCDEFGHIIJKLMOPQRSTUVWXYZ|
2 |0123456789 0123456789 0123456789|
3 |ABCDEFGHIIJKLMOPQRSTUVWXYZ|
4 |0123456789 0123456789 0123456789|
  */

  cout << '\n';
  // private testes (1000 points each)
  // download test files from https://moodle.up.pt/pluginfile.php/170067/mod_folder/content/0/07/ex3-p.zip?forcedownload=1
  {
    normalise("p3_test6.txt", "p3_test6_out.txt"); 
    print("p3_test6_out.txt");
  } /* ->
1|TO TEST YOUR CODE DOWNLOAD THE EX3.ZIP|
2|ARCHIVE CONTAINING THE TEXT FILES USED IN|
3|PUBLIC TESTS (P3_TEST[1-5].TXT).|
  */
  {
    normalise("p3_test7.txt", "p3_test7_out.txt"); 
    print("p3_test7_out.txt");
  } /* ->
1|YOU MAY ASSUME THAT THE ONLY BLANK CHARACTERS CONTAINED IN|
2|FILES ARE THE SPACE AND NEWLINE CHARACTER.|
  */
  {
    normalise("p3_test8.txt", "p3_test8_out.txt"); 
    print("p3_test8_out.txt");
  } /* ->
1|HINTS: YOU SHOULD USE AN  OFSTREAM  OBJECT TO WRITE|
2|THE OUTPUT FILE.|
3|YOU MAY USE TOUPPER TO CONVERT CHARACTERS TO UPPERCASE.|
  */
  {
    normalise("p3_test9.txt", "p3_test9_out.txt"); 
    print("p3_test9_out.txt");
  } /* ->
1|{|
2|WCRESULT R = WC("P2_TEST6.TXT");|
3|COUT << R.LINES << ' ' << R.WORDS << ' ' << R.BYTES << '\N';|
4|} // -> 1 14 94 // -> 14 74 419|
  */
  {
    normalise("p3_test10.txt", "p3_test10_out.txt"); 
    print("p3_test10_out.txt");
  } /* ->
1|WCRESULT R { 0, 0, 0 };|
2|FOR (STRING LINE; GETLINE(IN, LINE);) {|
3|R.LINES++;|
4|R.BYTES += LINE.LENGTH() + 1;|
  */

  return 0;
}