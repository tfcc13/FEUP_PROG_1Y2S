#include <iostream>
#include "complex.h"


 complex  csum(complex x, complex y) {
    complex z;
    z.img = x.img+y.img;
    z.real = x.real+y.real;
    return z;
 }


complex  cmul(complex x, complex y) {
    complex z;
    z.img = x.real*y.img+y.real*x.img;
    z.real = x.real*y.real-y.img*x.img;
    return z;
 }
 
 void mandel(complex c, int n, complex z[]) {
    z[0].real = 0;
    z[0].img = 0;

    for (int i = 1; i < n; i++) {
        z[i] = csum(cmul(z[i-1],z[i-1]),c);
    }
 }



int main() {
    { complex c = { 0, 0 };
  const int n = 1;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }

	

//[ 0 ]

{ complex c = { 0, 0 };
  const int n = 3;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }

	

//[ 0 0 0 ]

{ complex c = { 1, 1 };
  const int n = 3;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }

	

//[ 0 1+1i 1+3i ]

{ complex c = { -1, 0 };
  const int n = 6;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }

	

//[ 0 -1 0 -1 0 -1 ]

{ complex c = { 0, 3 };
  const int n = 5;
  complex z[n];
  mandel(c, n, z);
  print(z, n); }

	

//[ 0 +3i -9+3i 72-51i 2583-7341i ]

    return 0;
}