/*
Write a C++ class template Pair that provides a way to store two heterogeneous objects as a single unit.

In the definition of the class template, include two data members, let us call them first_ and second_, that can be of different types, and the following member functions:

    a constructor with parameters;
    get_first() and get_second() that return the first_ and the second_ data members, respectively;
    show() that shows the two elements of the pair, inside brackets and separated by a comma; for example: {1,Porto}, or {A,65}, or {2000,366}, depending on the type of elements of the pair; consider that the elements of the pair are either of a simple type (int, double, ...) or a C++-string.

Consider now that you want to store a set of pairs into a vector<Pair<string,int>>, representing different type of data, for example the name and age of a set of persons, the name and grade of a set of students, or the name and population of a set of cities.

Write two functions, external to class Pair, sort_by_first() and sort_by_second(), that can sort the elements of a vector<Pair<string,int>> in non-descending order, taking into account the values of the first_ or the second_ attribute of the pairs, respectively.

    For example, if v is a vector<Pair<string,int>> that represents a set of names and ages of persons, the call sort_by_second(v) should order the elements of v by non-descending age.

Write also the function show(), external to class Pair, that shows on the screen the contents of a vector<Pair<string,int>>. See examples of the output of this function in the public tests.

Hint: the STL algorithm sort can be used to sort the elements of a vector v using the call sort(v.begin(), v.end(), compare_func) where compare_func is a function that, in this case, takes two arguments of type Pair<string,int> and returns true if the first argument is less than the second argument (i.e. it is ordered before).


*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//template class Pair 

template <typename T1, typename T2> 

class Pair {
    public:
    Pair(const T1& first, const T2& second) : first_(first), second_(second) {}

    T1 get_first() const {
        return first_;
    }

    T2 get_second() const {
        return second_;
    }

    void show() const {
        std::cout << '{' << first_ << ',' << second_ << '}';
    }

    private:

    T1 first_;
    T2 second_;

};



void sort_by_first(std::vector<Pair<std::string,int>>& pair) {
    std::sort(pair.begin(),pair.end(), [](Pair<std::string,int> x, Pair<std::string,int> y)-> bool {return x.get_first() < y.get_first(); });

}

void sort_by_second(std::vector<Pair<std::string,int>>& pair) {
    std::sort(pair.begin(),pair.end(), [](Pair<std::string,int> x, Pair<std::string,int> y)-> bool {return x.get_second() < y.get_second(); });
}


void show(const std::vector<Pair<std::string,int>>& pair) {
    
    cout << '{';

    for (const Pair<std::string,int> &p:pair) {
        p.show();
    }

    cout << '}';
}

int main() {
  //public tests (1 point each)
  {
    vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
    sort_by_first(persons);
    show(persons); cout << '\n';
  }  // -> {{Ana,21}{Maria,17}{Pedro,19}}
  {
    vector<Pair<string, int>> persons = { {"Ana",19},{"Rui",16} };
    sort_by_second(persons);
    show(persons); cout << '\n';
  }  // -> {{Rui,16}{Ana,19}}
  {
    vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
    sort_by_first(teams);
    show(teams); cout << '\n';
  } // -> {{Benfica,74}{Porto,91}{Sporting,85}}
  {
    vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
    sort_by_second(teams);  // the worst go first!
    show(teams); cout << '\n';
  } // -> {{Benfica,74}{Sporting,85}{Porto,91}}
  {
    vector<Pair<string, int>> calories = { {"orange",37},{"egg",146},{"apple",56},{"yogurt",51} };
    sort_by_second(calories);
    show(calories); cout << '\n';
  } // -> {{orange,37}{yogurt,51}{apple,56}{egg,146}}
 
  cout << '\n';
  //private tests (1000 points each)
  {
    vector<Pair<string, int>> persons = { {"Rui",17},{"Ana",21},{"Pedro",19}, {"Maria",57} };
    sort_by_first(persons);
    show(persons); cout << '\n';
  } // -> {{Ana,21}{Maria,57}{Pedro,19}{Rui,17}}
  {
    vector<Pair<string, int>> persons = { {"Ana",2000},{"Rui",1000} };
    sort_by_second(persons);
    show(persons); cout << '\n';
  } // -> {{Rui,1000}{Ana,2000}}
  {
    vector<Pair<string, int>> empty = { };
    sort_by_first(empty);
    show(empty); cout << '\n';
  } // -> {}
  {
    vector<Pair<string, int>> teams = { {"Porto",91} };
    sort_by_second(teams);
    show(teams); cout << '\n';
  } // -> {{Porto,91}}
  {
    vector<Pair<string, int>> unknown = { {"a",6},{"b",3},{"c",2},{"d",4},{"e",1},{"f",5} };
    sort_by_second(unknown);
    show(unknown); cout << '\n';
  } // -> {{e,1}{c,2}{b,3}{d,4}{f,5}{a,6}}
 
  return 0;
}