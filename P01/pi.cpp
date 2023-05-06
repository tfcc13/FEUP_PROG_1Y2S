/*The value of Π

can be approximated by the Gregory–Leibniz series:

4∑kn=0(−1)n/(2n+1)

Write a C++ program that given integers k and d prints the k-th approximation with d decimal places. You should make use of a value of type double for the approximation, and customise the print format using std::fixed and std::setprecision defined in header <iomanip>, i.e., for a value x of type double and d digits of precision, print x with d digits using

    std::cout << std::fixed << std::setprecision(d) << x ; 
    
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int d,k;
    double pi;
    std::cin >> k >>d;
    for (int i  = 0; i<=k; i++){
        pi+= std::pow(-1,i)/(2*i+1);
    }
    pi = 4*pi;
    std::cout << std::fixed << std::setprecision(d) << pi;
}

// public tests (1 point each)
// 0 2 => 4.00
// 1 3 => 2.667
// 10 6 => 3.232316
// 100 7 => 3.1514934

// private tests (1000 points each)
// 1000 8 => 3.14259165
// 10000 8 => 3.14169264
// 10000 10 => 3.1416926436
// 2 3 => 3.467
