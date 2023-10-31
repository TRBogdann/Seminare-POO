#include "math_functions.h"
#include "operators.h"
#include "checker.h"
#pragma once
#include "calculator.h"
//#include <iostream>
#include <cstring>
struct solutii{
    double x1;
    double x2;
};
class Equation{
private:
    char Unk;
    double a, b, c, d;
    int  degree;
public:
//Constructori
    Equation(){}
    Equation(int degree, char Unk, double b, double c, double d):a(0),b(b),c(c), d(d), degree(degree){}
    Equation(int degree, char Unk, double a, double b, double c, double d): Unk(Unk), a(a),b(b),c(c),d(d){}
    Equation(const Equation& e);
//Getteri
    char getUnk(){ return Unk;}
    double getA(){ return a;}
    double getB(){ return b;}
    double getC(){ return c;}
    double getD(){ return d;}
    int getdegree(){ return degree;}
//Setteri
    void setUnk(char Unk);
    void setA(double a);
    void setB(double b);
    void setC(double c);
    void setD(double d);
    void setDegree(int degree);
//Overloads
    friend std::ostream& operator<<(std::ostream& os,const Equation& e);
    friend std::istream& operator>>(std::istream& is, Equation& e);
    friend Equation& operator!(const Equation& e);
    friend Equation& operator^(const Equation &e, float y);
//Alte Metode
    double f_degree(const Equation& e);
    solutii s_degree(const Equation& e);
    //double n_degree(const Equation& e);
};
