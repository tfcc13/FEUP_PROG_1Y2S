#include <iostream>

using namespace std;

char* repeat(const char str[], int n) {
    int count = 0;
    for (int j = 0; str[j] != '\0'; j++) {
        count++;
    }
    int lim = count*n+1;
    char* result = new char[lim];
    
    int count2 = 0;

    while (count2 < lim-1) {
        for (int j = 0; str[j] != '\0'; j++) {
            result[count2] = str[j];
            count2++;
        }
    }

    result[count2]= '\0';

    return result;
}

int main() {

    { const char str[] = "H e l l o";
  char* r = repeat(str, 2);
  cout << "\"" << r << "\"\n";
  delete [] r; }

	

//"H e l l oH e l l o"

{ const char str[] = "C++";
  char* r = repeat(str, 1);
  cout << "\"" << r << "\"\n";
  delete [] r; }

	

//"C++"

{ const char str[] = "";
  char* r = repeat(str, 99);
  cout << "\"" << r << "\"\n";
  delete [] r; }

	

//""

{ const char str[] = "C/C++@LEIC.";
  char* r = repeat(str, 5);
  cout << "\"" << r << "\"\n";
  delete [] r; }

	

//"C/C++@LEIC.C/C++@LEIC.C/C++@LEIC.C/C++@LEIC.C/C++@LEIC."

{ const char str[] = "x";
  char* r = repeat(str, 15);
  cout << "\"" << r << "\"\n";
  delete [] r; }

	

//"xxxxxxxxxxxxxxx"

    return 0;
}