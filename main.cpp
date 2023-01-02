#include "windows.h"
#include "iostream"
#include "Polynom.h"
#include "Polynom_second.h"
#include "Polynom_first.h"
using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);
    Polynom first,last,middle;
    Polynom_second second,one;
    int x=10;
    while (x!=0){
        cout << "Введите номер операции:\n";
        cout << "1-сложение,2-вычитание,3-умножение,4-остаток от деления\n";
        cout << "5-возведение в квадрат,6-дифферинцирование,7-НОД,8-корни квадратного многочлена\n";
        cout << "0-завершение\n";
        while (!(cin >> x) || (cin.peek() != '\n') || x<0 || x>8)
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Недопустимое значение, повторите ввод\n";
        }
        switch (x) {
            case 0:
                exit;
                break;
            case 1:
                cout << "Многочлен a:\n";
                first.set();
                first.get();
                cout << "Многочлен b:\n";
                last.set();
                last.get();
                first=first+last;
                cout << "Многочлен a+b:\n";
                first.get();
                cout << "-----\n";
                break;
            case 2:
                cout << "Многочлен a:\n";
                first.set();
                first.get();
                cout << "Многочлен b:\n";
                last.set();
                last.get();
                first=first-last;
                cout << "Многочлен a-b:\n";
                first.get();
                cout << "-----\n";
                break;
            case 3:
                cout << "Многочлен a:\n";
                first.set();
                first.get();
                cout << "Многочлен b:\n";
                last.set();
                last.get();
                first=first*last;
                cout << "Многочлен a*b:\n";
                first.get();
                cout << "-----\n";
                break;
            case 4:
                cout << "Многочлен a:\n";
                first.set();
                first.get();
                cout << "Многочлен b:\n";
                last.set();
                last.get();
                first=first/last;
                cout << "Многочлен a/b:\n";
                first.get();
                cout << "-----\n";
                break;
            case 5:
                cout << "Многочлен a:\n";
                first.set();
                first.get();
                first=first^2;
                cout << "Многочлен a^2:\n";
                first.get();
                cout << "-----\n";
                break;
            case 6:
                cout << "Многочлен a:\n";
                first.set();
                first.get();
                first=*first;
                cout << "Многочлен dif(a):\n";
                first.get();
                cout << "-----\n";
                break;
            case 7:
                cout << "Многочлен a:\n";
                first.set();
                first.get();
                cout << "Многочлен b:\n";
                last.set();
                last.get();
                first=middle.gsd(first,last);
                cout << "НОД:\n";
                first.get();
                cout << "-----\n";
                break;
            case 8:
                cout << "Многочлен:\n";
                second.set();
                second.get();
                second.koren();
                cout << "-----\n";
        }
    }
    return 0;
}
