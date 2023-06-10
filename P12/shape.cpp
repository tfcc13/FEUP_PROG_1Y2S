/*
xConsider the definition of an abstract class for bidimensional geometric shapes given in header Shape.h:

struct point {
  double x, y;
};
class Shape {
public:
  Shape(const point& center) : center_(center) { }
  const point& get_center() const { return center_; }
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual bool contains(const point& p) const = 0;
private:
  point center_;
};

A shape has a geometric center, returned by get_center(). Abstract functions area() and perimeter() should return a shape’s area and perimeter, respectively. Finally, abstract function contains() should be used to determine if a shape contains a given point.

To represent circles and rectangles, write the corresponding definition of classes Circle and Rectangle, that should both be subclasses of Shape. Circle should have a constructor that takes two arguments: the center of the circle and its radius (a double value). Rectangle has a constructor that takes 3 arguments: the geometric center of the rectangle, the rectangle’s width and the rectangle’s height (double values).

Note: use the M_PI constant defined by header <cmath> for the value of Pi. 
*/

#include "Shape.h"
#include <cmath>
#include <iostream>

using namespace std;

class Circle : public Shape {
    public:

    Circle(const point& center, double radius ) : Shape(center), radius_(radius) {}
    
    
    double radius() const { return radius_; }
   
    double area() const override {   
        
        return radius_*radius_*M_PI;
        
    }

    double perimeter() const override {
        return 2*radius_*M_PI;
    }
    bool contains(const point& p) const override {
        double dx = p.x- this->get_center().x;
        double dy = p.y - this->get_center().y;

        return sqrt(dx*dx+dy*dy)<= radius_;
    }

    private:
    
    double radius_;
    
};


class Rectangle : public Shape {
    public:

    Rectangle(const point& center, double width, double height) : Shape(center), width_(width), height_(height) {}



    const double& height() const {
        return height_;
    }
    const double& width() const {
        return width_;
    }
    


    double area() const override{

        return width_*height_;

    }
   double perimeter() const override {

        return 2*height_+2*width_;

    }
    bool contains(const point& p) const override {

        return p.y<= get_center().y+height_/2 && p.y>= get_center().y-height_/2 && p.x >= get_center().x-width_/2 && p.x <= get_center().x + width_/2 ; 


    }

    private:

    double width_;
    double height_;
};

int main() {
  // public tests (1 points each)
  { 
    Circle c({1, 2}, 1.0); 
    const point& p = c.get_center();
    cout << fixed << setprecision(2) 
         << '(' << p.x << ',' << p.y << ')' << ' '
         << c.area() << ' ' << c.perimeter() << '\n';
  } // -> (1.00,2.00) 3.14 6.28
  { 
    Rectangle r({3.4, 4.5}, 1, 2); 
    const point& p = r.get_center();
    cout << fixed << setprecision(2) 
         << '(' << p.x << ',' << p.y << ')' << ' '
         << r.area() << ' ' << r.perimeter() << '\n';
  } // -> (3.40,4.50) 2.00 6.00
  { 
    const Shape& s1 = Circle({1, 2}, 3); 
    const Shape& s2 = Rectangle({4, 5}, 6, 7); 
    cout << fixed << setprecision(2) << boolalpha
         << s1.area() << ' ' << s1.perimeter() << ' '
         << s1.contains({1, 2}) << ' ' << s1.contains({ 4, 5 }) << ' '
         << s2.area() << ' ' << s2.perimeter() <<  ' '
         << s2.contains({1, 2}) << ' ' << s2.contains({ 4, 5 }) << '\n';
  } // -> 28.27 18.85 true false 42.00 26.00 true true
  { 
    Circle c({1, 2}, 3);
    point a [] { 
      { -2.1,  2.0 }, { -1.9,  2.0 }, { 4.1,  2.0}, { 3.9,  2.0}, 
      {  1.0,  4.9 }, {  1.0, -0.9 }, { 1.0,  5.1}, { 1.0, -1.1}, 
      {  1.2, -0.3},  {  5.2,  5.1 }, { 2.1, -0.5}, { 3.2,  5.5} 
    };
    for (point& p : a)  
      if (c.contains(p)) 
        cout << '(' << p.x << ',' << p.y << ')';
    cout << '\n';
  } // -> (-1.90,2.00)(3.90,2.00)(1.00,4.90)(1.00,-0.90)(1.20,-0.30)(2.10,-0.50)
  { 
    Rectangle r({1, 2}, 6, 8);
    point a [] { 
      { -2.1,  2.0 }, { -1.9,  2.0 }, { 4.1,  2.0}, { 3.9,  2.0}, 
      {  1.0,  4.9 }, {  1.0, -0.9 }, { 1.0,  5.1}, { 1.0, -1.1}, 
      {  1.2, -0.3},  {  5.2,  5.1 }, { 2.1, -0.5}, { 3.2,  5.5} 
    };
    for (point& p : a)  
      if (r.contains(p)) 
        cout << '(' << p.x << ',' << p.y << ')';
    cout << '\n';
  } // -> (-1.90,2.00)(3.90,2.00)(1.00,4.90)(1.00,-0.90)(1.00,5.10)(1.00,-1.10)(1.20,-0.30)(2.10,-0.50)(3.20,5.50)

  cout << '\n';
  // private tests (1000 points each)
  { 
    Circle c({1.2, 2.3}, 3.4); 
    const point& p = c.get_center();
    cout << fixed << setprecision(2) 
         << '(' << p.x << ',' << p.y << ')' << ' '
         << c.area() << ' ' << c.perimeter() << '\n';
  } // -> (1.20,2.30) 36.32 21.36
  { 
    Rectangle r({3.4, 4.5}, 1.2, 3.4); 
    const point& p = r.get_center();
    cout << fixed << setprecision(2) 
         << '(' << p.x << ',' << p.y << ')' << ' '
         << r.area() << ' ' << r.perimeter() << '\n';
  } // -> (3.40,4.50) 4.08 9.20
  { 
    const Shape& s1 = Circle({4, 5}, 2.5); 
    const Shape& s2 = Rectangle({1, 2}, 4, 3); 
    cout << fixed << setprecision(2) << boolalpha
         << s1.area() << ' ' << s1.perimeter() << ' '
         << s1.contains({1, 2}) << ' ' << s1.contains({ 4, 5 }) << ' '
         << s2.area() << ' ' << s2.perimeter() <<  ' '
         << s2.contains({1, 2}) << ' ' << s2.contains({ 4, 5 }) << '\n';
  } // -> 19.63 15.71 false true 12.00 14.00 true false
  { 
    Circle c({2, 1}, 0.29);
    cout << fixed << setprecision(1);
    for (double x = -0.3; x <= 0.3; x += 0.1)
      for (double y = -0.3; y <= 0.3; y += 0.1)
        if (c.contains({ 2 + x, 1 + y}))
          cout << '(' << x << ',' << y << ')';
    cout << '\n';
  } // -> (-0.2,-0.2)(-0.2,-0.1)(-0.2,0.0)(-0.2,0.1)(-0.2,0.2)(-0.1,-0.2)(-0.1,-0.1)(-0.1,0.0)(-0.1,0.1)(-0.1,0.2)(0.0,-0.2)(0.0,-0.1)(0.0,0.0)(0.0,0.1)(0.0,0.2)(0.1,-0.2)(0.1,-0.1)(0.1,0.0)(0.1,0.1)(0.1,0.2)(0.2,-0.2)(0.2,-0.1)(0.2,0.0)(0.2,0.1)(0.2,0.2)
  { 
    Rectangle r({2, 1}, 0.59, 0.39);
    for (double x = -0.3; x <= 0.3; x += 0.1)
      for (double y = -0.3; y <= 0.3; y += 0.1)
        if (r.contains({ 2 + x, 1 + y}))
          cout << '(' << x << ',' << y << ')';
    cout << '\n';
  } // -> (-0.2,-0.1)(-0.2,0.0)(-0.2,0.1)(-0.1,-0.1)(-0.1,0.0)(-0.1,0.1)(0.0,-0.1)(0.0,0.0)(0.0,0.1)(0.1,-0.1)(0.1,0.0)(0.1,0.1)(0.2,-0.1)(0.2,0.0)(0.2,0.1)

  return 0;
}
