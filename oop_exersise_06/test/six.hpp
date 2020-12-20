#ifndef REC_H
#define REC_H

#include <iostream>
#include <math.h>

template<class T>
class Rectangle {
private:
    std::pair<T, T> center;
    double length;
public:
    Rectangle(){
        length = 0;
        center =std::make_pair(0, 0);
    }

    Rectangle( double l, T x, T y) : length(l) {
        center = std::make_pair(x, y);
    }


    bool operator!=(Rectangle<T> &rsh) {
        return !(*this == rsh);
    }

    template<class U>
    friend std::ostream &operator<<(std::ostream &out, Rectangle<U> &rec);

    template<class U>
    friend std::istream &operator>>(std::istream &in, Rectangle<U> &rec);

    bool operator==(Rectangle<T> &rsh) {
        if (this->length != rsh.length) {
            return false;
        }
        if (this->center != rsh.center) {
            return false;
        }
        return true;
    }


};

template<class U>
std::istream &operator>>(std::istream &in, Rectangle<U> &rec) {
    in >> rec.length  >> rec.center.first >> rec.center.second;
}

template<class T>
std::ostream &operator<<(std::ostream &out, Rectangle<T> &rec) {
    out << "Point A: (" << rec.center.first - rec.length << ", " << rec.center.second << ")\n";
    out << "Point B: (" << rec.center.first - (rec.length/2) << ", " << rec.center.second + (((rec.center.first + rec.length)*sqrt(3))/2 )<< ")\n";
    out << "Point C: (" << rec.center.first + (rec.length / 2) << ", " << rec.center.second + (((rec.center.first + rec.length) * sqrt(3)) / 2) << ")\n";
    out << "Point D: (" << rec.center.first + rec.length << ", " << rec.center.second << ")\n";
    out << "Point E: (" << rec.center.first + (rec.length / 2) << ", " << rec.center.second - (((rec.center.first + rec.length) * sqrt(3)) / 2) << ")\n";
    out << "Point F: (" << rec.center.first - (rec.length / 2) << ", " << rec.center.second - (((rec.center.first + rec.length) * sqrt(3)) / 2) << ")\n";
}

#endif //OOP_LAB5_RHOMBUS_H
