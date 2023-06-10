/*
Consider the classes partially defined in the files Employee.h, SalariedEmployee.h, HourlyEmployee.h, Employee.cpp, SalariedEmployee.cpp, and HourlyEmployee.cpp, given in the ex5.zip:

    Classes SalariedEmployee and HourlyEmployee are derived from class Employee
    A SalariedEmployee receives a fixed monthly amount for payment
    An HourlyEmployee receives an amount that is given by the number of worked hours times a wage rate (payment per hour)
    The program that calculates the payment that each employee receives at the end of the month, uses a vector<Employee*> to store the data about all the employees, both salaried and hourly

Complete the implementation of the classes SalariedEmployee (with code for calculate_net_pay()) and HourlyEmployee and write the code of the following global functions:

    void read_hours_worked(vector<Employee*> &employees) to read hours worked for all HourlyEmployees; this function must scan the employees vector and read from the standard input the hours, as a double, worked by each of the HourlyEmployees stored in the vector (but only for these employees)
    void calculate_pay(vector<Employee*>& employees), to calculate net pay for all employees
    void print_checks(const vector<Employee*>& employees), to print all checks for all employees

*/


#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include <vector>
#include <iostream>


using namespace std;

void SalariedEmployee::calculate_net_pay() {
    double sala = this->get_salary();
    set_net_pay(sala);
    }

void HourlyEmployee::calculate_net_pay() {
    double hours = this->get_hours();
    double money = this->get_rate();

    set_net_pay(hours*money);
}



void read_hours_worked(vector<Employee*> &employees) {
    for (auto& emp : employees) {
        HourlyEmployee* he = dynamic_cast<HourlyEmployee*> (emp) ;

        if (he != nullptr) {
            double hours;
            cin >> hours;
            he ->set_hours(hours);
        }
    }
}


void calculate_pay(vector<Employee*>& employees) {
  for (auto& emp : employees) {
    emp->calculate_net_pay();
  }
}


void print_checks(const vector<Employee*>& employees) {
  cout << "| ";
  for (auto& emp : employees) {
    emp->print_check();
    cout << " | ";
  }
  cout << endl;
}

int main() {
  cout << endl << "inputs?" << endl;
  // public tests (1 point each)
  {
    vector<Employee*> employees = {
      new SalariedEmployee("John", 2000),
      new HourlyEmployee("Mary", 10) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
  } // 100 -> | John:SE(2000.00)=2000.00 | Mary:HE(100.00,10.00)=1000.00 |
  {
    vector<Employee*> employees = {
      new HourlyEmployee("Peter", 10.31),
      new SalariedEmployee("Ann", 1957.4) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
  } // 175.5 -> | Peter:HE(175.50,10.31)=1809.41 | Ann:SE(1957.40)=1957.40 |
  {
    vector<Employee*> employees = {
      new HourlyEmployee("Philip", 10.75),
      new HourlyEmployee("Elisabeth", 9.5),
      new SalariedEmployee("Charles", 5000) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
  } // 200.25 199.75 -> | Philip:HE(200.25,10.75)=2152.69 | Elisabeth:HE(199.75,9.50)=1897.63 | Charles:SE(5000.00)=5000.00 | 
  {
    vector<Employee*> employees = {
      new SalariedEmployee("John", 2123.5),
      new SalariedEmployee("Peter", 1999.9) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
  } // (no input) -> | John:SE(2123.50)=2123.50 | Peter:SE(1999.90)=1999.90 |
  cout << endl;
  // private tests (1000 points each)
  {
    vector<Employee*> employees = {
      new HourlyEmployee("Mary", 10),
      new SalariedEmployee("John", 2000) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
  } // 23 -> | Mary:HE(23.00,10.00)=230.00 | John:SE(2000.00)=2000.00 | 
  {
    vector<Employee*> employees = {
      new SalariedEmployee("Ann", 2975.5),
      new HourlyEmployee("Peter", 15.07) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
  } // 177 -> | Ann:SE(2975.50)=2975.50 | Peter:HE(177.00,15.07)=2667.39 | 
  {
    vector<Employee*> employees = {
      new SalariedEmployee("Ann", 3999.3),
      new SalariedEmployee("Peter", 3950.32) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
  } // (no input) -> | Ann:SE(3999.30)=3999.30 | Peter:SE(3950.32)=3950.32 |
  {
    vector<Employee*> employees = {
      new HourlyEmployee("Peter", 11.23),
      new HourlyEmployee("Philip", 25.7),
      new HourlyEmployee("Charles", 200) };
    read_hours_worked(employees);
    calculate_pay(employees);
    print_checks(employees);
    for (const auto& e : employees) delete e;
  } // 199.5 150.25 1.75 -> | Peter:HE(199.50,11.23)=2240.39 | Philip:HE(150.25,25.70)=3861.42 | Charles:HE(1.75,200.00)=350.00 |

  return 0;
}
