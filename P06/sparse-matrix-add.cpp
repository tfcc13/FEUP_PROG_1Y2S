/*
A sparse matrix is a matrix where most elements have value 0. For space efficiency, data structures for sparse matrices only encode non-zero values.

Consider the following definition for a smatrix type, defined in smatrix.h (download), where sparse matrices are represented by a vector of type sm_entry:

struct sm_entry {
  size_t row;  // Matrix row
  size_t col;  // Matrix column
  int value;   // Value (non-zero)
};
typedef vector<sm_entry> smatrix;

Write a C++ function void sum(const smatrix& a, const smatrix& b, smatrix& r) such that a call to sum(a, b, r) places in r the result of adding the sparse matrices represented by a and b.

You should consider that entries in a and b are ordered by row first and then by column, and ensure the same type of ordering in r.

The provided tests use an utility function called print for printing sparse matrices, also defined in  smatrix.h. 

*/

#include<iostream>
#include <vector>
#include "smatrix.h"
using namespace std;

bool check_order( const sm_entry& a, const sm_entry& b) {
    if (a.row < b.row || (a.row == b.row && a.col < b.col)) return true;
    return false;
}

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    size_t count_a = 0, count_b = 0;

    while ( count_a < a.size() && count_b < b.size()) {
        if (check_order(a[count_a],b[count_b])) {
            r.push_back(a[count_a]);

            count_a++;
        }
        else {
            if (a[count_a].row == b[count_b].row &&a[count_a].col == b[count_b].col) {
                sm_entry tmp = {a[count_a].row, a[count_a].col, (a[count_a].value + b[count_b].value)};
                if (tmp.value != 0) r.push_back(tmp);
                count_a++;
                count_b++;
            }
            else {
             r.push_back(b[count_b]);
             count_b++;
            }

        }

    }

    while ( count_a < a.size()) {
        r.push_back(a[count_a]);
        count_a++;
    }

     while ( count_b < b.size()) {
        r.push_back(b[count_b]);
        count_b++;
    }
}


int main() {
      // public tests (1 point each)
  {
    smatrix r;
    sum({ },
        { {0, 3, 1}, {0, 50, 1} },
        r);
    print(r);
  } // -> [ (0, 3, 1) (0, 50, 1) ]
  {
    smatrix r;
    sum({ {0, 0, 1}, {1, 0, 1} },
        { {0, 3, 1}, {0, 50, 1} },
        r);
    print(r);
  } // -> [ (0, 0, 1) (0, 3, 1) (0, 50, 1) (1, 0, 1) ]
  {
    smatrix r;
    sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {99, 12, 32} },
        { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
        r);
    print(r);
  } // -> [ (0, 0, 2) (5, 10, 20) (10, 5, 20) (99, 10, 30) (99, 11, 31) (99, 12, 32) ]
  {
    smatrix r;
    sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
        { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
        r);
    print(r);
  } // -> [ (5, 10, 20) ]
  {
    smatrix r;
    sum({ {0, 0, -1}, {0, 1, 2},  {5, 10, 20 }, {10, 5, -20} },
        { {0, 0, 1}, {0, 1, -2},  {5, 10, -20}, {10, 5, 20} },
        r);
    print(r);
  } // -> [ ]

  cout << endl;
  // private tests (1000 point each)
  {
    smatrix r;
    sum({ {0, 3, 1}, {0, 50, 1} },
        { },
        r);
    print(r);
  } // -> [ (0, 3, 1) (0, 50, 1) ]
  {
    smatrix r;
    sum({ {0, 0, 1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20}, {99, 12, 32} },
        { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31} },
        r);
    print(r);
  } // -> [ (0, 0, 2) (5, 10, 20) (99, 10, 30) (99, 11, 31) (99, 12, 32) ]
  {
    smatrix r;
    sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20}, {13, 3, 19}, {21, 4, 12} },
        { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {99, 10, 30}, {99, 11, 31}, {99, 12, 31} },
        r);
    print(r);
  } // -> [ (5, 10, 20) (13, 3, 19) (21, 4, 12) (99, 10, 30) (99, 11, 31) (99, 12, 31) ]
  {
    smatrix r;
    sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20}, {13, 3, 19}, {21, 4, 12}, {99, 12, -31} },
        { {0, 0, 1}, {0, 1, -2}, {10, 5, 20}, {13, 3, -19}, {21, 4, -12}, {99, 12, 31} },
        r);
    print(r);
  } // -> [ (5, 10, 20) ]
  {
    smatrix r;
    sum({ {0, 0, -1}, {0, 1, 2}, {1, 0, 20}, {1, 1, -20}, {2, 0, -23}, {2, 1, 54}, {10, 5, -20} },
        { {0, 0, 1}, {0, 1, -2}, {1, 0, -20}, {1, 1, 20}, {2, 0, 23}, {2, 1, -54}, {10, 5, 20} },
        r);
    print(r);
  } // -> [ ]

  return 0;
}