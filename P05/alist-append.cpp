/*
Consider the code given in alist.h (you need to download this file), supporting the definition of “array lists” (lists represented using an array) containing elements of type int. Type alist defines member fields size of type int, expressing the number of elements in an array list, and elements, a pointer to a dynamically allocated array of elements of type int containing the elements and length equal to size.

struct alist {
  int size;       // Number of elements.
  int* elements;  // List elements.
};

The following functions, implemented in alist.h, are defined in association to alist:

    alist* build(int n, int v[]): create a new array list with n > 0 elements with initial values given in array v.
    alist* empty(): create a new array list that is initially empty, i.e., has no elements — for an empty list al, al->size is set to 0 and al->elements is set to nullptr.
    destroy(alist* al): releases the memory allocated to al; and
    print(alist* al): prints the elements in al.

Define a new function void append(alist* a, const alist* b) such that a call to append(a, b) appends all the elements in list b to list a. Note that, except when a or b represent the empty list, the internal array used by a must be replaced by a new array with size a->size + b->size. Moreover, b can't be changed. 
*/


#include <iostream>
#include "alist.h"
using namespace std;

void append(alist* a, const alist* b) {
    if(b->size == 0) return;

    int size = a->size + b->size;
    int* elements = new int[size];

    int count = 0;

    for (int i = 0; i< a->size; i++) {
        elements[i] = a->elements[i];
    }

    for (int i = 0; i < b->size; i++) {
        elements[a->size+i] = b->elements[i];

    }

    delete [] a->elements;
    a->size = size;
    a->elements = elements;


}

int main() {
  // public tests (1 point each)
  {
    alist* a = empty();
    const alist* b = empty();
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ ]
  {
    alist* a = empty();
    const int nB = 2;
    int eB[nB] = { 1, 2 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 1 2 ]
  {
    const int nA = 2;
    int eA[nA] = { 1, 2 };
    alist* a = build(nA, eA);
    const alist* b = empty();
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 1 2 ]
  {
    const int nA = 2;
    int eA[nA] = { 1, 2 };
    alist* a = build(nA, eA);
    const int nB = 3;
    int eB[nB] = { 3, 4, 5 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 1 2 3 4 5 ]
  {
    const int nA = 4;
    int eA[nA] = { 1, 2, 3, 4 };
    alist* a = build(nA, eA);
    const int nB = 3;
    int eB[nB] = { 5, 6, 7 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 1 2 3 4 5 6 7 ]

  cout << endl;
  // private tests (1000 points each)
  {
    const int nA = 7;
    int eA[nA] = { 1, 2, 14, 16, 28, 29, 30 };
    alist* a = build(nA, eA);
    const alist* b = empty();
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 1 2 14 16 28 29 30 ]
  {
    const int nA = 1;
    int eA[nA] = { 9 };
    alist* a = build(nA, eA);
    const int nB = 7;
    int eB[nB] = { 10, 12, 14, 16, 18, 19, 20 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 9 10 12 14 16 18 19 20 ]
  {
    const int nA = 9;
    int eA[nA] = { 1, 2, 3, 6, 7, 8, 11, 12, 13 };
    alist* a = build(nA, eA);
    const int nB = 3;
    int eB[nB] = { 19, 29, 39};
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 1 2 3 6 7 8 11 12 13 19 29 39 ]
  {
    const int nA = 9;
    int eA[nA] = { 1, 2, 3, 6, 7, 8, 11, 12, 13 };
    alist* a = build(nA, eA);
    const int nB = 6;
    int eB[nB] = { 19, 29, 39, 49, 59, 69 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 1 2 3 6 7 8 11 12 13 19 29 39 49 59 69 ]
  {
    const int nA = 7;
    int eA[nA] = { 11, 13, 15, 17, 21, 23, 25 };
    alist* a = build(nA, eA);
    const int nB = 7;
    int eB[nB] = { 10, 12, 14, 16, 18, 19, 20 };
    const alist* b = build(nB, eB);
    append(a, b);
    print(a);
    destroy(a);
    destroy(b);
  } // -> [ 11 13 15 17 21 23 25 10 12 14 16 18 19 20 ]

  return 0;
}
