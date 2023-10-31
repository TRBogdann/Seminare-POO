#include "math_functions.h"
#include "operators.h"
#include "checker.h"
#include "calculator.h"
//#include <iostream>
#include <cstring>
struct solutii{
    float x1;
    float x2;
};
class Equation{
private:
    char Unk;
    double a, b, c, d;
    int  degree;
public:
//Constructori
    Equation(){}
    Equation(char Unk, float b, float c, float d):a(0),b(b),c(c), d(d){}
    Equation(char Unk, float a, float b, float c, float d): Unk(Unk), a(a),b(b),c(c),d(d){}
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
    friend std::ostream& operator>>(std::ostream& os, const Equation& e);
    friend Equation& operator!(const Equation& e);
    friend Equation& operator^(const Equation &e, float y);
//Alte Metode
    double f_degree(const Equation& e);
    solutii s_degree(const Equation& e);
    //float n_degree(const Equation& e);
};