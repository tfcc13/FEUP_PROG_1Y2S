#include "Polygon.h"
#include <iostream>
#include <cmath>
#include <iomanip>

Polygon::Polygon(const std::vector<Point>& polygon) : polygon_(polygon) {}



int Polygon::get_tot_ver() const {
    return polygon_.size();
}

bool Polygon::get_vertex(int num, Point &point) const {
    if (num >= 1 && num <= int(polygon_.size())) {
        point = polygon_.at(num-1);
        return true;
    }
    return false;
}

bool Polygon::add_vertex(int num, const Point &point) {
    if (num >= 1 && num <= int(polygon_.size()+1)) {
        polygon_.insert(polygon_.begin()+num-1,point);
        return true;
    }
    return false;
}

void Polygon::show() const {
        std::cout << '{';
        for (const Point &point:polygon_ ) {
            point.show();
        }
        std::cout << '}';
    }
    
double Polygon::perimeter() const {
    double pm = 0.0;

    if (polygon_.size()>=3) {
        for (size_t i = 0; i < polygon_.size()-1; i++) {
            pm += distance(polygon_.at(i), polygon_.at(i+1));
        }
        pm += distance(polygon_.at(0), polygon_.at(polygon_.size()-1));
    }
    return pm;
}


double Polygon::distance(const Point &point1, const Point &point2) {
    double dx = point1.get_x() - point2.get_x();
    double dy = point1.get_y() - point2.get_y();

    return std::sqrt(dx*dx+dy*dy);
}