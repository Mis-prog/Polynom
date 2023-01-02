#include "iostream"
#include "Polynom_second.h"
#include "cmath"
using namespace std;

void Polynom_second::koren() {
    {
        double a1=a[2];
        double b=a[1];
        double c=a[0];
        double x;
        if((b*b - 4 * a1 * c) >= 0)
        {
            x = ( -1*b + sqrt(b*b - 4 * a1 * c) ) / (2 * a1);
            cout << "x1=" << x << endl;
            x = ( -1*b - sqrt(b*b - 4 * a1 * c) ) / (2 * a1);
            cout << "x2=" << x << endl;
        }
        else
        {
            cout << "Дискриминант меньше 0, корни невещественные." << endl;
        }
    }
}

void Polynom_second::set() {
    a.clear();
    a.resize(3,0);
    cout << "Введите 1, если хотите произвести ввод самостоятельно, 2 в случайном порядке:\n";
    int x;
    while (!(cin >> x) || (cin.peek() != '\n') || x<1 || x>2)
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Недопустимое значение, повторите ввод\n";
        cout << "Введите 1, если хотите произвести ввод самостоятельно, 2 в случайном порядке:\n";
    }
    switch (x) {
        case 1:
            cout << "Введите степень многочлена:" << endl;
            while (!(cin >> n1) || (cin.peek() != '\n')  || n1<0 || n1>2)
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Недопустимое значение, повторите ввод\n";
                cout << "Введите степень многочлена:" << endl;
            }
            cout << "Введите коэфиценты многочлена:" <<endl;
            for (int i=n1;i>=0;i--){
                bool good=false;
                while (!good)
                {
                    good= true;
                    cout << i << ":";
                    if (!(cin >> a[i]) || (cin.peek() != '\n')){
                        cout << "Недопустимое значение, повторите ввод\n";
                        good= false;
                    }
                    cin.clear();
                    while (cin.get() != '\n');
                }
            }
            break;
        case 2:
            srand(time(NULL));
            n1=rand()%2+1;
            for (int i=0;i<=n1;i++){
                a[i]=rand()%10+1;
            }
            break;
    }
}

