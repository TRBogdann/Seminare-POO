#pragma once
#include "checker.h"
#include <cstring>
#include <iostream>

class Calculator{
public:
//Constructor/ Destructor
Calculator();
Calculator(char* expression);
~Calculator();
//Getter
char* getExpression();
Checker getChecker();
//Setter
void setExpr(char *expr);
void setChecker(Checker checker);
//Overload
friend std::ostream& operator<<(std::ostream& os, const Calculator& c);
friend std::istream& operator>>(std::istream& is, Calculator& c);
//Metode diverse
void evalExpr();

private:
Checker checker;
char *expression;
};