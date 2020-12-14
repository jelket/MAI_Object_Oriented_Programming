#include <iostream>
#include <memory>
#include <algorithm>

template<typename T>
struct Rhombus {
    using coords = std::pair<T, T>;
    coords a, b, c, d;
};