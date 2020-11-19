
#pragma once

#ifndef VECTOR_H
#define VECTOR_H

#include "point.h"


class Vector {
public:
    Vector(double x_cord, double y_cord);
    Vector(Point& p1, Point& p2);

    double operator*(const Vector& a) const;
    Vector& operator=(const Vector& a);

    double x, y;
};

double Length(const Point& a, const Point& b);
double Length(const Vector& a);

bool isParallel(const Vector& a, const Vector& b);

#endif