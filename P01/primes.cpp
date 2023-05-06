/*
Write a C++ program that takes an integer n, provided by the user, and prints all prime numbers up to n.

A prime number (or a prime) is a natural number greater than 1 that can only be divided by 1 or itself [wikipedia]. 
*/

#include <iostream>

bool check_prime(int m) {
    if (m<2) return false;
    for (int j = 2; j < m; j++) {
        if (m % j== 0) {
            return false;
        } 
    }
    return true;   
}


int main() {
    int n;
    std::cin>> n;

    if ( n > 1) {
        for (int i = 0; i <= n;i++) {
            if ( check_prime(i)) {
                std::cout << i << " ";
            }
        }
    }
}

// public tests (10 points each)
// 20 => 2 3 5 7 11 13 17 19
// 19 => 2 3 5 7 11 13 17 19
// 2 => 2
// 1 => 

// private tests (40 points each)
// 25 => 2 3 5 7 11 13 17 19 23
// 45 => 2 3 5 7 11 13 17 19 23 29 31 37 41 43
// 5 => 2 3 5
// 0 =>
