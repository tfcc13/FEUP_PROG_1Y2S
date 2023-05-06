//Write a C++ program that, given an integer by user input, computes its reverse (the number with the digits by the reverse order) and prints it.





#include <iostream> 

int main() {
    int n, rev_n=0;

    std::cin>> n;

    while ( n != 0) {
        rev_n = rev_n * 10 + n%10;
        n /= 10;
    }
    std::cout<< rev_n;
    return 0;
}
// public tests (10 points each)
// 123 => 321
// 789 => 987
// 78989 => 98987
// 45654 => 45654 // a palindrome!

// private tests (40 points each)
// 1 => 1
// 66623 => 32666
// 32893474 => 47439823
// 190 => 91
