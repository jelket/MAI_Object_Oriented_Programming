#include <iostream>
#include <queue>
#include <ctime>
#include <sstream>
#include <thread>
#include <vector>
#include <functional>
#include <mutex>

#include "factory.hpp"
#include "extra.hpp"

using server = Server<std::shared_ptr<Figure>>;

void print_menu() {
    std::cout << "1. Add Rectangle" << std::endl;
    std::cout << "2. Add Trapezoid" << std::endl;
    std::cout << "3. Add Rhombus" << std::endl;
    std::cout << "0. Exit" << std::endl << std::endl;
}

// Аминов Степан М8О-208Б-19  ЛР%8

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "ERROR: ./... buffer_size" << std::endl;
        return 1;
    }

    short buf_size = std::atoi(argv[1]);
    if (buf_size <= 0) {
        std::cout << "Buffer size must be possitive" << std::endl;
        return 2;
    }



    server::get().register_subscriber([](const std::shared_ptr<Figure> fig) {
        fig->Print();
    });

    server::get().register_subscriber([](const std::shared_ptr<Figure> fig) {
        fig->Write_to_file(server::get().get_fd());
    });

    std::thread th([buf_size]() {
        server::get().run(buf_size);
    });

    print_menu();

    int cmd;
    while (true) {
        std::cin >> cmd;
        if (cmd == 1) {
            std::cout << "Enter center, side:" << std::endl;
            std::shared_ptr<Figure> fig = factory::create((Figure_type)cmd);
            server::get().publish(fig);
            std::cout << "Figure is added" << std::endl;
        }
        else if (cmd == 2) {
            std::cout << "Enter center, side:" << std::endl;
            std::shared_ptr<Figure> fig = factory::create((Figure_type)cmd);
            server::get().publish(fig);
            std::cout << "Figure is added" << std::endl;
        }
        else if (cmd == 3) {
            std::cout << "Enter center and two diagonals:" << std::endl;
            std::shared_ptr<Figure> fig = factory::create((Figure_type)cmd);
            server::get().publish(fig);
            std::cout << "Figure is added" << std::endl;
        }
        else if (cmd == 0) {
            server::get().stop();
            break;
        }
        else {
            std::cout << "Incorrect command" << std::endl;
        }
    }

    th.join();
    return 0;
}