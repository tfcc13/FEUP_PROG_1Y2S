/*
Write a C++ program that reads an integer number n by user input followed by n characters, all separated by spaces, and then prints the number of characters read that are letters, the number of characters read that are digits, and the number of characters read that are not letters or digits.

Hints:

    Spaces are filtered automatically when reading through std::cin
    Use the int type to represent n and the char type to represent characters;
    Use character constants: a value c of type char is a digit if its (integer) value is in the range between '0' and '9', and a letter if its value is in the ranges between 'a' and 'z' or 'A' and 'Z'.

*/

#include <iostream>

int main() {
    int n, char_count = 0, digit_count = 0, others_count = 0;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char x;
        std::cin >> x;

        if  ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) {
            char_count++;
        }

        else if  ((x >= '0' && x <= '9')) {
            digit_count++;
        }

        else {
            others_count++;
        }
    }

    std::cout << char_count << ' ' << digit_count << ' ' << others_count;
    return 0;
}       

/*
tests

1 a

	

1 0 0

11 2 0 2 3 , F e b . 1 3

	

3 6 2

11 P r o g 2 0 2 3 C + +

	

5 4 2

10 0 1 2 3 4 5 6 7 8 9

	

0 10 0

6 a H z A h Z

	

6 0 0

*/