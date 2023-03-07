#include "point.h"


Point::Point() : x{ 0.0 }, y{ 0.0 } {}
Point::Point(double a, double b) : x{ a }, y{ b } {}
Point::Point(const Point& other) : x{ other.x }, y{ other.y } {}

double Point::X() const { return x; }
double Point::Y() const { return y; }

Point Point::operator+ (const Point& a) const {
    return { this->x + a.x, this->y + a.y };
}

Point Point::operator- (const Point& a) const {
    return { this->x - a.x, this->y - a.y };
}

Point Point::operator* (double a) const {
    return { this->x * a, this->y * a };
}

Point Point::operator/ (double a) const {
    return { this->x / a, this->y / a };
}

std::ostream& operator<< (std::ostream& out, const Point& a) {
    out << "( " << a.x << ", " << a.y << " )";
    return out;
}

std::istream& operator>> (std::istream& in, Point& a) {
    in >> a.x >> a.y;
    return in;
}
