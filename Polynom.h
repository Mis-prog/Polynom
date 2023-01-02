#pragma once
#include "vector"
#include "Polynom_first.h"

using namespace std;
class Polynom :public Mnogochlen{
    friend int check(Polynom& name);
protected:
    int  n1;
    vector<double> a=vector<double>(100,0);
public:
    void set() override;
    void get();
    Polynom operator+(Polynom& name);
    Polynom operator-(Polynom& name);
    Polynom operator*(Polynom& name);
    Polynom operator/(Polynom& name);
    Polynom operator^(const int a);
    Polynom operator*();
    Polynom gsd(Polynom& left,Polynom &right);
    ~Polynom();
};

bool blank(const vector<double> &vec);
int check(Polynom& name);
