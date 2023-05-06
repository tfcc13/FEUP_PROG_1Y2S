/*Complete the skeleton below for a program that reads two integers a and b and prints all numbers between a and b

. All you need to do is change the for loop instruction.

#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  // TODO: change initial value of i and fix test condition
  for (int i = 0; i <= 10; i++) {
    cout << i << ' ';
  }
  return 0;
} */


#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  // TODO: change initial value of i and fix test condition
  for (int i = a; i <= b; i++) {
    cout << i << ' ';
  }
  return 0;
} 