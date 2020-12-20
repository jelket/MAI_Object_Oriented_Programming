#include <iostream>
#include <algorithm>
#include "queue.cpp"
#include "allocator.h"
#include "six.hpp"

void print_menu() {
    std::cout << "1. Push hexagon in the stack\n";
    std::cout << "2. Pop hexagon from the stack\n";
    std::cout << "3. Check first element in queue\n";
    std::cout << "4. Insert hexagon to the position\n";
    std::cout << "5. Erase hexagon from the position\n";
    std::cout << "6. Print all figures\n";
    std::cout << "0. Exit\n";
}

int main() {
    Queue<Rectangle<int>, allocator<Rectangle<int>, 10>> q;
    print_menu();
    short cmd;
    while (std::cin >> cmd) {
        if (cmd == 1) {
            try {
                std::cout << "Enter lenght of a side and koordinates of center center = (x,y):\n";
                Rectangle<int> rec;
                std::cin >> rec;
                q.Push(rec);
                std::cout << "OK\n";
            }
            catch (std::exception &ex) {
                std::cout << "Not enough memory: " << ex.what() << std::endl;
            }

        } else if (cmd == 2) {
            try {
                q.Pop();
                std::cout << "OK\n";
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        } else if (cmd == 3) {
            try {
                auto t = q.Top();
                std::cout << "Head:\n" << t;
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }
        } else if (cmd == 4) {
            Rectangle<int> rec;
            size_t pos;
            std::cout << "Enter lenght of a side and koordinates of center center = (x,y):\n";
            std::cin >> rec;
            std::cout << "Enter position:\n";
            std::cin >> pos;
            auto iter = q.Begin();
            try {
                if (iter == q.End() && pos != 0) {
                    throw std::runtime_error("ERROR: Impossible to insert");
                }
                for (unsigned int i = 0; i < pos; ++i) {
                    ++iter;
                    if (iter == q.End() && i != pos - 1) {
                        throw std::runtime_error("ERROR: Impossible to insert");
                    }
                }
                q.Insert(iter, rec);
                std::cout << "OK\n";
            }
            catch (std::runtime_error &ex) {
                std::cout << ex.what() << std::endl;
            }
            catch (std::bad_alloc &ex) {
                std::cout << "Not enough memory: " << ex.what() << std::endl;
            }
        } else if (cmd == 5) {
            unsigned int pos;
            std::cout << "Enter position:\n";
            std::cin >> pos;
            auto iter = q.Begin();
            try {
                if (iter == q.End()) {
                    throw std::runtime_error("ERROR: Impossible to erase");
                }
                for (unsigned int i = 0; i < pos; ++i) {
                    ++iter;
                    if (iter == q.End() && i != pos) {
                        throw std::runtime_error("ERROR: Impossible to erase");
                    }
                }
                q.Erase(iter);
                std::cout << "OK\n" << std::endl;
            }
            catch (std::exception &ex) {
                std::cout << ex.what() << std::endl;
            }

        } else if (cmd == 6) {
            std::for_each(q.Begin(), q.End(), [](Rectangle<int> rec) {
                std::cout << rec << std::endl;
            });

        } else if (cmd == 0) {
            break;
        } else {
            std::cout << "Invalid write\n";
        }
    }
    return 0;
}
