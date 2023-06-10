/*
Write the C++ code for the Student class that represents a student in the Programming course, with the definition given in the Student.h header file.

class Student {
public:
  // constructor
  Student(const std::string& name, const std::string& id, 
          short ac, short p1, short p2);
  // accessors
  std::string get_id() const;
  std::string get_name() const;
  double actual_grade() const; // [0..20]
private:
  std::string name_;
  std::string id_;
  short ac_, p1_, p2_; // [0..20]
};

The course has three assessment components: continuous assessment (ac), minitest 1 (p1) and minitest 2 (p2) and the final grade is obtained using the formula: 10% ac + 45% p1 + 45% p2. 
*/



#include <iostream>
#include <string>
#include "Student.h"
#include <iomanip>

using namespace std;



Student::Student(const std::string& name, const std::string& id, short ac, short p1, short p2) : name_(name), id_(id), ac_(ac), p1_(p1), p2_(p2) {}


std::string Student::get_id() const {
  return id_;
}



std::string  Student::get_name() const {
  return name_;
}

double Student::actual_grade() const { // [0..20]
  return 0.1*ac_+0.45*p1_+0.45*p2_;
}

int main () {
  
  { Student s("Andre Meira", "up201404877", 20, 18, 10);
  cout << "[" << s.get_id() << "]" << "/";
  cout << fixed << setprecision(2) << s.actual_grade() << endl; }

	

//[up201404877]/14.60

{ Student s("John Doe", "up19790007", 20, 20, 20);
  cout << "[" << s.get_id() << "]" << "/";
  cout << fixed << setprecision(2) << s.actual_grade() << endl; }

	

//[up19790007]/20.00

{ Student s("Graham Chapman", "up19790077", 10, 10, 10);
  cout << "[" << s.get_id() << "]" << "/";
  cout << fixed << setprecision(2) << s.actual_grade() << endl; }

	

//[up19790077]/10.00

{ Student s("John Cleese", "up19790077", 8, 7, 13);
  cout << "[" << s.get_id() << "]" << "/";
  cout << fixed << setprecision(2) << s.actual_grade() << endl; }

	

//[up19790077]/9.80

  return 0;
}