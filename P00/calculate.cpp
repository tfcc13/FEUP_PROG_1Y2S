/*Complete the skeleton below for a program that reads an integer value x and writes the value of x and x2−x+1

. As in Python, you may use operators *, + and - for multiplication, addition and subtraction, respectively. Unlike in Python, however, the power operator (**) does not exist in C++.

#include <iostream>
using namespace std;

int main() {
  int x; // Declares x as a variable of type int.
  cin >> x; // Reads input value for x.
  int y = x; // TODO: edit the assignment expression.
  cout << x << ' ' << y << '\n'; // Prints value of x and y.
  return 0;
} */


#include <iostream>
using namespace std;

int main() {
  int x; // Declares x as a variable of type int.
  std::cin >> x; // Reads input value for x.
  int y = x*x -x+1; // TODO: edit the assignment expression.
  std::cout << x << ' ' << y << '\n'; // Prints value of x and y.
  return 0;
} 