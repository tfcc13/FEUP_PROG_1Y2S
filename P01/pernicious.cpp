/*In number theory, a pernicious number is a positive integer that has a prime number of 1s in their binary representation. We are interested in numbers that are both prime and pernicious. For instance 7=1112 is both prime and pernicious, 6=1102 is pernicious but not prime, and 23=101112

is prime but not pernicious.

Write a C++ program that prints the value of all numbers between a and b that are both pernicious and prime, where a and b are positive integers supplied as input. 
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

bool is_pernicious(int n) {
    int count = 0;

    while (n != 0) {
        count += n %2;

        n /= 2;
    }
    return check_prime(count);
}

int main() {
    int a,b;

    std::cin >> a >> b;

    for (int i = a; i <= b; i++) {
        if (check_prime(i) && is_pernicious(i)) {
            std::cout << i << ' ';
        }

    }
    return 0;
}


// public tests (1 point each)
// 10 50 => 11 13 17 19 31 37 41 47
// 11 47 => 11 13 17 19 31 37 41 47
// 1 11 => 3 5 7 11
// 23 83 => 31 37 41 47 59 61 67 73 79

// private tests (1000 points each)
// 20 30 => 
// 85 99 => 97
// 123 234 => 127 131 137 151 157 167 173 179 181 191 193 199 211 223 227 229 233
// 1 15 => 3 5 7 11 13
