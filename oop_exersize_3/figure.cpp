#include "figure.h"


std::ostream& operator<< (std::ostream& out, const Figure& fig) {
    fig.Print(out);
    return out;
}

std::istream& operator>> (std::istream& in, Figure& fig) {
    fig.Scan(in);
    return in;
}