#pragma once
#include <memory>
#include "Rhombus.hpp"
#include "Pentagon.hpp"
#include "Hexagon.hpp"

enum class Figure_type {
    Pentagon = 1,
    Hexagon = 2,
    Rhombus = 3,
};



struct factory {
    static std::shared_ptr<Figure> create(Figure_type t) {
        switch (t) {
            case Figure_type::Pentagon: {
                std::pair<double, double> center;
                double side;
                std::cin >> center.first >> center.second >> side;
                return std::make_shared<Pentagon>(center, side);
            }
            case Figure_type::Hexagon: {
                std::pair<double, double> center;
                double side;
                std::cin >> center.first >> center.second >> side;
                return std::make_shared<Hexagon>(center, side);
            }
            case Figure_type::Rhombus: {
                std::pair<double, double> center;
                double d1,d2;
                std::cin >> center.first >> center.second >> d1 >> d2;
                return std::make_shared<Rhombus>(center, d1, d2);
            }
            default:
                throw std::logic_error("Wrong figure id");
        }
    }
};