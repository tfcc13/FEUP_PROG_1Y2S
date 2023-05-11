/*
A quadratic equation of the form ax2+bx+c=0 in the domain of real numbers is known to have 0, 1, or 2 solutions according to the value of Δ=b2−4ac

:

    no solutions if Δ<0

1 solution x1=−b2a
if Δ=0
2 solutions x1=−b−Δ−−√2a
and x2=−b+Δ−−√2a when Δ>0

Write a C++ function to solve the quadratic equation for the case where a
, b, c are integer coefficients, with a≠0

:

int solve_eq(int a, int b, int c, double& x1, double& x2)

The function should return the number of solutions for the equation (0, 1, or 2) and, in the case there are solutions, assign the corresponding values to x1 and x2 as described above. x1 and x2 should be set to NAN defined in header cmath when there are no corresponding solutions (x2 = NAN when Δ=0
; and x1 = x2 = NAN when Δ<0

).

To perform the square root computation, you should use the function std::sqrt, defined in header cmath.

Note: the test cases illustrate solutions with a precision of 7 decimal digits. 

*/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int solve_eq(int a, int b, int c, double& x1, double& x2) {

    int delta;
    delta = b*b -4*a*c;
    if (delta == 0) {
        x1 = -b/(2.0*a);  // usa-se 2.0 para o compilador assumir um float e fazer operações com floar
        x2= NAN;            // caso contrario ao usar um inteiro truncaria o numero
        return 1;
    }
    else if (delta > 0) {
        x1 = (-b-sqrt(delta))/(2.0*a);
        x2 = (-b+sqrt(delta))/(2.0*a);
        return 2;
    }
    else {
        x1 = NAN;
        x2 = NAN;
        return 0;
    }
}

int main(){

      // public tests (1 points each)
  {
    double x1, x2; 
    int r = solve_eq(1, 1, 0, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 2 -1.0000000 0.0000000
  {
    double x1, x2; 
    int r = solve_eq(1, -2, 1, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 1 1.0000000 nan
  {
    double x1, x2; 
    int r = solve_eq(1, 1, 1, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 0 nan nan
  { 
    double x1, x2; 
    int r = solve_eq(1, -1, 0, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 2 0.0000000 1.0000000
  {
    double x1, x2; 
    int r = solve_eq(3, 4, -2, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 2 -1.7207592 0.3874259

  // private test(s (1000 points each)
  cout << '\n';
  { 
    double x1, x2; 
    int r = solve_eq(2, -2, 3, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 0 nan nan
  { 
    double x1, x2; 
    int r = solve_eq(2, -16, 32, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 1 4.0000000 nan
  {
    double x1, x2; 
    int r = solve_eq(1, 0, 0, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 1 0.0000000 nan
  {  
    double x1, x2; 
    int r = solve_eq(-9, 6, -1, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 1 0.3333333 nan
  {
    double x1, x2; 
    int r = solve_eq(17, 0, -1, x1, x2); 
    cout << fixed << setprecision(7) 
         << r << ' ' << x1 << ' ' << x2 << '\n'; 
  } // => 2 -0.2425356 0.2425356

  return 0;

}