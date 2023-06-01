/*
A text file contains the name, the address and the phone number of a set of persons (see examples in persons.zip). The name, address and phone may have several words and are written consecutively, in separate lines. So, the data of the first person is written in the first 3 lines of the file, the data of the second person is written in the next 3 lines, and so on.

Consider that you want to develop a program to show the contents of the file, sorted by name. The program must use a class Person, declared in the header file Person.h, to represent a person’s data:

class Person {
public:
  Person(const string& name, const string& address, const string& phone);
  string get_name() const;
  string get_address() const;
  string get_phone() const;
private:
  string name_;    // Name
  string address_; // Address
  string phone_;   // Phone
};

The Person.h header also includes the definition of void show_persons_data(const vector<Person>& persons), an utility function for testing.

You must implement the following functions:

    The member functions of class Person;
    void read_persons_data(const string& file_name, vector<Person>& persons) that reads the contents of a text file, as described above, and stores the persons’ data into a vector<Person> object; you may consider that the file exists and that its contents are in the specified format;
    void sort_persons_by_name(vector<Person>& persons) that sorts the contents of persons by lexicographic order of the name;
    Hint: You may use the sort algorithm from STL.

*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Person.h"

using namespace std;

Person::Person(const string& name, const string& address, const string& phone) : name_(name), address_(address), phone_(phone){}

string Person::get_name() const {
    return name_;
}

string Person::get_address() const {
    return address_;
}

string Person::get_phone() const {
    return phone_;
}

void read_persons_data(const string& file_name, vector<Person>& persons) {
    ifstream infile(file_name);
    string name, adress, phone;

    while(getline(infile, name )) {
        getline(infile,adress);
        getline(infile,phone);
        Person p(name,adress,phone);
        persons.push_back(p);
        }
    
}

bool name(const Person& p1, const Person& p2){
    return (p1.get_name()<p2.get_name());
}

void sort_persons_by_name(vector<Person>& persons) {
    sort(persons.begin(),persons.end(),name);
}

 
int main() {
  // public tests (1 point each)
  {
    vector<Person> persons { 
      Person("Pedro Miguel Faria", "Rua de Santa Catarina, 1234, Porto", "911123456"),
      Person("Maria Roberta Fernandes", "Rua do Santo Silva, 4321, Porto", "987654321") };
    show_persons_data(persons);
  } /* -> 
[
  Pedro Miguel Faria : Rua de Santa Catarina, 1234, Porto : 911123456
  Maria Roberta Fernandes : Rua do Santo Silva, 4321, Porto : 987654321
]
*/
  {
    vector<Person> persons;
    read_persons_data("persons-1.txt", persons);
    show_persons_data(persons);
  } /* -> 
[
  Pedro Miguel Faria : Rua de Santa Catarina, 1235, Porto : 911123456
  Ana Sousa : Avenida da Boavista, 7654, Porto : 987654321
  Rui da Silva Santos : Avenida da Liberdade, 1234, Lisboa : 963111222
]
*/
  {
    vector<Person> persons;
    read_persons_data("persons-1.txt", persons);
    sort_persons_by_name(persons);
    show_persons_data(persons);
  } /* -> 
[
  Ana Sousa : Avenida da Boavista, 7654, Porto : 987654321
  Pedro Miguel Faria : Rua de Santa Catarina, 1235, Porto : 911123456
  Rui da Silva Santos : Avenida da Liberdade, 1234, Lisboa : 963111222
]
*/
  {
    vector<Person> persons;
    read_persons_data("persons-2.txt", persons);
    sort_persons_by_name(persons);
    show_persons_data(persons);
  } /* ->
[
  Ana Sousa : Avenida da Boavista, 7654, Porto : 987654321
  Pedro Miguel Faria : Rua de Santa Catarina, 1235, Porto : 911123456
  Rui da Silva Santos : Avenida da Liberdade, 1234, Lisboa : 963111222
  Sofia Alves Marques de Sousa : Rua da Sofia, 987, Coimbra : 963111222
]
*/ 
cout << endl;
// private tests (1000 points each)
  {
    vector<Person> persons { 
      Person("João Lopes", "Rua de Cedofeita, 123, Porto", "961123456"),
      Person("Maria Fernandes", "Rua do Olival, 432, Coimbra", "927654321") };
    show_persons_data(persons);
  } /* -> 
[
  João Lopes : Rua de Cedofeita, 123, Porto : 961123456
  Maria Fernandes : Rua do Olival, 432, Coimbra : 927654321
]
  */
  {
    vector<Person> persons;
    read_persons_data("persons-3.txt", persons);
    show_persons_data(persons);
  } /* -> 
[
  João Miguel Fernandes : Rua da Boavista, 135, Coimbra : 931234567
  Ana Maria Sousa Lopes : Avenida das Antas, 4654, Lisboa : 967654321
  Rui de Almeida Santos : Avenida da Liberdade, 4050, Porto : 913111222
]
*/
  {
    vector<Person> persons;
    read_persons_data("persons-3.txt", persons);
    sort_persons_by_name(persons);
    show_persons_data(persons);
  } /* -> 
[
  Ana Maria Sousa Lopes : Avenida das Antas, 4654, Lisboa : 967654321
  João Miguel Fernandes : Rua da Boavista, 135, Coimbra : 931234567
  Rui de Almeida Santos : Avenida da Liberdade, 4050, Porto : 913111222
]
*/
  {
    vector<Person> persons;
    read_persons_data("persons-4.txt", persons);
    sort_persons_by_name(persons);
    show_persons_data(persons);
  } /* ->
[
  Ana de Sousa Pinto : Avenida da Boavista, 765, Lisboa : 917654321
  Maria Alves Marques : Rua da Sofia, 9876, Porto : 933111222
  Pedro Miguel Silva : Rua de Santa Maria, 123, Coimbra : 961123456
  Rui Manuel da Silva Santos : Avenida da Liberdade, 1234, Porto : 923111222
]
*/ 
  return 0;
}

