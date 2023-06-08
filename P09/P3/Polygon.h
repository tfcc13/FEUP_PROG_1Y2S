#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "Point.h"

class Polygon {
    public:

    Polygon(const std::vector<Point>& polygon = {});

    int get_tot_ver() const;

    bool get_vertex(int num, Point &point) const;

    bool add_vertex(int num, const Point &point);

    void show() const;

    double perimeter() const;


    private:
        static double distance(const Point &point1, const Point &point2);
        std::vector<Point> polygon_;
    

};

#endif