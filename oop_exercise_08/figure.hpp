#pragma once

#include <cmath>
#include <utility>
#include <iostream>

class Figure {
public:
    Figure() = default;

    virtual double Square() = 0;

    virtual void Print() = 0;

    virtual void Write_to_file(std::ofstream &out) = 0;
};