#include "five.h"


Five::Five() :
        A{ Point{} }, B{ Point{} }, C{ Point{} }, D{ Point{} },
        E{ Point{} } {}

Five::Five(Point a, Point b, Point c, Point d,
                 Point e) :
        A{ a }, B{ b }, C{ c }, D{ d },
        E{ e } {

    Vector AB{ A, B }, BC{ B, C }, CD{ C, D }, DE{ D, E }, EF{ E, A };
}

Point Five::Center() const {
    return { (A + B + C + D + E) / 5};
}

double Five::Area() const {
    return 1.72 * Length(A, B) * Length(A, B);
}

std::ostream& Five::Print(std::ostream& out) const {
    out << "Five: A " << A << ", B " << B << ", C " << C << ", D " << D << ", E " << E << std::endl;
    return out;
}

std::istream& Five::Scan(std::istream& in) {
    in >> A >> B >> C >> D >> E;
    (*this) = Five(A, B, C, D, E);
    return in;
}