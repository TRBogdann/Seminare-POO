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
    this->Unk=e.Unk;
    this->a=e.a;
    this->b=e.b;
    this->c=e.c;
    this->d=e.d;
    this->degree=e.degree;
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

double Equation::f_degree(){
    return ((c-d)/b);
}

solutii Equation::s_degree(){
    solutii s;
    s.x1= !(b)/(2*a) + math_functions::sqrt((((*this)^2).b-4*a*c),2)/(2*a);
    s.x2= !(b)/(2*a) - (((*this) ^ 2).b - 4 * a * c) / (2 * a);
    return s;
}

