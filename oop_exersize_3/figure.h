#pragma once

#ifndef FIGURE_H
#define FIGURE_H

#include "myvector.h"


class Figure {
public:
    virtual ~Figure() = default;

    virtual Point Center() const = 0;
    virtual double Area() const = 0;

    virtual std::ostream& Print(std::ostream& out) const = 0;
    virtual std::istream& Scan(std::istream& in) = 0;
};

std::ostream& operator<< (std::ostream& out, const Figure& fig);
std::istream& operator>> (std::istream& in, Figure& fig);

#endif