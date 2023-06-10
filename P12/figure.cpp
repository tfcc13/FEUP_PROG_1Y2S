/*

Consider that you want to develop an application for drawing figures, for simplicity only rectangles and circles.

The application must use three classes, Figure, Rectangle and Circle, such that:

    Classes Rectangle and Circle must be derived from Figure
    Figure is an abstract class whose definition is given in Figure.h
    The data members of class Figure are the coordinates of the center of the figure x_center_, y_center_

Define classes Rectangle and Circle, taking into account that:

    Rectangle has two additional data members, the width and height of the rectangle width_, height_
    Circle has one additional data member, the radius of the circle radius_

Member functions draw() do not effectively draws the figures on the screen, they are just “stubs” that write a message indicating the type (R or C), the attributes of the rectangle or circle (coordinates of the center) and, for the rectangle, the length of the sides, for the circle, its radius. For example:

    R(10,20)(200,100) — rectangle centered at (x=10,y=20) with (width=200, height=100)
    C(-10,0)(50) — circle rectangle centered at (x=-10,y=0) with (radius=50)



*/

#include "Figure.h"
#include <iostream>
#include <vector>

using namespace std;

class Rectangle : public Figure {
    public:

    Rectangle(double x_center, double y_center, double width, double height ) : Figure(x_center,y_center), width_(width), height_(height) {}

    virtual void draw() const {

        cout << 'R' << '(' << this->x_center_ << ',' << this->y_center_  << ')' << '(' << width_ << ',' << height_ << ')';

    }

    private:

    double width_, height_;



};


class Circle : public Figure {

    public:

    Circle(double x_center, double y_center, double radius) : Figure(x_center, y_center), radius_(radius) {} 

    virtual void draw() const {

        cout << 'C' << '(' << this->x_center_ << ',' << this->y_center_  << ')' << '(' << radius_ << ')';

    }


    private:

    double radius_;

};


int main() {  // LeakSanitizer: detected memory leaks
  // public tests (1 point each)
  {
    Rectangle r(10, 10, 200, 100);
    r.draw(); cout << endl;
  } // -> R(10,10)(200,100)
  {
    Circle c (20, 20, 500);
    c.draw(); cout << endl;
  } // -> C(20,20)(500))
  {
    Rectangle * r = new Rectangle(10, 10, 200, 100);
    r->draw(); cout << endl; delete r;
  } // -> R(10,10)(200,100)
  {
    vector<Figure*> figures = {
      new Rectangle(10,10,200,100),
      new Circle(20,20,500),
      new Rectangle(-10,-20,150,250),
      new Circle(0,0,100) };
    for (const auto& f : figures) f->draw(); 
    cout << endl; for (const auto& f : figures) delete f;
  } // -> R(10,10)(200,100)C(20,20)(500)R(-10,-20)(150,250)C(0,0)(100)
  {
    vector<Figure*> figures = {
      new Rectangle(-10,-10,5,15),
      new Rectangle(0,0,20,10),
      new Circle(5,0,25) };
    for (const auto& f : figures) f->draw(); 
    cout << endl; for (const auto& f : figures) delete f;
  } // -> R(-10,-10)(5,15)R(0,0)(20,10)C(5,0)(25)
   cout << endl;
  // private tests (1000 points each)
  {
    Circle c(1,2,3);
    c.draw(); cout << endl;
  } // -> C(1,2)(3)
  {
    Rectangle r(1, 1, 20, 10);
    r.draw(); cout << endl;
  } // -> R(1,1)(20,10)
  {
    Circle* r = new Circle(10, 20, 30);
    r->draw(); cout << endl; delete r;
  } // -> C(10,20)(30)
  {
    vector<Figure*> figures = {
      new Rectangle(-1,-2,15,25),
      new Circle(0,0,10),
      new Rectangle(11, 12, 13, 14),
      new Circle(2, -2, 5) };
    for (const auto& f : figures) f->draw(); 
    cout << endl; for (const auto& f : figures) delete f;
  } // -> R(-1,-2)(15,25)C(0,0)(10)R(11,12)(13,14)C(2,-2)(5)
  {
    vector<Figure*> figures = {
      new Circle(0,5,100),
      new Rectangle(10,10,15,15),
      new Rectangle(0,10,100,200) };
    for (const auto& f : figures) f->draw(); 
    cout << endl; for (const auto& f : figures) delete f;
  } // -> C(0,5)(100)R(10,10)(15,15)R(0,10)(100,200)

  return 0;
}
