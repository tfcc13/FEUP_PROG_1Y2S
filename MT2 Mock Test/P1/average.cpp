/*
Write a C++ function bool average(const string& input_fname, const string& output_fname) that reads several series of double values, one series per line, stored in input file named input_fname, and outputs to file name output_fname corresponding lines with the average value of the series rounded to 3 decimal places. In the end, the function outputs the number of lines read.

The function returns false if it fails to open the input file and true otherwise. Note that fail() may be used to test if an error has occurred on the associated stream.

To run the provided tests, you need to include a header file named show_file.h that contains an utility function show_file for printing file contents. You also need to download the ex1a.zip archive containing the text files used in public tests (p1a-[1-4].txt).

You may assume that the only blank characters contained in files are the space and newline character. 
*/

#include <sstream>
#include <fstream>
#include <ostream>
#include <iostream>
#include <string>
#include <iomanip>
#include "show_file.h"


using namespace std;

 bool average(const string& input_fname, const string& output_fname) {

    ifstream inp(input_fname);
    ofstream out(output_fname);
    string line;
    double number;
    int count_lines = 0;
    while( getline(inp,line)) {
        double count = 0;
        double avg = 0;
        istringstream iss(line);

        while(iss >> number) {
            avg += number;
            count++;
        }

        avg /= count;
        count_lines++;

        out << fixed << setprecision(3) << avg << '\n';
       
    }
    out << "lines=" << count_lines;
    return true;

    


 }

 int main() {

    { if (average("p1a-1.txt", "p1a-1_out.txt"))
    show_file("p1a-1_out.txt"); }

	

//==> p1a-1_out.txt <==
//1.629
//1.222
//1.695
//lines=3

{ if (average("p1a-2.txt", "p1a-2_out.txt"))
    show_file("p1a-2_out.txt"); }

	

//==> p1a-2_out.txt <==
//0.000
//26.528
//3.141
//lines=3

{ if (average("p1a-3.txt", "p1a-3_out.txt"))
    show_file("p1a-3_out.txt"); }

	

// ==> p1a-3_out.txt <==
//0.000
//18.786
//lines=2

{ if (average("p1a-4.txt", "p1a-4_out.txt"))
    show_file("p1a-4_out.txt"); }

//==> p1a-4_out.txt <==
//1.629
//1.222
//0.848
//26.528
//3.141
//lines=5

    return 0;

 }