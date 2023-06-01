/*
Write the C++ code for the Student class that represents a student in the Bachelor in Informatics and Computing Engineering, with the definition given in the Student.h header file.

struct course {
  std::string name;  // "ALGA", "AMI", "FSC", "MD", ...
  float credits;     // 1.5, 4.5, 6
  short grade;       // 0..20
};

class Student {
public:
  // constructor with parameters
  Student(const std::string& id);
  // accessor
  std::string get_id() const;
  // member functions
  void add(const course& c);  // add a course grade
  double avg() const;         // calculate the average grade
private:
  std::string id_;
  std::vector<course> courses_;
};

Note that the avg function must return the weighted average grade calculated by multiplying the grades by their corresponding credits and taking its sum:
∑ni=1crediti∗gradei∑ni=1crediti

You can assume that only courses with passing grades (grade>=10) are added. 
*/

#include <iostream>
#include <string>
#include "Student.h"
#include <iomanip>
#include <cmath>
using namespace std;

Student::Student(const std::string& id) : id_(id) {}

std::string Student::get_id() const {
    return id_;
}

void Student::add(const course& c) {
    if (c.grade >= 10) courses_.push_back(c);
}

double Student::avg() const {
    double sum = 0;
    double count = 0;
    for (auto i = courses_.begin(); i !=  courses_.end(); i++) {
        sum += i->grade*i->credits;
        count+= i->credits;
    }
    return isnan(sum/count) ? 0 : sum/count;
}

int main() {
  cout << endl;
  // -> public testes (1 point each)
  {
    Student s("up2022001111");
    s.add({"FP", 6, 20});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
  } // -> [up2022001111]/20.00
  {
    Student s("up2022002222");
    s.add({"MD", 6, 18}); s.add({"AMI", 6, 16}); s.add({"FSC", 6, 14});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
  } // -> [up2022002222]/16.00
  {
    Student s("up2022003333");
    s.add({"ALGA", 4.5, 18}); s.add({"AMI", 6, 16}); s.add({"PUP", 1.5, 14});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
  } // -> [up2022003333]/16.50
  {
    Student s("up2022004444");
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
  } // -> [up2022004444]/0.00

  cout << endl;
  // -> private testes (1000 points each)
  {
    Student s("up2022005555");
    s.add({"MD", 6, 10}); s.add({"FP", 6, 20}); s.add({"PUP", 1.5, 18});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
  } // -> [up2022005555]/15.33
  {
    Student s("up2022006666");
    s.add({"ALGA", 4.5, 10}); s.add({"FP", 6, 20}); s.add({"MD", 6, 12});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
  } // -> [up2022006666]/14.36
  {
    Student s("up2022007777");
    s.add({"FSC", 6, 10}); s.add({"FP", 6, 20}); s.add({"PUP", 1.5, 12}); s.add({"MD", 6, 12});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
  } // -> [up2022007777]/13.85
  {
    Student s("up2022008888");
    s.add({"ALGA", 4.5, 10}); s.add({"AMI", 6, 16}); s.add({"FSC", 6, 16}); 
    s.add({"MD", 4.5, 10}); s.add({"FP", 6, 20}); s.add({"PUP", 1.5, 18});
    cout << "[" << s.get_id() << "]/";
    cout << fixed << setprecision(2) << s.avg() << endl;
  } // -> [up2022008888]/15.05

  return 0;
}