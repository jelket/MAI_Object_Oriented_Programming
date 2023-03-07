#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


class Figure{
public:
    virtual void getSquare() = 0;
    virtual void getCoordinates() = 0;
    virtual void showFigureType() = 0;
    virtual int getMagic() = 0;
    virtual void save(ostream &f) = 0;
    virtual ~Figure() {}
};

class Hexagon : public Figure
{
private:
    double s;
public:
    Hexagon(){
    }
    Hexagon(double side) : s(side){
    }
    Hexagon(istream &f){
        f.read( (char*) (&s), sizeof(double) );
    }
    void save(ostream &f){
        f.write( (char*) (&s), sizeof(double));
    }
    void getSquare(){
        std::cout << "Hexagon Square: "<< 1.5*sqrt(3)*s*s << std::endl;
    }
    void getCoordinates(){
        std::cout << "Hexagon Coords:"<<"(" << s*sin(0) << "," << s << ");"  << std::endl;
        std::cout << "(" << s*sin(2*3.14*1/6) << ","<< s*cos(2*3.14*1/6) << ");" << std::endl;
        std::cout << "(" << s*sin(2*3.14*2/6) << ","<< s*cos(2*3.14*2/6) << ");" << std::endl;
        std::cout << "(" << s*sin(2*3.14*3/6) << ","<< s*cos(2*3.14*3/6) << ");" << std::endl;
        std::cout << "(" << s*sin(2*3.14*4/6) << ","<< s*cos(2*3.14*4/6) << ");" << std::endl;
        std::cout << "(" << s*sin(2*3.14*5/6) << ","<< s*cos(2*3.14*5/6) << ");" << std::endl;
    }
    void showFigureType(){
        std::cout << "Hexagon" << std::endl;
    }
    int getMagic() { return 1; }
};

class Rhombus : public Figure{
private:
    double diag1;
    double diag2;
public:
    Rhombus(){
    }
    Rhombus(double d1, double d2) : diag1(d1), diag2(d2){
    }
    Rhombus(istream &f){
        f.read( (char*) (&diag1), sizeof(double) );
        f.read( (char*) (&diag2), sizeof(double) );
    }
    void save(ostream &f){
        f.write( (char*) (&diag1), sizeof(double) );
        f.write( (char*) (&diag2), sizeof(double) );
    }
    void getSquare(){
        std::cout << "Rhombus Square: "<< diag1 * diag2 * 0.5 << std::endl;
    }
    void getCoordinates(){
        std::cout << "Rhombus Coords:"<<"(0,0);("<< diag2/2 <<";"<<diag1/2<<");(0;"<< diag1 <<");("<< -diag2/2 <<";"<< diag1/2 <<")." << std::endl;
    }
    void showFigureType(){
        std::cout << "Rhombus" << std::endl;
    }
    int getMagic() { return 2; }
};

class Pentagon : public Figure{
private:
    double a;
public:
    Pentagon(){
    }
    Pentagon(double a) : a(a){
    }
    Pentagon(istream &f){
        f.read( (char*) (&a), sizeof(double) );
    }
    void save(ostream &f){
        f.write( (char*) (&a), sizeof(double) );
    }
    void getSquare(){
        std::cout << "Pentagon Square: "<<  1.72*a*a << std::endl;
    }

    void getCoordinates(){
        std::cout << "Pentagon Coords:"<<"(" << (a/1.1756)*sin(0) << "," << a << ");"  << std::endl;
        std::cout << "(" << (a/1.1756)*sin(2*3.14*1/5) << ","<< (a/1.1756)*cos(2*3.14*1/5) << ");" << std::endl;
        std::cout << "(" << (a/1.1756)*sin(2*3.14*2/5) << ","<< (a/1.1756)*cos(2*3.14*2/5) << ");" << std::endl;
        std::cout << "(" << (a/1.1756)*sin(2*3.14*3/5) << ","<< (a/1.1756)*cos(2*3.14*3/5) << ");" << std::endl;
        std::cout << "(" << (a/1.1756)*sin(2*3.14*4/5) << ","<< (a/1.1756)*cos(2*3.14*4/5) << ");" << std::endl;
    }
    void showFigureType(){
        std::cout << "Pentagon" << std::endl;
    }
    int getMagic() { return 3; }
};

class Factory{
public:
    virtual Figure* createFigure() = 0;
    virtual Figure* loadFigure(istream &f) = 0;
    virtual ~Factory() {}
};

class HexFactory: public Factory{
public:
    Figure *createFigure(){
        return reinterpret_cast<Figure*>(new Hexagon());
    }
    Figure* createFigure(double width,double height) {
        return reinterpret_cast<Figure*>(new Hexagon(width));
    }
    Figure* loadFigure(istream &f) {
        return reinterpret_cast<Figure*>(new Hexagon(f));
    }
};

class RhomFactory: public Factory{
public:
    Figure *createFigure(){
        return reinterpret_cast<Figure*>(new Rhombus());
    }
    Figure* createFigure(double diag1,double diag2) {
        return reinterpret_cast<Figure*>(new Rhombus(diag1,diag2));
    }
    Figure* loadFigure(istream &f) {
        return reinterpret_cast<Figure*>(new Rhombus(f));
    }
};

class PenFactory: public Factory{
public:
    Figure *createFigure(){
        return reinterpret_cast<Figure*>(new Pentagon());
    }
    Figure* createFigure(double a) {
        return reinterpret_cast<Figure*>(new Pentagon(a));
    }
    Figure* loadFigure(istream &f) {
        return reinterpret_cast<Figure*>(new Pentagon(f));
    }
};