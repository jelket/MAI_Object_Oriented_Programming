
#pragma once

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>


class Point {
public:
    Point();
    Point(double a, double b);
    Point(const Point& other);

    double X() const;
    double Y() const;

    Point operator+ (const Point& a) const;
    Point operator- (const Point& a) const;
    Point operator* (double a) const;
    Point operator/ (double a) const;

    friend std::ostream& operator<< (std::ostream& out, const Point& a);
    friend std::istream& operator>> (std::istream& in, Point& a);


private:
    double x;
    double y;
};

#endif
