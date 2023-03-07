
#include "romb.h"


Romb::Romb() : A{ Point{} }, B{ Point{} }, C{ Point{} }, D{ Point{} } {}

Romb::Romb(Point a, Point b, Point c, Point d) :
        A{ a }, B{ b }, C{ c }, D{ d } {

    Vector AB{ A, B }, BC{ B, C }, CD{ C, D }, DA{ D, A }, AC{A,C}, BD{B,D};

    if (!isParallel(DA, BC)) {
        std::swap(A, B);
        AB = { A, B };
        BC = { B, C };
        DA = { D, A };
    }
    if (!isParallel(AB, CD)) {
        std::swap(B, C);
        AB = { A, B };
        BC = { B, C };
        DA = { D, A };
    }
    if (AC * BD) {
        throw std::logic_error("Диагонали ромбы должны быть перпендикулярны");
    }
    if (Length(AB) != Length(BC) || Length(BC) != Length(CD) || Length(CD) != Length(DA) || Length(DA) != Length(AB)) {
        throw std::logic_error("Стороны ромба должны быть равны");
    }
    if (!Length(AB) || !Length(BC) || !Length(CD) || !Length(DA)) {
        throw std::logic_error("Стороны ромба должны быть больше нуля");
    }
}

Point Romb::Center() const {
    return Point{ (A + B + C + D) / 4 };
}

double Romb::Area() const {
    double AB = Length(A, B);
    double BC = Length(B, C);
    double AC = Length(A, C);
    double accumulate = AB + BC + AC;
    double heron = sqrt((accumulate / 2) * (accumulate / 2 - AB) * (accumulate / 2 - BC) * (accumulate / 2 - AC));
    return heron*2;
}

std::ostream& Romb::Print(std::ostream& out) const {
    out << "Square: A " << A << ", B " << B << ", C " << C << ", D " << D << std::endl;
    return out;
}

std::istream& Romb::Scan(std::istream& in) {
    in >> A >> B >> C >> D;
    (*this) = Romb(A, B, C, D);
    return in;
}
