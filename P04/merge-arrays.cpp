/*
Enunciado da pergunta

Write a C++ function void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) that merges 2 arrays, a with na > 0 elements and b, with nb > 0 elements, sorted in ascending order, placing the result in array c. The values in c must also be sorted in ascending order.

To run the provided tests, you need to include a header file named print_array.h (download) that contains an utility function print_array for printing array values. 
*/

#include <iostream> 
#include "print_array.h"
using namespace std;

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) {

    int a_size = 0,b_size = 0, c_size = 0;

    while (a_size < na && b_size < nb) {
        if (a[a_size] < b[b_size]) {
            c[c_size] = a[a_size];
            a_size++;
        }
        else {
            c[c_size] = b[b_size];
            b_size++;
        }
        c_size ++;
    }

    while (a_size < na) {
        c[c_size] = a[a_size];
        a_size++;
        c_size++;
    }


while (b_size < nb) {
        c[c_size] = b[b_size];
        b_size++;
        c_size++;
    }

}

int main() {
  cout << "\n// public tests (1 point each)\n";
  {
    const int NA = 4, NB = 6;
    int a[NA] = { 1, 2, 4, 7};
    int b[NB] = { 0, 3, 5, 6, 8, 9};
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [0,1,2,3,4,5,6,7,8,9]
  {
    const int NA = 6, NB = 4;
    int a[NA] = { 0, 3, 5, 6, 8, 9};
    int b[NB] = { 1, 2, 4, 7};
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [0,1,2,3,4,5,6,7,8,9]
  {
    const int NA = 2, NB = 3;
    int a[NA] = { 0, 1 };
    int b[NB] = { 2, 3, 4 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [0,1,2,3,4]
  {
    const int NA = 3, NB = 2;
    int a[NA] = { 2, 3, 4 };
    int b[NB] = { 0, 1 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [0,1,2,3,4]
  {
    const int NA = 15, NB = 15;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
    int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [0,0,0,1,1,1,2,2,3,3,3,4,4,5,5,5,5,6,6,6,6,7,7,7,8,8,8,9,9,9]

  cout << "\n// private tests (1000 points each)\n";
  {
    const int NA = 1, NB = 1;
    int a[NA] = { 2 };
    int b[NB] = { 1 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [1,2]
  {
    const int NA = 1, NB = 2;
    int a[NA] = { 2 };
    int b[NB] = { 1, 3};
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [1,2,3]
  {
    const int NA = 7, NB = 11;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5 };
    int b[NB] = { 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // =>[0,1,1,2,3,3,3,4,4,5,5,5,5,6,7,7,8,9]
  {
    const int NA = 16, NB = 12;
    int a[NA] = { 0, 0, 1, 1, 1, 4, 5, 5, 5, 6, 7, 7, 8, 8, 8, 9 };
    int b[NB] = { 4, 4, 4, 4, 4, 6, 6, 6, 6, 7, 8, 8};
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [0,0,1,1,1,4,4,4,4,4,4,5,5,5,6,6,6,6,6,7,7,7,8,8,8,8,8,9]
  {
    const int NA = 13, NB = 15;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8 };
    int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int c[NA+NB];
    merge_arrays(a, NA, b, NB, c);
    print_array(c, NA+NB);
  } // => [0,0,0,1,1,1,2,2,3,3,3,4,4,5,5,5,5,6,6,6,6,7,7,7,8,8,8,9]



    return 0;
}