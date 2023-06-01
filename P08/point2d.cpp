/*
Consider the code given in Point2d.h containing the definition of class Point2d to represent 2D-coordinates of type double:

class Point2d {
  public:
    Point2d();                   // default constructor (builds origin)
    Point2d(const Point2d& p);   // copy constructor
    Point2d(double x, double y); // constructor using supplied coordinates
    double get_x() const;  // accessor for X coordinate
    double get_y() const;  // accessor for Y coordinate
    void set_x(double x);  // mutator for X coordinate
    void set_y(double y);  // mutator for Y coordinate
    void translate(const Point2d& t);           // translate coordinates
    double distance_to(const Point2d& p) const; // get distance to given point
  private: 
    double x;  // X coordinate
    double y;  // Y coordinate
};

Write the C++ code for the translate() and distance_to() member functions (not yet implemented), such that:

    a.translate(t) changes a with a translation by coordinates t, i.e., if a has coordinates (x,y) on entry, then a should have coordinates (x + t.x, y + t.y) on exit; and
    a.distance_to(b) returns the Euclidean distance between a and b, i.e., (a.x−b.x)2+(a.y−b.y)2−−−−−−−−−−−−−−−−−−−−−−√
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Point2d.h"
using namespace std;

 void Point2d::translate(const Point2d& t) {
    set_x(x+t.x);
    set_y (y+t.y);
 }

 double Point2d::distance_to(const Point2d& p) const {
    return (sqrt(pow(x-p.x,2)+pow(y-p.y,2)));
 }

 int main() { 
  // public tests (1 point each) 
  {
    Point2d a { 1.0, 2.1 };
    a.translate({ -0.3, 0.5 });
    cout << fixed << setprecision(2) 
         << a.get_x() << ' ' << a.get_y() << '\n';
  } // -> 0.70 2.60
  {
    Point2d a { 1.0, 2.1 }, b { 2.0, 3.1 };
    cout << fixed << setprecision(2) 
         << a.distance_to(b) << '\n';
  } // -> 1.41
  {
    Point2d a { 0, 0 }; Point2d b = a;
    a.translate({ 0, 0 });
    cout << fixed << setprecision(2) 
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 0.00 0.00 0.00
  {
    Point2d a { 0, 1 }; Point2d b = a;
    a.translate({ 1.5, 0 });
    cout << fixed << setprecision(2) 
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 1.50 1.00 1.50
  {
    Point2d a { 1, 0 }; Point2d b = a;
    a.translate({ -1, 2.5 });
    cout << fixed << setprecision(2) 
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 0.00 2.50 2.69
  
  cout << '\n';
  // private tests (1000 points each) 
  {
    Point2d a { 5.0, -2.1 };
    a.translate({ -0.3, 0.5 });
    cout << fixed << setprecision(2) 
         << a.get_x() << ' ' << a.get_y() << '\n';
  } // -> 4.70 -1.60
  {
    Point2d a { 1.0, 2.1 }, b { 0, 0 };
    cout << fixed << setprecision(2) 
         << a.distance_to(b) << '\n';
  } // -> 2.33
  {
    Point2d a { 5, -3 }; Point2d b = a;
    a.translate({ -5, 3 });
    cout << fixed << setprecision(2) 
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 0.00 0.00 5.83
  {
    Point2d a { 10.33, -1.23 }; Point2d b = a;
    a.translate({ -1.5, 12.3 });
    cout << fixed << setprecision(2) 
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 8.83 11.07 12.39
  {
    Point2d a { 2, 2.5 }; Point2d b = a;
    a.translate({ 0, 2.5 });
    cout << fixed << setprecision(2) 
         << a.get_x() << ' ' << a.get_y() << ' '
         << a.distance_to(b) << '\n';
  } // -> 2.00 5.00 2.50

  return 0;
}