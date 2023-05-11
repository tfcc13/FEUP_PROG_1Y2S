/*
For two complex numbers c1=x1+y1i and c2=x2+y2i we have that c1+c2=(x1+x2)+(y1+y2)i and c1×c2=(x1x2−y1y2)+(x1y2+x2y1)i. Additionally, for a complex number c=x+yi, the Euclidean norm is given by |x|=x2+y2−−−−−−√

.

Consider a type for complex numbers defined by

struct complex {
   double x; // Real part
   double y; // Imaginary part
};

Write three C++ functions for calculating complex number addition, multiplication, and Euclidean norm

void add(const complex& a, const complex& b, complex& r);

void mul(const complex& a, const complex& b, complex& r);

double norm(const complex& c);

In your code you should include header file complex.h (you need to download the file) that contains the declarations of functions above and the complex type, along with support for printing complex values using cout. 
*/

#include <iostream>
#include "complex.h"
#include <cmath>
using namespace std;

void add(const complex& a, const complex& b, complex& r) {

r = {a.x+b.x, a.y+b.y};

}

void mul(const complex& a, const complex& b, complex& r) {

    r = {a.x*b.x-a.y*b.y, a.x*b.y+b.x*a.y};

}

double norm(const complex& c) {

    double res;
    res = sqrt(c.x*c.x+c.y*c.y);
    return res;

}

int main() {
      // public tests (1 point each)
  {
    complex a { 0, 1 }, b { 2, 1}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => 2.000+2.000i -1.000+2.000i 2.828 2.236
  {
    complex a { 1.2, 3.4 }, b { -1.2, 2.3}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => 0.000+5.700i -9.260-1.320i 5.700 9.354
  {
    complex a { -1.5, 1 }, b { -1, 2}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => -2.500+3.000i -0.500-4.000i 3.905 4.031
  {
    complex a { -2, 2 }, b { 2, -2}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => 0.000+0.000i 0.000+8.000i 0.000 8.000
  {
    complex a { 0, 0 }, b { 1.2, -3.4}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => 1.200-3.400i 0.000+0.000i 3.606 0.000
  {
    complex a { 2, 0 }, b { 2.5, -3.1}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => 4.500-3.100i 5.000-6.200i 5.464 7.965
  
  // private tests (1000 points each)
  cout << '\n';
  {
    complex a { 1, 0 }, b { 0, 2}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => 1.000+2.000i 0.000+2.000i 2.236 2.000
  {
    complex a { 3.4, 1.2 }, b { -1.2, 2.3}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => 2.200+3.500i -6.840+6.380i 4.134 9.354
  {
    complex a { -1, 1.5 }, b { 1.2, -2.3}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => 0.200-0.800i 2.250+4.100i 0.825 4.677
  {
    complex a { -3, -3 }, b { -2, -0.2}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => -5.000-3.200i 5.400+6.600i 5.936 8.528
  {
    complex a { 1.0, -0.005 }, b { -1.2, 3.4}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => -0.200+3.395i -1.183+3.406i 3.401 3.606
  {
    complex a { 2.123, 0 }, b { -5.2, 1.3}, s, m;
    add(a, b, s); 
    mul(a, b, m);
    cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n';
  } // => -3.077+1.300i -11.040+2.760i 3.340 11.379
  return 0;
}