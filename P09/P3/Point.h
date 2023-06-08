#ifndef POINT_H
#define POINT_H

class Point {
    public:
    Point(double x=0, double y=0);

    //acessors

    double get_x() const;
    double get_y() const;
    void show() const;

    private:
    double x_, y_;

};

#endif