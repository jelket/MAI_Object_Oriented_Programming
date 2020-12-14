#include <iostream>
#include <utility>
#include <algorithm>
#include <locale>

#include "queue.cpp"
#include "figure.cpp"

/*
Аминов Степан М80-208Б-19
*/


void IU() {
    std::cout << std::endl << "1 - Добавить ромб в очередь" << std::endl;
    std::cout << "2 - Удалить ромб из очереди" << std::endl;
    std::cout << "3 - Вывод ромбов" << std::endl;
    std::cout << "4 - Общая площадь" << std::endl;
    std::cout << "5 - Меню" << std::endl;
    std::cout << "6 - Выход" << std::endl;
}

int main() {
    Queue<Rhombus<int>> q;
    int cmd, i, cnt;
    double sq;
    IU();
    while (true) {
        std::cin >> cmd;
        switch(cmd) {
            case 1: {
                std::cout << "1 - добавить в конец\n2 - добавить по индексу" << std::endl;
                std::cin >> cmd;
                if(cmd == 1) {
                    Rhombus<int> rec;
                    try {
                        std::cout << "Первая диагональ:" << std::endl;
                        std::cin >> rec.c.first;
                        std::cout << "Вторая диагональ:" << std::endl;
                        std::cin >> rec.c.second;
                    } catch (std::exception &e) {
                        std::cout << e.what() << std::endl;
                        break;
                    }
                    q.Push(rec);
                    continue;
                }
                else if (cmd == 2) {
                    Rhombus<int> rec;
                    try {
                        std::cout << "Первая диагональ:" << std::endl;
                        std::cin >> rec.c.first;
                        std::cout << "Вторая диагональ:" << std::endl;
                        std::cin >> rec.c.second;
                    } catch (std::exception &e) {
                        std::cout << e.what() << std::endl;
                        break;
                    }
                    std::cout << "Введите позицию вставки:" << std::endl;
                    std::cin >> i;
                    Queue<Rhombus<int>>::ForwardIterator it = q.Begin();
                    for (cnt = 0; cnt < i; cnt++) {
                        it++;
                    }
                    q.Insert(it, rec);
                    continue;
                }
                else {
                    std::cout << "Error: Invalid input" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(30000, '\n');
                    break;
                }
            }
            case 2: {
                std::cout << " 1 - pop\n2 - position" << std::endl;
                std::cin >> cmd;
                if (cmd == 1) {
                    q.Pop();
                    continue;
                }
                else if(cmd == 2) {
                    std::cout << "Введите индекс удаления элемента по позиции: ";
                    std::cin >> i;
                    Queue<Rhombus<int>>::ForwardIterator it = q.Begin();
                    for (cnt = 0; cnt < i; cnt++) {
                        it++;
                    }
                    q.Erase(it);
                    continue;
                }
                else {
                    std::cout << "Error: Invalid input" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(30000, '\n');
                    break;
                }
            }
            case 3: {
                std::cout << "Вывод очереди:" << std::endl;
                q.Print();

                continue;
            }

            case 4: {
                std::cout << "Введите число: " << std::endl;
                std::cin >> sq;
                std::cout << "Количество ромбов с площадью меньше, чем заданное число: "
                          << std::count_if(q.Begin(), q.End(), [sq](Rhombus<int> t){
                              return 0.5 * t.c.first*t.c.second < sq;
                          }) << std::endl;
                continue;
            }
            case 6: {
                return 0;
            }
            case 5: {
                IU();
                continue;
            }
            default: {
                std::cout << "Error: Invalid input" << std::endl;
                std::cin.clear();
                std::cin.ignore(30000, '\n');
            }
        }
    }
    return 0;
}
