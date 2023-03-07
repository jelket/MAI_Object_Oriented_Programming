#pragma once
#include <fstream>
#include <iostream>
#include "figure.hpp"

class Hexagon: public Figure {
private:
    std::pair<double,double> center;
    double side;
public:
    Hexagon() = default;

    Hexagon(std::pair<double, double> &center, double l) : center(center), side(l) {}

    double Square() override {
        return 1.5*sqrt(3)*side*side ;
    }

    void Print() override {
        std::cout << *this;
    }


    void Write_to_file(std::ofstream& out) override {
        out << *this << std::endl;
        out << "Square: " << Square() << std::endl;
        out << "Center: (" << this->center.first << "; " << this->center.second << ")" << std::endl << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &out, Hexagon &rh);
};
std::ostream &operator<<(std::ostream &out, Hexagon &six) {
    std::cout << "Hexagon Coords:"<<"(" << six.center.first + six.side*sin(0) << "," << six.center.second + six.side << ");"  << std::endl;
    std::cout << "(" << six.center.first + six.side*sin(2*3.14*1/6) << ","<< six.center.second + six.side*cos(2*3.14*1/6) << ");" << std::endl;
    std::cout << "(" << six.center.first + six.side*sin(2*3.14*2/6) << ","<< six.center.second + six.side*cos(2*3.14*2/6) << ");" << std::endl;
    std::cout << "(" << six.center.first + six.side*sin(2*3.14*3/6) << ","<< six.center.second + six.side*cos(2*3.14*3/6) << ");" << std::endl;
    std::cout << "(" << six.center.first + six.side*sin(2*3.14*4/6) << ","<< six.center.second + six.side*cos(2*3.14*4/6) << ");" << std::endl;
    std::cout << "(" << six.center.first + six.side*sin(2*3.14*5/6) << ","<< six.center.second + six.side*cos(2*3.14*5/6) << ");" << std::endl;
}