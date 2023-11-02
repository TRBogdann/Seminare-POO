#include "checker.h"
#include "calculator.h"
#include "cstring"
#include <iostream>

Calculator::Calculator(char* expr){
    expression= new char[strlen(expr) + 1]; 
    this->expression = expr;
    delete[] expr;
}

Calculator::~Calculator(){
    delete[] expression;
}

char* Calculator::getExpression(){
    return expression;
}

Checker Calculator::getChecker(){
    return checker;
}

void Calculator::setChecker(Checker check){
    this->checker = check;
}

void Calculator::setExpr(char *expr){
    expression = new char(255);
    expression = expr;
    delete[] expr;
}

std::ostream& operator<<(std::ostream& os, const Calculator& c){
    os << c.expression;
    return os;
}

std::istream& operator>>(std::istream& is, Calculator& c){
    is >>c.expression;
    return is;
}

void Calculator::evalExpr(){
    //?? nuj ce vine aici
}
