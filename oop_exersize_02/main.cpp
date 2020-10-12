#include <iostream>
#include <string>
#include <climits>

#define MAX 999999999

using namespace std;

class Long {
private:
    unsigned int first;
    unsigned int second;

public:
    Long() : first(0), second(0){}
    void Init(int, int);
    void Read();
    string toString();
    void Display();
    int countOfDigits(int);

    Long operator+ (Long l);
    Long operator- (Long l);
    Long operator* (Long l);
    Long operator/ (Long l);




};

Long Long::operator+ (Long l){
    Long a;
         a.first = this->first + l.first;
         a.second = this->second + l.second;
         if (a.second > MAX){
             a.first += 1;
             a.second -= MAX + 1;
         }
    return a;

}

Long Long::operator- (Long l){
    Long a;
    if (l.second > this->second){
        a.first = this->first - l.first - 1;
        a.second = MAX - l.second + this->second;
    }else {
        a.first = this->first - l.first;
        a.second = this->second - l.second;
    }
    return a;

}
Long Long::operator* (Long l){
    Long a;
    a.first = this->first * l.first + this->first * l.second + this->second * l.first;
    a.second = this->second * l.second;
    if (a.second > MAX){
        a.first += 1;
        a.second -= MAX + 1;
    }
    return a;

}
Long Long::operator/ (Long l){
    Long a;
    a.first = this->first / l.first;
    a.second = 0;
    return a;
}


int Long::countOfDigits(int Num){ //Считаем к-ство цифр в числе

    int count = 0;

    while (Num >= 1){
        Num /= 10;
        count++;
    }

    return count;
}

void Long::Init(int x, int y){


    if (y > UINT_MAX) throw "Error!"; //Если поля больше максимального значения то ошибка
    if (x > UINT_MAX) throw "Error!";
    if (y < 0)throw "Error!"; //Если второе поле отрицательное то ошибка
    if (y > MAX){
        x += 1;
        y -= MAX;
    }
    if (x < 0) throw "Error!";
    first = x;
    second = y;
}

void Long::Display(){

    cout << toString() << endl;
}

string Long::toString(){ // Первод в строку

    string Zeros = "";
    int countOfZeros = (9 - countOfDigits(first)) + (9 - countOfDigits(second)); //Добавляем нули неиспользованным разрядам

    if (first != 0){
        for (int i = 0; i < countOfZeros; i++){

            Zeros += "0";
        }
        return to_string(first) + Zeros + to_string(second); //Если старшая часть не равна нулю
    }
    else return to_string(second); //Если старшая часть равна нулю

}

int main() {

    setlocale(LC_ALL, "RUS");

    unsigned long long c;
    unsigned int a;
    unsigned int b;

    Long l1;
    Long l2;
    Long l3;

    cout << "введите первое число: " << endl;
    cin >> c;
    b = c/1000000000;
    a = c%1000000000;
    l1.Init(b, a);

    cout << "введите второе число: " << endl;
    cin >> c;
    b = c/1000000000;
    a = c%1000000000;
    l2.Init(b, a);

    int opt, opt_exit = 1;

    while(opt_exit == 1) {

        cout << "\n\t Выберите действие:";
        cout << "\n\t 1.Сложение";
        cout << "\n\t 2.Вычитание";
        cout << "\n\t 3.Умножение";
        cout << "\n\t 4.Деление";
        cout << "\n\t 5.Выход\n";

        cin >> opt;

        switch(opt) {
            case 1:
                l3 = l1 + l2;
                cout << "\n\n";

                l1.Display();
                cout << " + ";
                l2.Display();
                cout << " = ";
                l3.Display();
                break;

            case 2:
                l3 = l1 - l2;
                cout << "\n\n";
                l1.Display();
                cout << " - ";
                l2.Display();
                cout << " = ";
                l3.Display();
                break;

            case 3:
                l3 = l1 * l2;
                cout << "\n\n";
                l1.Display();
                cout << " * ";
                l2.Display();
                cout << " = ";
                l3.Display();
                break;

            case 4:
                l3 = l1 / l2;
                cout << "\n\n";
                l1.Display();
                cout << " / ";
                l2.Display();
                cout << " = ";
                l3.Display();
                break;

            case 5:

                return 0;

            default:
                cout << "\n\n\t---Invalid choice....... try again\n";
                break;
        }
        cout << "\n\n\t---Press 1 to continue--> ";
        cin >> opt_exit;
    }
    return 0;
}