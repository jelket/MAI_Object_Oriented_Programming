
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "Figure.cpp"
#include <cmath>

using namespace std;

// Аминов Степан М8О-108Б-19 ЛР№7

void printmenu(){
    std::cout << "1 - Add hexagon" << std::endl;
    std::cout << "2 - Add rhombus" << std::endl;
    std::cout << "3 - Add pentagon" << std::endl;
    std::cout << "4 - Show current figures" << std::endl;
    std::cout << "5 - Start information printing" << std::endl;
    std::cout << "6 - Delete last figure" << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "n - Create new vector" << std::endl;
    std::cout << "s - Save vector as file(!)" << std::endl;
    std::cout << "l - Load vector from file(!)" << std::endl;
    std::cout << "u - Undo last step(!)" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "7 - Print help" << std::endl;
    std::cout << "8 - Exit" << std::endl;
};

void checkSaved( int &sav ) {
    char a = '\0';
    if(sav != 1){
        std::cout << "File wasn't saved. Are you sure you want to continue? Every unsaved progress will be lost FOREVER." << std::endl;
        std::cout << "y to continue\n any key to decline;" << std::endl;
        std::cin >> a;
        if(a == 'y'){
            sav = 1;
        }
        else{
            std::cout << "Denied" << std::endl;
        };
    }
}

using PFigure = std::shared_ptr<Figure>;

int main()
{
    HexFactory*  re_factory(new HexFactory);
    RhomFactory*  rh_factory(new RhomFactory) ;
    PenFactory*  pe_factory(new PenFactory) ;
    std::vector<PFigure> figur, cmd;
    double inc_a,inc_b,inc_c;
    char a;
    int sav = 1;
    printmenu();
    while (a != '8'){
        std::cin >> a;
        if(a=='1'){
            std::cout << "Creating hexagon" << std::endl;
            std::cout << "side:" << std::endl;
            std::cin >> inc_a;
            figur.push_back(PFigure(re_factory -> createFigure(inc_a,inc_b)));
            cmd.push_back(PFigure(nullptr));
            sav = 0;
            std::cout << "DONE!" << std::endl;
        };
        if(a=='2'){
            std::cout << "Creating rhombus:" << std::endl;
            std::cout << "diagonal 1:" << std::endl;
            std::cin >> inc_a;
            std::cout << "diagonal 2:" << std::endl;
            std::cin >> inc_b;
            figur.push_back(PFigure(rh_factory -> createFigure(inc_a,inc_b)));
            cmd.push_back(PFigure(nullptr));
            sav = 0;
            std::cout << "DONE!" << std::endl;
        };

        if(a=='3'){
            std::cout << "Creating pentagon:" << std::endl;
            std::cout << "side:" << std::endl;
            std::cin >> inc_a;
            figur.push_back(PFigure(pe_factory -> createFigure(inc_a)));
            cmd.push_back(PFigure(nullptr));
            sav = 0;
            std::cout << "DONE!" << std::endl;
        };

        if(a=='4'){
            std::cout << "Vector contains:"<<std::endl;
            for (const auto&obj: figur) {
                obj -> showFigureType();
            }
            std::cout << "DONE!" << std::endl;
        };

        if(a=='5'){
            for (const auto&obj: figur) {
                obj -> showFigureType();
                obj -> getSquare();
                obj -> getCoordinates();
            };
            std::cout << "DONE!" << std::endl;
        };

        if(a=='6'){
            if ( figur.size() > 0 ) {
                cmd.push_back(PFigure(figur.back()));
                figur.pop_back();
                sav = 0;
                std::cout << "DONE!" << std::endl;
            } else {
                std::cout << "Nothing to delete" << std::endl;
            }
        };

        if(a=='7'){
            printmenu();
        };

        if(a=='8'){
            checkSaved(sav);
            if ( sav != 1 ) {
                a=0;
            }
        }
        if(a=='s'){
            std::string fname;
            std::cout << "Enter file name" << std::endl;
            std::cin >> fname;
            ofstream f( fname, ios_base::out | ios_base::binary );
            int fSize = figur.size();
            f.write( (char*) (&fSize), sizeof(int) );
            for (const auto&obj: figur) {
                int magic = obj->getMagic();
                f.write( (char*) (&magic), sizeof(int) );
                obj->save(f);
            };
            f.close();
            sav = 1;
            std::cout << "File Saved!" << std::endl;
        };
        if(a=='l'){
            checkSaved( sav );
            if ( sav == 1 ) {
                figur.clear();
                cmd.clear();
                std::string fname;
                std::cout << "Enter file name" << std::endl;
                std::cin >> fname;
                ifstream f( fname, ios_base::in | ios_base::binary );
                int fSize;
                f.read( (char*) (&fSize), sizeof(int) );
                for ( int i = 0; i < fSize; i++ ) {
                    int magic;
                    f.read( (char*) (&magic), sizeof(int) );
                    Factory *fc;
                    switch( magic ) {
                        case 1:
                            fc = re_factory;
                            break;
                        case 2:
                            fc = rh_factory;
                            break;
                        case 3:
                            fc = pe_factory;
                            break;
                        default:
                            std::cout << "Error reading file!" << std::endl;
                            break;
                    }
                    figur.push_back(PFigure(fc->loadFigure(f)));
                }
                f.close();
                std::cout << "File loaded!" << std::endl;
            }
        };
        if(a=='n'){
            checkSaved( sav );
            if ( sav == 1 ){
                figur.clear();
                cmd.clear();
                std::cout << "File created!" << std::endl;
            };
        };
        if(a=='u'){
            if ( cmd.size() > 0 ) {
                PFigure f = cmd.back();
                if ( f == nullptr ) {
                    figur.pop_back();
                } else {
                    figur.push_back(f);
                }
                cmd.pop_back();
                std::cout << "last step has been undone!" << std::endl;
            } else {
                std::cout << "Nothing to undo" << std::endl;
            }
        };
    };
    delete re_factory;
    delete rh_factory;
    delete pe_factory;

    return 0;
};