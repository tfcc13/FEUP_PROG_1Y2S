#include <iostream>
#include "Book.h"
#include "Page.h"

using namespace std;



// driver code with the tests
int main() {
  cout << endl;
  // public tests (1 point each)
  {
    Book b;
    if (!(b.import("book_01.txt"))) cout << "book not found! \n";
    set<string> words = { "C++", "linux", "computer" };
    b.build_index(words);
    b.show_index();
  } // -> / C++: 1 / linux: 1 / 
  {
    Book b;
    if (!(b.import("book_02.txt"))) cout << "book not found! \n";
    set<string> words = { "C++", "program", "computer", "windows" };
    b.build_index(words);
    b.show_index();
  } // -> / C++: 1 2 3 / computer: 3 / program: 1 / windows: 1 3 / 
  {
    Book b;
    if (!(b.import("book_03.txt"))) cout << "book not found! \n";
    set<string> words = { "linux", "program", "cpu" };
    b.build_index(words);
    b.show_index();
  } // -> / cpu: 1 / linux: 2 / program: 2 / 
  {
    Book b;
    if (!(b.import("book_04.txt"))) cout << "book not found! \n";
    set<string> words = { "computer", "program", "file","windows" };
    b.build_index(words);
    b.show_index();
  } // -> / computer: 1 / file: 3 / program: 1 3 / windows: 3 /
  {
    Book b;
    if (!(b.import("book_05.txt"))) cout << "book not found! \n";
    set<string> words = { "linux", "byte", "cpu" };
    b.build_index(words);
    b.show_index();
  } // -> / byte: 1 2 / cpu: 1 /

  cout << endl;
  // private tests (1000 points each)
  {
    Book b;
    if (!(b.import("book_06.txt"))) cout << "book not found! \n";
    set<string> words = { "C++", "program" };
    b.build_index(words);
    b.show_index();
  } // -> / C++: 2 / program: 1 2 / 
  {
    Book b;
    if (!(b.import("book_07.txt"))) cout << "book not found! \n";
    set<string> words = { "C++", "linux", "program" };
    b.build_index(words);
    b.show_index();
  } // -> / C++: 1 2 3 / linux: 1 2 3 / program: 2 3 / 
  {
    Book b;
    if (!(b.import("book_08.txt"))) cout << "book not found! \n";
    set<string> words = { "disk", "file" };
    b.build_index(words);
    b.show_index();
  } // -> / disk: 1 2 / file: 1 2 /
  {
    Book b;
    if (!(b.import("book_09.txt"))) cout << "book not found! \n";
    set<string> words = { "windows", "program" };
    b.build_index(words);
    b.show_index();
  } // -> / program: 1 / windows: 1 /
  {
    Book b;
    if (!(b.import("book_10.txt"))) cout << "book not found! \n";
    set<string> words = { "cpu", "byte", "disk", "file" };
    b.build_index(words);
    b.show_index();
  } // -> / byte: 1 / cpu: 1 / disk: 2 / file: 2 / 
 
  return 0;
}