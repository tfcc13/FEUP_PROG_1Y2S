/*
The Mandelbrot set recurrence z0,z1,z2,... of complex numbers is defined for a complex constant c

by:

z0=0zn=zn−1×zn−1+c∀n>0

Consider again the complex type defined in header complex.h and use the functions you defined in the previous exercise to write a C++ function

void mandelbrot(const complex& c, unsigned int n, complex& z_n)

such that a call to mandelbrot(c, n, z_n) yields in z_n the n-th element of the Mandelbrot set recurrence for c. 
*/

#include <iostream>
#include "complex.h"
using namespace std;

void add(const complex& a, const complex& b, complex& r) {

r = {a.x+b.x, a.y+b.y};

}

void mul(const complex& a, const complex& b, complex& r) {

    r = {a.x*b.x-a.y*b.y, a.x*b.y+b.x*a.y};

}


void mandelbrot(const complex& c, unsigned int n, complex& z_n) {
    z_n = {0,0};
    if (n == 0) return;

    complex tmp = {0,0};

    for (unsigned int i = 1; i <= n; i++) {
        mul(tmp,tmp,z_n);
        add(z_n,c,z_n);
        tmp = {z_n.x,z_n.y};
    }
}

int main() {
      // public tests (1 point each)
  {
    complex z_n;
    mandelbrot({1.2, 3.4}, 0, z_n);
    cout << z_n << '\n';
  } // -> 0.000+0.000i
  {
    complex z_n;
    mandelbrot({1, 1}, 1, z_n);
    cout << z_n << '\n';
  } // => 1.000+1.000i
  {
    complex z_n;
    mandelbrot({1, 1}, 2, z_n);
    cout << z_n << '\n';
  } // => 1.000+3.000i
  {
    complex z_n;
    mandelbrot({-1.2, 0.4}, 7, z_n);
    cout << z_n << '\n';
  } // => -0.624-2.499i
  {
    complex z_n;
    mandelbrot({0.1, 3.2}, 4, z_n);
    cout << z_n << '\n';
  } // => 2174.128-13121.836i
  {
    complex z_n;
    mandelbrot({-1, 0}, 11, z_n);
    cout << z_n << '\n';
  } // -> -1.000+0.000i

  // private tests (1000 points each)
  cout << '\n';
  {
    complex z_n;
    mandelbrot({1,0}, 5, z_n);
    cout << z_n << '\n';
  } // -> 677.000+0.000i
  {
    complex z_n;
    mandelbrot({-2, 1}, 4, z_n);
    cout << z_n << '\n';
  } // => 73.000+101.000i
  {
    complex z_n;
    mandelbrot({ 1, -3 }, 4, z_n);
    cout << z_n << '\n';
  } // => -14167-7629i
  {
    complex z_n;
    mandelbrot({-3, 3}, 4, z_n);
    cout << z_n << '\n';
  } // -> 39309.000-40731.000i
  {
    complex z_n;
    mandelbrot({0.1, 0.15}, 10, z_n);
    cout << z_n << '\n';
  } // => 0.074+0.176i
  {
    complex z_n;
    mandelbrot({0.9, -0.4}, 5, z_n);
    cout << z_n << '\n';
  } // => -165.540+321.482i

  return 0;

}