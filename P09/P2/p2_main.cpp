/*
Consider the classes Date and Person whose declarations are given in Date.h and Person.h.

In the file named p2_main.cpp, write a C++ function that takes as input parameters a list of Person objects stored into a vector and a Date object, and shows on the screen the name and birthdate of all the persons that were born before the given date. The signature of the function is:

void born_before(const vector<Person>& persons, const Date& date)

Download the class declarations Date.h and Person.h and implement the code of the classes using the separate compilation principle, that is, with the definition of each class in a .h file and the implementation of its member functions in a corresponding .cpp file.

In your local workspace, to compile a program in a file named p2_main.cpp, you should use the supplied Makefile and execute the following command in the terminal:

make PROG=p2_main CPP_FILES="Date.cpp Person.cpp p2_main.cpp" HEADERS="Date.h Person.h"

You must submit three files: Date.cpp, Person.cpp and p2_main.cpp. 
*/

#include <iostream>
#include <vector>
#include "Date.h"
#include "Person.h"

using namespace std;

void born_before(const vector<Person>& persons, const Date& date) {
    date.show();
    cout << ": ";

    for (const Person &p : persons) {
        if(p.get_birth_date().is_before(date)) {
            p.show();
            cout << ' ';
        }
    }

    cout << '\n';
}

int main() {
  // public tests (1 point each)
  born_before({ {"Ana",{2000,4,5}}, {"Rui",{1999,5,11}}, {"Susana",{1999,5,13}}, {"Pedro",{2010,2,10}} }, {2000,1,1});
  // -> 2000/1/1: Rui-1999/5/11 Susana-1999/5/13 
  born_before({ {"Rui",{2009,4,9}}, {"Susana",{1997,6,19}}, {"Pedro",{2018,3,10}} }, {2019,12,31});
  // -> 2019/12/31: Rui-2009/4/9 Susana-1997/6/19 Pedro-2018/3/10 
  born_before({ {"Ana",{1999,5,12}}, {"Rui",{1960,3,21}}, {"Susana",{1999,7,25}}, {"Pedro",{1999,7,31}} }, {1970,1,1});
  // -> 1970/1/1: Rui-1960/3/21 
  born_before({ {"Ana",{2001,7,15}}, {"Susana",{2019,8,12}}, {"Pedro",{2000,5,8}} }, {2001,1,1});
  // -> 2001/1/1: Pedro-2000/5/8 
  born_before({ {"Pedro",{2000,11,7}} }, {2001,1,1});
  // -> 2001/1/1: Pedro-2000/11/7 
  
  cout << '\n';
  // private tests (1000 points each)
  born_before({ }, {2000,1,1});
  // -> 2000/1/1: 
  born_before({ {"Rui",{2000,4,5}}, {"Ana",{1999,5,11}}, {"Susana",{1999,5,13}}, {"Pedro",{2010,2,10}} }, {2020,1,1});
  // -> 2020/1/1: Rui-2000/4/5 Ana-1999/5/11 Susana-1999/5/13 Pedro-2010/2/10
  born_before({ {"Pedro",{1997,6,19}}, {"Susana",{2018,3,10}} }, {2010,12,31});
  // -> 2010/12/31: Pedro-1997/6/19
  born_before({ {"Susana",{1999,7,30}}, {"Rui",{1960,3,21}}, {"Ana",{1999,10,30}} }, {2000,1,1});
  // -> 2000/1/1: Susana-1999/7/30 Rui-1960/3/21 Ana-1999/10/30 
  born_before({ {"Susana",{2001,7,15}}, {"Pedro",{2009,2,18}}, {"Ana",{2019,8,12}}, {"Rui",{2000,5,8}} }, { 2009,12,31});
  // -> 2009/12/31: Susana-2001/7/15 Pedro-2009/2/18 Rui-2000/5/8

  return 0;
}