#include <iostream>
using namespace std;

int main() {
  int x;         // Declares x as a variable of type int
  cin >> x;      // Reads input value for x
  if ( x % 2 == 0 ) { // TODO: this is not the correct condition; fix it!
    cout << x << " is even\n";
  } else {
    cout << x << " is odd\n";
  }
  return 0;
} 

