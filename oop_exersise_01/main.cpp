#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>

int main(){
    using namespace std;

    ifstream file("/home/magic/CLionProjects/untitled1/given.txt");

    float D1, D2;
    double A1, A2, B1, B2;
    char symbol;
    double rad;
    int otv;

    if(!file){
        cerr << "nope" << endl;
        exit(1);
    }
    while (file){
        file>>D1;
        file>>symbol;

        if(symbol == '+'){
            file>>D2;
            A1 = modf(D1, &A2);
            B1 = modf(D2, &B2);
            otv = A2*60 + A1*100 + B2*60 + B1*100;
            rad = otv/60*3.14/180 + otv%60*3.14/180*0.01;
            if (otv%60 < 10){
                cout << "ответ в граддусах" << otv/60 << ",0" << otv%60 << endl;
            } else {
                cout << "ответ в градусах:" << otv/60 << "," << otv%60 << endl;
            }
            cout << "ответ в радианах:" << rad << endl;
        }
        if(symbol == '/'){
            file>>D2;
            A1 = modf(D1, &A2);
            B1 = modf(D2, &B2);
            otv = (A2*60 + A1*100)/(B2*60 - B1*100);
            cout << "результат деления:" << otv  << endl;
        }
        if(symbol == '-'){
            file>>D2;
            A1 = modf(D1, &A2);
            B1 = modf(D2, &B2);
            otv = A2*60 + A1*100 - B2*60 - B1*100;
            while (otv < 0){
                otv += 21600;
            }
            rad = otv/60*3.14/180 + otv%60*3.14/180*0.01;
            if (otv%60 < 10){
                cout << "ответ в граддусах" << otv/60 << ",0" << otv%60-1 << endl;
            } else {
                cout << "ответ в градусах:" << otv / 60 << "," << otv % 60 -1 << endl;
            }
            cout << "ответ в радианах:" << rad << endl;
        }
        if(symbol == 'r'){
            A1 = modf(D1, &A2);
            otv = A2*60 + A1*100;
            rad = otv*3.14/180/60;
            cout << "перевод в радианы:" << rad << endl;
        }
        if(symbol == 'd'){
            rad = D1*180/3.14;
            while (rad > 360){
                rad -= 360;
            }
            cout << "перевод в градусы:" << rad << endl;
        }
    }
    return 0;
}
