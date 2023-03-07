#include <iostream>
#include <vector>
#include <cstring>

#include "romb.h"
#include "five.h"
#include "six.h"


void print_help() {
    std::cout << "1.  'add romb'            --> Create romb" << std::endl;
    std::cout << "2.  'add five'          --> Create five" << std::endl;
    std::cout << "3.  'add six'           --> Create six" << std::endl;
    std::cout << "4.  'show <ID>'             --> Output figure" << std::endl;
    std::cout << "5.  'print total'           --> Output total area" << std::endl;
    std::cout << "6.  'print area'            --> Output area" << std::endl;
    std::cout << "7.  'print center'          --> Output center" << std::endl;
    std::cout << "8.  'delete <ID>'           --> Delete figure" << std::endl;
    std::cout << "9.  'help'                  --> Get help" << std::endl;
    std::cout << "10. 'exit'                  --> Exit" << std::endl;
}

void print_errors(int&& err) {
    switch (err) {
        case 1: {
            std::cout << "Incorrect command" << std::endl;
            break;
        }
        case 2: {
            std::cout << "Incorrect coordinates for a figure" << std::endl;
            break;
        }
        case 3: {
            std::cout << "There is no item with the given index" << std::endl;
            break;
        }
        default: {
            std::cout << "Undefined error" << std::endl;
        }
    }
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main() {
    print_help();
    std::vector<Figure*> figs;

    char com1[40];
    char com2[40];
    int num_com;

    Figure* fig = nullptr;

    while (true) {
        std::cin >> com1;
        num_com = atoi(com1);

        if ((1 <= num_com && num_com <= 3) || strcmp(com1, "add") == 0) {
            if (1 <= num_com && num_com <= 3)
                com2[0] = '\0';
            else
                std::cin >> com2;

            if (num_com == 1 || strcmp(com2, "square") == 0) {
                std::cout << "input <A.x> <A.y> >> <B.x> <B.y> >> <C.x> <C.y> >> <D.x> <D.y>\t";
                fig = new Romb;
            }
            else if (num_com == 2 || strcmp(com2, "triangle") == 0) {
                std::cout << "input <A.x> <A.y> >> <B.x> <B.y> >> <C.x> <C.y> >> <D.x> <D.y> >> <E.x> <E.y>\t";
                fig = new Five;
            }
            else if (num_com == 3 || strcmp(com2, "octagon") == 0) {
                std::cout << "input <A.x> <A.y> >> <B.x> <B.y> >> <C.x> <C.y> >> <D.x> <D.y> >> <E.x> <E.y> >> <F.x> <F.y>\t";
                fig = new Six;
            }
            else {
                print_errors(1);
            }
            fig->Scan(std::cin);
            figs.push_back(fig);
        }
        else if (num_com == 4 || strcmp(com1, "show") == 0) {
            int id;
            std::cin >> id;
            if (id >= figs.size()) {
                print_errors(3);
                continue;
            }
            figs[id]->Print(std::cout);
        }
        else if ((5 <= num_com && num_com <= 7) || strcmp(com1, "print") == 0) {
            if (5 <= num_com && num_com <= 7)
                com2[0] = '\0';
            else
                std::cin >> com2;
            if (num_com == 5 || strcmp(com2, "total") == 0) {
                double total_area = 0;
                for (Figure* fig : figs) {
                    total_area += fig->Area();
                }
                std::cout << "Total area: " << total_area << std::endl;
            }
            else if (num_com == 6 || strcmp(com2, "area") == 0) {
                std::cout << "Display area: ";
                for (Figure* fig : figs) {
                    std::cout << fig->Area() << std::endl;
                }
            }
            else if (num_com == 7 || strcmp(com2, "center") == 0) {
                std::cout << "Display center: ";
                for (Figure* fig : figs) {
                    Point tmp = fig->Center();
                    std::cout << "( " << tmp.X() << ", " << tmp.Y() << " )" << std::endl;
                }
            }
            else {
                std::cout << "Incorrect command\n";
            }
        }
        else if (num_com == 8 || strcmp(com1, "delete") == 0) {
            int id;
            std::cin >> id;
            if (id >= figs.size()) {
                print_errors(3);
                continue;
            }
            delete figs[id];
            figs.erase(figs.begin() + id);
        }
        else if (num_com == 9 || strcmp(com1, "help") == 0) {
            print_help();
            continue;
        }
        else if (num_com == 10 || strcmp(com1, "exit") == 0) {
            break;
        }
        else {
            print_errors(1);
        }
        std::cout << "\tdone" << std::endl;
    }

    delete fig;

    for (int i = 0; i < figs.size(); ++i) {
        delete figs[i];
    }
    return 0;
}
