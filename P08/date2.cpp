/*
Consider the code given in Date2.h containing the definition of class Date :

#include <iostream>
#include <iomanip>
#include <string>

class Date {
  public:
    // constructors
    Date();
    Date(int year, int month, int day);
    Date(const std::string& year_month_day);
    // accessors
    int get_year() const;
    int get_month() const;
    int get_day() const;
    // other methods
    bool is_valid() const; // tests date validity
    void write() const;    // writes the date as "yyyy/mm/dd"
  private:
    // attributes
    int year;
    int month;
    int day;
    // compute the number of days of month
    static int num_days(int year, int month);
};

Write the C++ code for the member functions of the class not yet implemented, observing the following requirements:

    The default constructor must build the date 1/1/1;
    When the parameters of the other constructors constitute an invalid date, the values of the attributes must take the value zero (consider that a date is valid for years between 1 and 9999);
    The parameter of the constructor Date(const std::string& year_month_day) must be in the format: y/m/d, where y, m and d can have a variable number of digits (examples of valid dates: "2022/04/01", "2022/4/13",  "899/1/1"); the separator must always be the character '/';
    The member function is_valid() returns false if one of the attributes is equal to zero.

Hint: use a istringstream object to decompose the string year_month_day. 
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Date2.h"

using namespace std;

Date::Date() : year(1), month(1), day(1) {}

Date::Date(int year, int month, int day) {
      if (year >= 1 && year <= 9999 &&
    month >= 1 && month <= 12 &&
    day >= 1 && day <= num_days(year, month))
  {
    this->year = year;
    this->month = month;
    this->day = day;
  } 
  else {
    this->year = 0;
    this->month = 0;
    this->day = 0;
  }
}

Date::Date(const std::string& year_month_day) {
    int year, month, day;
  char sep1, sep2;
 
  istringstream iss(year_month_day);
  if (iss >> year >> sep1 >> month >> sep2 >> day
    && sep1 == '/' && sep2 == '/'
    && year >= 1 && year <= 9999
    && month >= 1 && month <= 12
    && day >= 1 && day <= num_days(year, month))
  {
    this->year = year;
    this->month = month;
    this->day = day;
  }
  else {
    this->year = 0;
    this->month = 0;
    this->day = 0;
  }

}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

int Date::num_days(int year, int month) {
    int n[12] = {31,28,31,30,31,30,31,31,30,31,30,31} ;
    if (month == 2 && year % 4 == 0 && (year%100 != 0 || year%400 == 0)){
        return 29;
    }
    return n[month-1];
}

bool Date::is_valid() const {
    return year != 0 && month != 0 && day != 0;
}

int main() {
  //public tests
  Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
  // -> 0001/01/01
  Date d2(2022, 4, 31); d2.write(); cout << (d2.is_valid() ? "" : "-invalid") << endl;
  // -> 0000/00/00-invalid
  Date d3("2ooo/2/28"); d3.write(); cout << (d3.is_valid() ? "" : "-invalid") << endl;
  // -> 0000/00/00-invalid
  Date d4("1900/1/1"); d4.write(); cout << (d4.is_valid() ? "" : "-invalid") << endl;
  // -> 1900/01/01
  Date d5("2022#12#31"); d5.write(); cout << (d5.is_valid() ? "" : "-invalid") << endl;
  // -> 0000/00/00-invalid
  cout << '\n';
  //private tests
  Date d11(0, 1, 2); d11.write(); cout << (d11.is_valid() ? "" : "-invalid") << endl;
  // -> 0000/00/00-invalid
  Date d12(2000, 12, 31); d12.write(); cout << (d12.is_valid() ? "" : "-invalid") << endl;
  // -> 2000/12/31
  Date d13("2022/10/9"); d13.write(); cout << (d13.is_valid() ? "" : "-invalid") << endl;
  // -> 2022/10/09
  Date d14("1900/2/29"); d14.write(); cout << (d14.is_valid() ? "" : "-invalid") << endl;
  // -> 0000/00/00-invalid
  Date d15("2022-12/31"); d15.write(); cout << (d15.is_valid() ? "" : "-invalid") << endl; 
  // -> 0000/00/00-invalid

  return 0;
}
