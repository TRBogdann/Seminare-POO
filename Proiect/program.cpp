#define _CRT_SECURE_NO_WARNINGS
#include <cstddef>
#include <cstring>
#include <iomanip>
#include <iostream>
#include "calculator.h"

int main()
{

Calculator c(500);
c.loop();

EquationHandler eq(500);
char* test0=new char[10];
strcpy(test0,"(x+1)^2=1");
char* test1=new char[23];
strcpy(test1,"x+2.12*5*(1+x)+(1+x)=2");
char* test2=new char[18];
strcpy(test2,"x+(x+1)*(x+1)+1=3");
char* test3=new char[22];
strcpy(test3,"x+x+1+2*[1+(1+x)*2]=4");
char* test4=new char[24];
strcpy(test4,"x+[x+2*(1+x)*(2+x)]=5");

eq.setEquation(test0);
eq.getCoeficientOf(0);
eq.setEquation(test1);
eq.getCoeficientOf(0);
eq.setEquation(test2);
eq.getCoeficientOf(0);
eq.setEquation(test3);
eq.getCoeficientOf(0);
eq.setEquation(test4);
eq.getCoeficientOf(0);



    return 0;
}