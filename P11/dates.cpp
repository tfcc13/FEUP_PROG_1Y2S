/*
Consider the following interface of a class named Date given in header Date.h:

class Date {
public:
  Date(int year = 1, int month = 1, int day = 1) 
     : year_(year), month_(month), day_(day) {}
  int getYear() const { return year_; }
  int getMonth() const { return month_; }
  int getDay() const { return day_; }
private:
  int year_, month_, day_;
};

Overload the implementation of the operators necessary for sorting and showing on the screen the contents of a vector<Date> dates, using the following statements:

sort(dates.begin(), dates.end());
for (const auto& d : dates) cout << d << endl;

The sorting of the dates must be done in ascending order (older dates come first).

Note: the year, month and day must always be written with 4, 2 and 2 digits, respectively, filling each number with zeros, on the left side, when necessary, and must be separated by ‘/’ (see test examples). 
*/

#include "Date.h"
#include <iostream>
#include <vector>
#include <ostream>
#include <iomanip>
#include <algorithm>

using namespace std;


bool operator<(const Date &d1, const Date &d2) {

    int date1 = d1.getYear()*10000 + d1.getMonth()*100 + d1.getDay();
    int date2 = d2.getYear()*10000 + d2.getMonth()*100 + d2.getDay();  
    return date1 < date2;
}

ostream& operator<<(std::ostream &out,  const Date &date) {
    out << setw(4) << setfill('0') << date.getYear() << '/' << setw(2) << setfill('0') << date.getMonth() << '/' << setw(2) << setfill('0') << date.getDay();
    return out;   
}





int main() {
  // public tests (1 point each) 
  {
    vector<Date> dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 2021/12/08 2023/11/14 2023/11/15
  {
    vector<Date> dates = { {2000,1,1}, {2000,2,1}, {2000,12,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 2000/01/01 2000/02/01 2000/12/31 
  {
    vector<Date> dates = { {2001,10,31}, {2005,10,31}, {2010,10,31}, {1992,10,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 1992/10/31 2001/10/31 2005/10/31 2010/10/31
  {
    vector<Date> dates = { {2023,4,28}, {999,1,1} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 0999/01/01 2023/04/28
  {
    vector<Date> dates = { {2075,2,2}, {2077,10,10}, {2075,2,2}};
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  }  // -> 2075/02/02 2075/02/02 2077/10/10
  cout << '\n';
  // private tests (1000 points each)
  {
    vector<Date> dates = { {2023,4,29}, {2023,4,30}, {2023,4,28} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  }  // -> 2023/04/28 2023/04/29 2023/04/30 
  {
    vector<Date> dates = { {2000,12,1}, {2000,11,1}, {2000,10,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 2000/10/31 2000/11/01 2000/12/01
  {
    vector<Date> dates = { {1970,9,20}, {1969,10,31}, {2099,6,30}, {1975,7,31} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  } // -> 1969/10/31 1970/09/20 1975/07/31 2099/06/30
  {
    vector<Date> dates = { {100,10,2}, {1,1,1}, {1000,1,10} };
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  }  // -> 0001/01/01 0100/10/02 1000/01/10
  {
    vector<Date> dates = { {2030,1,2}, {2029,1,1}};
    sort(dates.begin(), dates.end());
    for (const auto& d : dates) cout << d << " ";
    cout << '\n';
  }  // -> 2029/01/01 2030/01/02
 
  return 0;
}