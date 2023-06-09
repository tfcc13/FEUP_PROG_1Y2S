/*
Consider the partial definitions of classes Page and Book in the files Page.h and Book.h and the partial implementation of the classes in the files Page.cpp and Book.cpp given in the archive ex5.zip.

Write the C++ code of the member function void Book::build_index(const set<string>& words) that builds the index of a book.

    The words to be indexed are received through parameter words
    The index of the book is a map that associates to each word a set containing the numbers of the pages in which the word occurs (see the private data members of class Book)
    If there are no occurrences of some words present in the words parameter they must be omitted from the index
    Each book is saved in a text file, named book_xx.txt where xx takes the values "01", "02", ..."05", available in the given archive; the string <PAGE> marks the end of each page (see the given examples)
    For simplicity, consider that the book does not contain punctuation marks
    The examples used for testing are not real books but just collections of words, organised in pages

You must submit only the code for function Book::build_index.

In your local workspace, to compile a program in a file containing the tests, named for instance main.cpp, you should use the supplied Makefile and execute the following command in the Terminal:

make PROG=books CPP_FILES="Page.cpp Book.cpp books.cpp" HEADERS="Page.h Book.h"
*/

#include "Book.h"
#include "Page.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>



using namespace std;

void Book::build_index(const std::set<std::string> &words) {
    index_.clear();

    for (size_t page_num = 0; page_num < book_.size(); page_num++){
        Page& page = book_[page_num];
        set<string> page_unic_word;

        for (size_t line_num = 0; line_num < page.get_num_lines(); line_num++) {

            const string& lines = page.get_line(line_num);

            istringstream iss(lines);

            string word;

            while(iss>>word) {
                if(words.count(word)) {
                    page_unic_word.insert(word);
                }
            }

        }

        for (const string& word : page_unic_word) {
            index_[word].insert(page_num+1);
        }



    }
}


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