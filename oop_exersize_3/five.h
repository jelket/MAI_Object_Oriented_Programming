
#pragma once

#ifndef FIVE_H
#define FIVE_H

#include "figure.h"


class Five : public Figure {
public:
    Five();
    Five(Point a, Point b, Point c, Point d, Point e);

    Point Center() const override;
    double Area() const override;

    std::ostream& Print(std::ostream& out) const override;
    std::istream& Scan(std::istream& in) override;

private:
    Point A, B, C, D, E;
};

#endif