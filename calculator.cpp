#include "checker.h"
#include "calculator.h"
#include "cstring"
#include <iostream>

void Calculator::evalExpr(){
    //?? nuj ce vine aici
}

void Calculator::setExpr(char *expr){
    expression = new char(255);
    expression = expr;
    delete[] expr;
}

Calculator::~Calculator(){
    delete[] expression;
}