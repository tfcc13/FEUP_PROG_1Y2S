/*
Write a C++ function int* merge_arrays(const int a[], int na, const int b[], int nb) that returns a dynamically allocated array that merges the elements of two arrays, a with na > 0 elements and b, with nb > 0 elements, both sorted in ascending order. The result array must also be sorted in ascending order.

To run the provided tests, you need to include a header file named print_array.h (download) that contains an utility function print_array for printing array values.

Hint: You should allocate the array for the result using new. The code should be otherwise the same as exercise 4.2 last week. 
*/
#include <iostream>
#include "print_array.h"
using namespace std;
int* merge_arrays(const int a[], int na, const int b[], int nb) {

    int* c = new int[na+nb];
    int i = 0, j = 0, k = 0 ;
    while( i < na && j < nb) {

        if (a[i]<b[j]) {
            c[k] = a[i];
            i++;
        }

        else {
            c[k] = b[j];
            j++;
        }
    k++;


    }

    while (i<na) {
        c[k] = a[i];
        k++;
        i++;
    }

    while (j<nb) {
        c[k] = b[j];
        k++;
        j++;
    }

    return c;

}

int main() {
  // public tests (1 point each)
  {
    const int NA = 4, NB = 6;
    int a[NA] = { 1, 2, 4, 7};
    int b[NB] = { 0, 3, 5, 6, 8, 9};
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [0,1,2,3,4,5,6,7,8,9]
  {
    const int NA = 6, NB = 4;
    int a[NA] = { 0, 3, 5, 6, 8, 9};
    int b[NB] = { 1, 2, 4, 7};
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [0,1,2,3,4,5,6,7,8,9]
  {
    const int NA = 2, NB = 3;
    int a[NA] = { 0, 1 };
    int b[NB] = { 2, 3, 4 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [0,1,2,3,4]
  {
    const int NA = 3, NB = 2;
    int a[NA] = { 2, 3, 4 };
    int b[NB] = { 0, 1 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [0,1,2,3,4]
  {
    const int NA = 15, NB = 15;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
    int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [0,0,0,1,1,1,2,2,3,3,3,4,4,5,5,5,5,6,6,6,6,7,7,7,8,8,8,9,9,9]

  // private tests (1000 points each
  cout << '\n';
  {
    const int NA = 1, NB = 1;
    int a[NA] = { 2 };
    int b[NB] = { 1 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [1,2]
  {
    const int NA = 1, NB = 2;
    int a[NA] = { 2 };
    int b[NB] = { 1, 3};
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [1,2,3]
  {
    const int NA = 7, NB = 11;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5 };
    int b[NB] = { 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // =>[0,1,1,2,3,3,3,4,4,5,5,5,5,6,7,7,8,9]
  {
    const int NA = 16, NB = 12;
    int a[NA] = { 0, 0, 1, 1, 1, 4, 5, 5, 5, 6, 7, 7, 8, 8, 8, 9 };
    int b[NB] = { 4, 4, 4, 4, 4, 6, 6, 6, 6, 7, 8, 8};
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [0,0,1,1,1,4,4,4,4,4,4,5,5,5,6,6,6,6,6,7,7,7,8,8,8,8,8,9]
  {
    const int NA = 13, NB = 15;
    int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8 };
    int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
    int* c = merge_arrays(a, NA, b, NB);
    print_array(c, NA+NB);
    delete [] c;
  } // => [0,0,0,1,1,1,2,2,3,3,3,4,4,5,5,5,5,6,6,6,6,7,7,7,8,8,8,9]

  return 0;
}