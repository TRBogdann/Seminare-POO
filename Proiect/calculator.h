#pragma once
#include "math_functions.h"
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
char* getExpr();
Checker getChecker();
std::string getErrorMessage();
double getResult();
//Setteri
void setExpr(char *expr);
void setChecker(Checker checker);
//Overload
friend std::ostream& operator<<(std::ostream& os, const Calculator& c);
friend std::istream& operator>>(std::istream& is, Calculator& c);
//Metode diverse
void evalExpr();
void clear();
void printResult();
void loop(char *buffer,int buffer_size);

private:
Checker checker;
char *expression;
double last_result;
std::string error_message;
double evalSeg(char *str,int len,char flag);
double string_to_double(char *str,int len);


};