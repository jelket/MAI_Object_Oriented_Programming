#include "six.h"


Six::Six() :
        A{ Point{} }, B{ Point{} }, C{ Point{} }, D{ Point{} },
        E{ Point{} }, F{ Point{} } {}

Six::Six(Point a, Point b, Point c, Point d,
                 Point e, Point f) :
        A{ a }, B{ b }, C{ c }, D{ d },
        E{ e }, F{ f }{

    Vector AB{ A, B }, BC{ B, C }, CD{ C, D }, DE{ D, E }, EF{ E, F }, FA{ F, A };
}

Point Six::Center() const {
    return { (A + B + C + D + E + F) / 6};
}

double Six::Area() const {
    return 1.5 * sqrt(3) * Length(A, B) * Length(A, B);
}

std::ostream& Six::Print(std::ostream& out) const {
    out << "Six: A " << A << ", B " << B << ", C " << C << ", D " << D << ", E " << E << ", F " << F << std::endl;
    return out;
}

std::istream& Six::Scan(std::istream& in) {
    in >> A >> B >> C >> D >> E >> F;
    (*this) = Six(A, B, C, D, E, F);
    return in;
}//
// Created by magic on 02.11.2020.
//

