/*
Write a C++ function void maximum(const string& input_fname, const string& output_fname) that reads double values with variable number of decimal places, stored one per line in input file named input_fname, and outputs to file name output_fname the corresponding values, one per line, rounded to 3 decimal places. In the end, the function outputs the number of values read and the maximum value (see examples in the tests). You may assume that the values are all in the range [-1000,1000].

To run the provided tests, you need to include a header file named show_file.h (download the file) that contains an utility function show_file for printing file contents. You also need to download the ex4.zip archive containing the text files used in public tests (p4_test[1-4].txt).

You may assume that the only blank characters contained in files are the space and newline character and may use fixed and setprecision defined in the iomanip header to write the values rounded to 3 decimal places. 
*/


#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <iomanip>
#include "show_file.h"


void maximum(const string& input_fname, const string& output_fname) {
    ifstream infile(input_fname);
    ofstream outfile(output_fname);
    int count = 0;
    double num;
    double max_double = -1001;

    while (infile>>num) {
        count++;
        if (num > max_double) max_double = num;
        outfile << fixed << setprecision(3) << num << '\n'; 
    }
    outfile << "count="<< count <<'/'<<"max="<<max_double;
}


int main() {
  cout << endl;
  // -> public testes (1 point each)
  {
    maximum("p4_test1.txt", "p4_test1_out.txt");
    show_file("p4_test1_out.txt");
  } /* -> 
==> p4_test1_out.txt <==
-1.200
1.222
3.142
count=3/max=3.142
  */
  {
    maximum("p4_test2.txt", "p4_test2_out.txt");
    show_file("p4_test2_out.txt");
  } /* -> 
==> p4_test2_out.txt <==
-11.223
-65.240
-3.142
count=3/max=-3.142
  */
  {
    maximum("p4_test3.txt", "p4_test3_out.txt");
    show_file("p4_test3_out.txt");
  } /* -> 
=> p4_test3_out.txt <==
-11.000
0.000
12.452
1234.568
count=4/max=1234.568
  */
  {
    maximum("p4_test4.txt", "p4_test4_out.txt");
    show_file("p4_test4_out.txt");
  } /* -> 
==> p4_test4_out.txt <==
1.223
1.200
3.146
count=3/max=3.146
  */
 
  cout << endl;
  // -> private testes (1000 points each)
  // download test files from https://moodle.up.pt/pluginfile.php/170067/mod_folder/content/0/07/ex4-p.zip?forcedownload=1
  {
    maximum("p4_test5.txt", "p4_test5_out.txt");
    show_file("p4_test5_out.txt");
  } /* -> 
==> p4_test5_out.txt <==
-11.220
65.234
3.142
123.667
count=4/max=123.667
  */
  {
    maximum("p4_test6.txt", "p4_test6_out.txt");
    show_file("p4_test6_out.txt");
  } /* -> 
==> p4_test6_out.txt <==
-11.223
11.223
25.240
12.345
2.000
3.142
count=6/max=25.240
  */
  {
    maximum("p4_test7.txt", "p4_test7_out.txt");
    show_file("p4_test7_out.txt");
  } /* -> 
==> p4_test7_out.txt <==
3.141
-11.223
0.000
11.223
35.240
12.345
2.000
count=7/max=35.240
  */
  {
    maximum("p4_test8.txt", "p4_test8_out.txt");
    show_file("p4_test8_out.txt");
  } /* -> 
==> p4_test8_out.txt <==
3.142
3.141
-1.222
2.444
3.666
1.222
1.222
-3.142
6.532
-1.222
2.444
count=11/max=6.532
  */

  return 0;
}