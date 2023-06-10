/*
Consider the definition of class Person given in header Person.h:

class Person {
public:
  Person(int id, const string& name)
    : id_(id), name_(name) { }
  int id() const { return id_; }
  const string& name() const { return name_; }
  virtual string to_string() const {
    ostringstream out;
    out << id_ << '/' << name_;
    return out.str();
  }
private:
  int id_;
  string name_;
};

As illustrated by the constructor and accessor functions, a Person object represents the identifier and the name of a person. In addition, to_string() returns a string representation for a Person object, where person attributes in text form are separated by the / character.

Write two classes, Student and ErasmusStudent, with the following requirements.

Student must extend Person, and define an attribute for the course in which a student is enrolled. The class must have the following functions defined:

    Student(int id, const string& name, const string& course): the constructor;
    const string& course() const: an accessor function for the course information; and
    string to_string() const: overrides Person::to_string(), and returns a string in which the course information is appended to the person information (see the test cases for illustrative examples).

ErasmusStudent must extend Student, and define an attribute for the country of origin for the student. The class must have the following functions defined:

    ErasmusStudent(int id, const string& name, const string& course, const string& country): the constructor:
    const string& country() const: an accessor function for the country information; and
    string to_string() const: overrides Student::to_string(), and returns a string in which the country information is appended to the student information.

*/


#include "Person.h"
#include <iostream>

using namespace std;


class Student : public Person {
    public:

    Student(int id, const string& name, const string& course) : Person(id,name), course_(course) {}
    const string& course() const {
        return course_;
    }
    virtual std::string to_string() const {
        return Person::to_string() + '/' + course_;
    }

    private:
    std::string course_;


};

class ErasmusStudent : public Student {
    public:

    ErasmusStudent(int id, const string& name, const string& course, const string& country) : Student(id, name, course), country_(country) {}
    
    const string& country() const {
        return country_;
    }
    virtual std::string to_string() {
        return Student::to_string() + '/' + country_;
    }


    private:

    std::string country_;
};


int main() {
  // public tests (1 points each) 
  {
     const Person& p = Student(123, "Manuel Dias", "LEIC");
     cout << p.id() << ' ' << p.name() << '\n';
  } // -> 123 Manuel Dias
  {
     const Student& s = ErasmusStudent(124, "John Zorn", "LXPTO", "United States");
     cout << s.id() << ' ' << s.name() << ' ' << s.course() << '\n';
  } // -> 124 John Zorn LXPTO
  {
     Student s(123, "Manuel Dias", "LEIC");
     cout << s.id() << ' ' << s.name() << ' '  << s.course() << '\n';
  } // -> 123 Manuel Dias LEIC
  {
     ErasmusStudent es(124, "John Zorn", "LXPTO", "United States");
     cout << es.id() << ' ' << es.name() << ' ' << es.course() << ' ' << es.country() << '\n';
  } // -> 124 John Zorn LXPTO United States
  {
     Person p(125, "Marie Curie");
     Student s(126, "Ada Lovelace", "LEIC");
     ErasmusStudent es(127, "Grace Hopper", "LXPTO", "United States");
     cout << p.to_string() << ' ' << s.to_string() << ' ' << es.to_string() << '\n';
  } // -> 125/Marie Curie 126/Ada Lovelace/LEIC 127/Grace Hopper/LXPTO/United States
  cout << '\n';
  // private tests (1000 points each)
  {
     const Person& p = Student(999, "Arnaldo Vespa", "LB");
     cout << p.id() << ' ' << p.name() << '\n';
  } // -> 999 Arnaldo Vespa
  {
     const Student& s = ErasmusStudent(1234, "Astor Piazzolla", "LTango", "Argentina");
     cout << s.id() << ' ' << s.name() << ' ' << s.course() << '\n';
  } // -> 1234 Astor Piazzolla LTango
  {
     Student s(999, "Arnaldo Vespa", "LB");
     cout << s.id() << ' ' << s.name() << ' '  << s.course() << '\n';
  } // -> 999 Arnaldo Vespa LB
  {
     ErasmusStudent es(1234, "Astor Piazzolla", "LTango", "Argentina");
     cout << es.id() << ' ' << es.name() << ' ' << es.course() << ' ' << es.country() << '\n';
  } // -> 1234 Astor Piazzolla LTango Argentina
  {
     Person p(125, "Albert Einstein");
     Student s(126, "Roger Moore", "L007");
     ErasmusStudent es(127, "Alan Turing", "LCC", "United Kingdom");
     cout << p.to_string() << ' ' << s.to_string() << ' ' << es.to_string() << '\n';
  } // -> 125/Albert Einstein 126/Roger Moore/L007 127/Alan Turing/LCC/United Kingdom

  return 0;

}