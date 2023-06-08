#include "Point.h"
#include <iostream>


    Point::Point(double x, double y) : x_(x), y_(y) {}



    //acessors

    double Point::get_x() const {
        return x_;
    }
    double Point::get_y() const {
        return y_;
    }
    void Point::show() const {
        std::cout << '(' << x_ << ',' << y_ << ')';
    }
