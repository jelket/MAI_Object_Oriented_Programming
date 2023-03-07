
#pragma once

#ifndef SIX_H
#define SIX_H

#include "figure.h"


class Six : public Figure {
public:
    Six();
    Six(Point a, Point b, Point c, Point d, Point e, Point f);

    Point Center() const override;
    double Area() const override;

    std::ostream& Print(std::ostream& out) const override;
    std::istream& Scan(std::istream& in) override;

private:
    Point A, B, C, D, E, F;
};

#endif
