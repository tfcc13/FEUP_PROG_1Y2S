/*
Write a C++ function void calc_medians(const string& input_fname, const string& output_fname) that reads several series of double values, one series per line, stored in input file named input_fname, and outputs to file name output_fname corresponding lines with the median value of the series.

Input files may have comment lines, beginning with the # character, that should be ignored, and each series of values begins with a string identifier followed by the values to consider in the same line separated by one or more space characters.

The output file should have one line per series with the corresponding identifier and median value with one decimal place of precision (you may use fixed and setprecision defined in the iomanip header to guarantee this).

For instance, given the input file with contents:

# a 1.2 1.0 this is a comment line
b 1.2 1.0
# another comment line
c 1.3
d -1.0 2.0 1.0

then the generated output file should have contents:

b 1.1
c 1.3
d 1.0

The median of a sequence of n sorted values v[0], . . . , v[n-1] is:

    v[n/2], if n is odd; or
    0.5 * (v[ n / 2 - 1] + v[ n / 2]), if n is even.

Note that the values in each series in input files are not guaranteed to be sorted. To handle this detail, you may store read values in a vector v and then sort the values using sort, i.e. call sort(v.begin(), v.end()) before calculating the median value.

To run the provided tests, you need to include a header file named show_file.h (download the file) that contains an utility function show_file for printing file contents. You also need to download the ex5.zip archive containing the text files used in public tests (p5_test[1-5].txt). 
*/

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <algorithm>
#include "show_file.h"

using namespace std;


double median_calc(vector<double>& vec_1) {
    size_t size_vec = vec_1.size();
    sort(vec_1.begin(),vec_1.end());
    if (size_vec % 2 == 0) {
        return ((vec_1.at(size_vec/2)+vec_1.at(size_vec/2-1))/2);
    }
    return vec_1.at(size_vec/2);

}

void calc_medians(const string& input_fname, const string& output_fname) {
    ifstream infile(input_fname);
    ofstream outfile(output_fname);
    string line;

    for (string line; getline(infile,line);) {
        if (line[0] == '#') continue;
        istringstream iss(line);
        string id;
        iss >> id;
        vector<double> med_vec;
        for (double x;  iss >> x;) {
            med_vec.push_back(x);
        }
        outfile << id << ' ' << fixed << setprecision(1) << median_calc(med_vec) << '\n';
    }

    

}

int main(int argc, char**argv) {
  // -> public testes (1 point each)
  {
    calc_medians("p5_test1.txt", "p5_test1_out.txt"); 
    show_file("p5_test1_out.txt");
  } /* -> 
==> p5_test1_out.txt <==
a 3.0
  */
  {
    calc_medians("p5_test2.txt", "p5_test2_out.txt"); 
    show_file("p5_test2_out.txt");
  } /* -> 
==> p5_test2_out.txt <==
b 1.1
c 1.3
d 1.0
*/
  {
    calc_medians("p5_test3.txt", "p5_test3_out.txt"); 
    show_file("p5_test3_out.txt");
  } /* ->
==> p5_test3_out.txt <==
u1 1.5
u2 2.0
u3 2.0
u4 -0.5
*/
  {
    calc_medians("p5_test4.txt", "p5_test4_out.txt"); 
    show_file("p5_test4_out.txt");
  } /* ->
==> p5_test4_out.txt <==
___a 1.0
___b 1.0
___c 0.5
___d 1.0
*/
  {
    calc_medians("p5_test5.txt", "p5_test5_out.txt"); 
    show_file("p5_test5_out.txt");
  } /* ->
==> p5_test5_out.txt <==
___a 1.0
___b 1.0
___c 0.5
___d 1.0
*/

  // -> private tests (1000 points each)
  // download test files from https://moodle.up.pt/pluginfile.php/170067/mod_folder/content/0/07/ex5-p.zip?forcedownload=1
  {
    calc_medians("p5_test6.txt", "p5_test6_out.txt"); 
    show_file("p5_test6_out.txt");
  } /* ->
==> p5_test6_out.txt <==
a 3.3
  */
  {
    calc_medians("p5_test7.txt", "p5_test7_out.txt"); 
    show_file("p5_test7_out.txt");
  } /* ->
==> p5_test7_out.txt <==
b 1.1
__c 1.3
d 1.0
  */
  {
    calc_medians("p5_test8.txt", "p5_test8_out.txt"); 
    show_file("p5_test8_out.txt");
  } /* ->
==> p5_test8_out.txt <==
u1 1.5
_u2 2.0
__u3 2.0
___u4 -3.1
  */
  {
    calc_medians("p5_test9.txt", "p5_test9_out.txt"); 
    show_file("p5_test9_out.txt");
  } /* ->
==> p5_test9_out.txt <==
___a 2.2
___b 1.2
___c 0.0
___d 10.0
  */
  {
    calc_medians("p5_test10.txt", "p5_test10_out.txt"); 
    show_file("p5_test10_out.txt");
  } /* ->
==> p5_test10_out.txt <==
___a 11.0
___b 100.0
___c 46.0
___d 1999.1
  */

  return 0;
}