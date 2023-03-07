#pragma once
#include <fstream>
#include <iostream>
#include "figure.hpp"

class Pentagon: public Figure {
private:
    std::pair<double,double> center;
    double side;
public:
    Pentagon() = default;

    Pentagon(std::pair<double, double> &center, double l) : center(center), side(l) {}

    double Square() override {
        return 1.72*side*side ;
    }

    void Print() override {
        std::cout << *this;
    }


    void Write_to_file(std::ofstream& out) override {
        out << *this << std::endl;
        out << "Square: " << Square() << std::endl;
        out << "Center: (" << this->center.first << "; " << this->center.second << ")" << std::endl << std::endl;
    }
    friend std::ostream &operator<<(std::ostream &out, Pentagon &rh);
};

std::ostream &operator<<(std::ostream &out, Pentagon &five) {
    std::cout << "Pentagon Coords:"<<"(" <<five.center.first + (five.side/1.1756)*sin(0) << "," <<five.center.second + five.side << ");"  << std::endl;
    std::cout << "(" <<five.center.first + (five.side/1.1756)*sin(2*3.14*1/5) << ","<<five.center.second + (five.side/1.1756)*cos(2*3.14*1/5) << ");" << std::endl;
    std::cout << "(" <<five.center.first + (five.side/1.1756)*sin(2*3.14*2/5) << ","<<five.center.second + (five.side/1.1756)*cos(2*3.14*2/5) << ");" << std::endl;
    std::cout << "(" <<five.center.first + (five.side/1.1756)*sin(2*3.14*3/5) << ","<<five.center.second + (five.side/1.1756)*cos(2*3.14*3/5) << ");" << std::endl;
    std::cout << "(" <<five.center.first + (five.side/1.1756)*sin(2*3.14*4/5) << ","<<five.center.second + (five.side/1.1756)*cos(2*3.14*4/5) << ");" << std::endl;
}