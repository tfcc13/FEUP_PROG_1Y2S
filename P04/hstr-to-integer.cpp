/*
Write a C++ function unsigned long hstr_to_integer(const char hstr[]) that converts a C string formed by the characters that correspond to hexadecimal digits (‘0’ to ‘9’, ‘a’ to ‘f’, or ‘A’ to ‘F’) to the corresponding integer decimal value. Remember that, as usual, C strings are null-terminated. 
*/

#include <iostream>
#include <cmath>
using namespace std;


unsigned long hstr_to_integer(const char hstr[])  {
    int count = 0;
    unsigned long res = 0;
    
    while (hstr[count] != '\0') {
        unsigned long tot ;
        if( hstr[count] >= 'A' && hstr[count] <= 'F') {
                tot = (hstr[count]-'A')+10;
        }
        if ( hstr[count] >= 'a' && hstr[count] <= 'f') {
            tot = (hstr[count]-'a')+10;
        }
        if ( hstr[count] >= '0' && hstr[count] <= '9')
            tot = (hstr[count] -'0');
        count++;
        res = res*16+tot;
    }
    return res;
}

int main()  {
    cout << hstr_to_integer("0") << '\n'; // 0

    cout << hstr_to_integer("A") << '\n'; //10

	


    cout << hstr_to_integer("19") << '\n';//25

	

    cout << hstr_to_integer("fF") << '\n'; // 255

	

cout << hstr_to_integer("CafeBabe2022") << '\n'; //223195403526178

    return 0;
}