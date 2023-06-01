/*
Consider the code given in Date1.h containing the definition of class Date:

// A simple class Date definition
class Date {
  public:
    Date();                             // Default constructor
    Date(int year, int month, int day); // Constructor with parameters
    int get_year() const;               // Year accessor
    int get_month() const;              // Month accessor
    int get_day() const;                // Day accessor
    void write() const;                 // Writes the date as "yyyy/mm/dd"
  private:
    int year;   // Private attribute year
    int month;  // Private attribute month
    int day;    // Private attribute day
};

Write the C++ code for all member functions not yet implemented:

    The default constructor must build the date 1/1/1;
    For the constructor with parameters, assume that the supplied arguments always define a valid date and that the year value is between 1 and 9999;
    Write also the code of the accessors that return the private attributes of the class.

Finally, write a function (not part of class Date), bool is_before(const Date& date1, const Date& date2) that returns true if date1 is before date2, and false otherwise.


*/

#include <iostream>
#include "Date1.h"
#include <iomanip>
using namespace std;

Date::Date() : year(1), month(1), day(1) {}
Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
  assert (year >= 1 && year <= 9999 && month >= 1 && month <= 12 && day >= 1 && day <= num_days(year,month), "invalid date");
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


bool is_before(const Date& date1, const Date& date2)  {
    if (date1.get_year()< date2.get_year()) return true;
    if (date1.get_year() == date2.get_year() && date1.get_month() < date2.get_month() ) return true;
    if (date1.get_year() == date2.get_year() && date1.get_month() == date2.get_month()  &&date1.get_day() < date2.get_day() ) return true;
    return false;
}


int main() {
  // public tests (1 point each)
  Date d1; d1.write(); cout << '\n';
  // -> 0001/01/01
  Date d2(2020, 2, 29); d2.write(); cout << '\n';
  // > 2020/02/29
  Date d3(1925, 4, 30); d3.write(); cout << '\n';
  // -> 1925/04/30
  Date d4, d5(2022,4,29); d4.write(); cout << '-' << boolalpha << is_before(d4, d5) << '\n';
  // -> 0001/01/01-true
  Date d6(2023,10,31), d7(2022, 4, 29); d6.write(); cout << '-' << boolalpha << is_before(d6, d7) << '\n';
  // -> 2023/10/31-false
 
  cout << '\n';
  // private (1000 points each)
  Date d11(2000, 2, 29); d11.write(); cout << '\n';
  // -> 2000/02/29
  Date d12(1, 2, 28); d12.write(); cout << '\n';
  // -> 0001/02/28
  Date d13(2025, 12, 31); d13.write(); cout << '\n';
  // -> 2025/12/31
  Date d14(1992, 10, 31), d15(1992, 11, 1); d14.write(); cout << '-' << boolalpha << is_before(d14, d15) << '\n';
  // -> 1992/10/31-true
  Date d16(2000, 1, 1), d17(1999, 12, 31); d16.write(); cout << '-' << boolalpha << is_before(d16, d17) << '\n';
  // -> 2000/01/01-false

  return 0;
}

