/*
Consider the following interface of a class named Point given in header Point.h:

class Point {
public:
  Point(); // builds (0,0)
  Point(int x, int y); // builds (x,y)
  Point(const Point& p); // copy constructor
  int get_x() const; // get x coordinate
  int get_y() const; // get y coordinate
  Point& operator=(const Point& p); // assignment operator
  Point operator+(const Point& p) const; // sum
  Point& operator+=(const Point& p); // composed assignment and sum
  Point operator*(int v) const; // "right" multiplication by scalar
private:
  int x_, y_;
};

Point operator*(int x, const Point& p); // "left" multiplication by scalar
std::ostream& operator<<(std::ostream& os, const Point& p);

Provide an implementation of all functions, including those related to operator overloading. For an output stream os, points a and b, and an int value v:

    os << a should output to os the coordinates x and y of a with the format (x,y) and (as usual) return os as a result (for chained calls using the << operator).
    a = b should assign the coordinates of b to a and (as usual) the implementation of operator= should return *this (for chained assignments);
    a += b should assign to a the sum of its coordinates with b and (as usual) the implementation of operator+= should return *this (for chained assignments);
    a + b should return a point with the coordinates corresponding to the sum of a and b;
    a * v and v * a should return a point with the coordinates of a both multiplied by v.

*/

#include "Point.h"
#include <iostream>
#include <ostream>

using namespace std;

 Point::Point() : x_(0), y_(0) {} // builds (0,0)

 Point::Point(int x, int y) : x_(x), y_(y) {} // builds (x,y)


Point::Point(const Point& p) {
    x_ = p.x_;
    y_ = p.y_;
} // copy constructor;

int Point::get_x() const {
    return x_;
} // get x coordinate

int Point::get_y() const {
    return y_;
} // get y coordinate

Point& Point::operator=(const Point& p) {
    x_ = p.x_;
    y_ = p.y_;

    return *this;
} // assignment operator

Point Point::operator+(const Point& p) const {
    int x = x_+p.x_;
    int y = y_+p.y_;

    return Point(x,y);
} //


Point& Point::operator+=(const Point& p) {
    x_ += p.x_;
    y_ += p.y_;
    return *this;
} // composed assignment and sum
Point Point::operator*(int v) const {
    
    int x = x_*v;
    int y = y_*v;

    return Point(x,y);

} // "right" multiplication by scalar
    
Point operator*(int x, const Point& p) {
    int p1 = x*p.get_x();
    int p2 = x*p.get_y();

    return Point(p1,p2);

} // "left" multiplication by scalar
std::ostream& operator<<(std::ostream& os, const Point& p) {
    
    os << '(' << p.get_x() << ',' << p.get_y() << ')';
    return os;
}

int main() { 
  // public tests (1 point each) 
  { 
    Point a, b(1,2), c(b), d(3,4); 
    b = a;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  } // -> (0,0) (0,0) (1,2) (3,4)
  { 
    Point a, b(1,2), c(b), d(3,4); 
    c = b = a;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  } // -> (0,0) (0,0) (0,0) (3,4)
  { 
    Point a(1,2), b(3,4), c = a + b, d(5,6);
    b += d;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  } // -> (1,2) (8,10) (4,6) (5,6)
  { 
    Point a(1,2), b(3,4), c = a * 2, d(5,6);
    b = 2 * d;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  } // -> (1,2) (10,12) (2,4) (5,6)
  {
    Point a(1,1), b(0,1), c(1,0), d(1,1);
    d += c += b += a += {1,2};
    d = 2 * d * 2;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
  } // -> (2,3) (2,4) (3,4) (16,20)

  cout << '\n';
  // private tests (1000 points each) 
  {
    Point a(-3,2), b(-2,4), c(6,-5), d = a + b + c;
    cout << d << '\n';
  } // -> (1,1)
  {
    Point a(-3,2), b(-2,4), c(6,-5), d;
    ((d += 3 * a) += b * 2) += 4 * c;
    cout << d << '\n';
  } // (11,-6)
  {
    Point a(-1,0), b(-10,1), c(8,-1), d(-3,1);
    d += a + 2 * b + c * 3;
    cout << d << '\n';
  } // -> (0,0)
  {
    Point a(0,-1), b(1,0), c(8,-3), d(-5,7);
    cout << (a * 2 + b * 3 + c * (-4) + 2 * d)  << '\n';
  } // // -> (-39,24)
  {
    Point a(3,-3);
    cout << (a += 3 * a * 3 * 3)  << '\n';
  } // // -> (84,-84)

  return 0;
}
