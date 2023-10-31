#include "equation.h"
#include "math_functions.h"
#include "operators.h"
#include "checker.h"
#include "calculator.h"
//#include <iostream>
#include <cstring>
#include <iostream>

void Equation::setUnk(char Unk){
    this->Unk=Unk;
}
void Equation::setA(double a){
    this->a=a;
}

void Equation::setB(double b){
    this->b=b;
}

void Equation::setC(double c){
    this->c=c;
}

void Equation::setD(double d){
    this->d=d;
}

void Equation::setDegree(int degree){
    this->degree=degree;
}

Equation::Equation(const Equation& e){
    Unk=e.Unk;
    a=e.a;
    b=e.b;
    c=e.c;
    d=e.d;
    degree=e.degree;
}

std::ostream& operator<<(std::ostream& os, const Equation& e){
    switch (e.degree)
    {
    case 1:
        os << e.b << "*" << e.Unk << "+(" << e.c << ")="<<e.d<< "  " << e.degree <<"st degree ecuation"; 
        break;
    case 2:
        os << e.a << "*" << e.Unk <<"^2+("<< e.b<<")*"<<e.Unk<<"+(" << e.c << ")="<<e.d<< "  " << e.degree <<"nd degree ecuation";
        break;
    default:
        os<< "SYNTAX_ERROR Unknown degree!!";
        break;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Equation& e){
    is>>e.degree>>e.Unk;
    if(e.degree == 2)
        is>>e.a>>e.b>>e.c>>e.d;
    if(e.degree == 1)
        is>>e.b>>e.c>>e.d;
    return is;
}

Equation& operator!(const Equation& e){
    Equation e1;
    e1.a = (-1)*e.a;
    e1.b = (-1)*e.b;
    e1.c = (-1)*e.c;
    e1.d = (-1)*e.d;
    return e1;
}

Equation &operator^(const Equation &e, float y)
{   Equation e1(e);
    e1.a = math_functions::pow(e.a, y);
    e1.b = math_functions::pow(e.b, y);
    e1.c = math_functions::pow(e.c,y);
    e1.d = math_functions::pow(e.d,y);
    return e1;
}

double Equation::f_degree(const Equation& e){
    return ((e.c-e.d)/e.b);
}

solutii Equation::s_degree(const Equation& e){
    solutii s;
    s.x1= !(e.b)/(2*e.a) + math_functions::sqrt(((e^2).b-4*e.a*e.c),2)/(2*e.a);
    s.x2= !(e.b)/(2*e.a) - ((e^2).b-4*e.a*e.c)/(2*e.a);
    return s;
}

