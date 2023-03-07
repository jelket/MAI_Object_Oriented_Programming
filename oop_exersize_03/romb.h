
#pragma once

#ifndef ROMB_H
#define ROMB_H

#include "figure.h"


class Romb : public Figure {
public:
    Romb();
    Romb(Point a, Point b, Point c, Point d);

    Point Center() const override;
    double Area() const override;

    std::ostream& Print(std::ostream& out) const override;
    std::istream& Scan(std::istream& in) override;

private:
    Point A, B, C, D;
};

#endif
