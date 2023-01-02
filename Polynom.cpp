#include "Polynom.h"
#include "iostream"
#include "random"
#include "cstdlib"
using namespace std;

Polynom::~Polynom() {
    a.clear();
}

void Polynom::set() {
    a.clear();
    a.resize(11,0);
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
            while (!(cin >> n1) || (cin.peek() != '\n') || n1 < 0) {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Недопустимое значение, повторите ввод\n";
                cout << "Введите степень многочлена:" << endl;
            }
            cout << "Введите коэфиценты многочлена:" << endl;
            for (int i = n1; i >= 0; i--) {
                bool good = false;
                while (!good) {
                    good = true;
                    cout << i << ":";
                    if (!(cin >> a[i]) || (cin.peek() != '\n')) {
                        cout << "Недопустимое значение, повторите ввод\n";
                        good = false;
                    }
                    cin.clear();
                    while (cin.get() != '\n');
                }
            }
            break;
        case 2:
            srand(time(NULL));
            n1 = rand() % 10 + 1;
            for (int i = 0; i <= n1; i++) {
                a[i] = rand() % 10+1;
            }
            break;
    }
}
void Polynom::get() {
    if (n1==1){
        if (a[1]>=0){
            cout << a[1] << "x";
            if (a[0]>=0){
                cout << "+" << a[0];
            }else{
                cout << "-" << -a[0];
            }
        }else{
            cout << a[1] << "x";
            if (a[0]>=0){
                cout << "+" << a[0];
            }else{
                cout << "-" << -a[0];
            }
        }
    }else if (n1==0){
        cout << a[0];
    }else {
        cout << a[n1] << "x^" << n1;
        for (int i = n1 - 1; i >= 0; i--) {
            if (i > 1) {
                if (a[i] >= 0) {
                    cout << "+" << a[i] << "x^" << i;
                } else {
                    cout << "-" << -a[i] << "x^" << i;
                }
            } else if (i == 1) {
                if (a[i] >= 0) {
                    cout << "+" << a[i] << "x";
                } else {
                    cout << "-" << -a[i] << "x";
                }
            } else {
                if (a[i] >= 0) {
                    cout << "+" << a[i];
                } else {
                    cout << "-" << -a[i];
                }
            }
        }
    }
    cout << endl;
}
Polynom Polynom::operator+(Polynom &name) {
    Polynom temp;
    int maxN;
    if (n1>name.n1){
        temp.n1=n1;
        maxN=n1;
    }
    else{
        temp.n1=name.n1;
        maxN=name.n1;
    }
    for (int i=0;i<=maxN;i++){
        temp.a[i]= this->a[i]+name.a[i];
    }
    return temp;
}
Polynom Polynom::operator-(Polynom &name) {
    Polynom temp;
    int maxN;
    if (this->n1>name.n1){
        temp.n1=this->n1;
        maxN=this->n1;
    }
    else{
        temp.n1=name.n1;
        maxN=name.n1;
    }
    for (int i=0;i<=maxN;i++){
        temp.a[i]= this->a[i]-name.a[i];
    }
    return temp;
}
Polynom Polynom::operator*(Polynom &name) {
    Polynom temp;
    for (int i=0;i<=this->n1;i++){
        for (int j=0;j<=name.n1;j++){
            temp.a[i+j]+= this->a[i]*name.a[j];
        }
    }
    temp.n1=this->n1+name.n1;
    return temp;
}
Polynom Polynom::operator/(Polynom &name) {
    Polynom temp;
    vector <double> r3(11,0);
    int maxN,minN;
    if (this->n1>=name.n1){
        maxN=this->n1;
        minN=name.n1;
    }else {
        maxN=name.n1;
        minN=this->n1;
    }
    double q=(this->a[maxN]/name.a[minN]);
    for (int i=maxN;i>=0;i--){
        if (i>=(maxN-minN)){
            r3[i]=this->a[i]-q*name.a[i-(maxN-minN)];
        } else{
            r3[i]=this->a[i];
        }
    }
    temp.n1=maxN;
    copy(r3.begin(),r3.end(), temp.a.begin());
    r3.clear();
    return temp;
}
Polynom Polynom::operator^(const int a) {
    Polynom temp;
    for (int i=0;i<=this->n1;i++){
        for (int j=0;j<=this->n1;j++){
            temp.a[i+j]+=this->a[i]*this->a[j];
        }
    }
    temp.n1=this->n1+this->n1;
    return temp;
}
Polynom Polynom::operator*() {
    Polynom temp;
    for (int i=this->n1;i>0;i--){
        temp.a[i-1]=i*this->a[i];
    }
    temp.n1=this->n1-1;
    return temp;
}
Polynom Polynom::gsd(Polynom &left, Polynom &right) {
    if (check(left)==0){
        return left;
    }
    if (check(right)==0){
        return right;
    }
    while(true){
        left=left/right;
        if (blank(left.a)==1){
            return right;
        }
        if (check(right)>=check(left)){
            right.n1= check(right);
            left.n1= check(left);
        }else{
            right.n1= check(left);
            left.n1= check(left);
        }
        right=right/left;
        if(blank(right.a)==1){
            return left;
        }
        if (check(left)>= check(right)){
            left.n1= check(left);
            right.n1= check(right);
        }else{
            left.n1= check(right);
            right.n1= check(right);
        }
    }
}
int check(Polynom &name) {
    int x=0;
    for (int i=name.n1;i>=0;i--){
        if (name.a[i]!=0){
            x=i;
            break;
        }
    }
    return x;
}
bool blank(const vector<double> &vec) {
    for (auto i : vec){
        if (i!=0){
            return 0;
        }
    }
    return 1;
}
