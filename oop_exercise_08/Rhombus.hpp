#pragma once

#include <iostream>
#include <fstream>
#include "figure.hpp"

class Rhombus : public Figure{
private:
    double d1;
    double d2;
    std::pair<double,double> center;

public:
    Rhombus() = default;

    Rhombus(std::pair<double, double> &center, double d1, double d2) : center(center), d1(d1), d2(d2) {}

    double Square() override {
        return d1 * d2 * 0.5;
    }

    void Print() override {
        std::cout << *this;
    }

    void Write_to_file(std::ofstream& out) override {
        out << *this << std::endl;
        out << "Square: " << Square() << std::endl;
        out << "Center: (" << this->center.first << "; " << this->center.second << ")" << std::endl << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &out, Rhombus &rh);
};

std::ostream &operator<<(std::ostream &out, Rhombus &rh) {
    out << "Rhombus:\n";
    out << "(" << rh.center.first - rh.d1 * 0.5 << "; " << rh.center.second << ")\n";
    out << "(" << rh.center.first << "; " << rh.center.second + rh.d2 * 0.5 << ")\n";
    out << "(" <<rh.center.first + rh.d1 * 0.5 << "; " << rh.center.second << ")\n";
    out << "(" <<rh.center.first << "; " << rh.center.second - rh.d2 * 0.5 << ")\n";
    return out;
}