#include <iostream>
#include "checker.h"



int main()
{
Checker checker;

char* s=new char[100];
bool x=1;


while(x){
std::cin.getline(s,100);
int res=checker.checkExpression(s);
if(res==DIVISION_BY_ZERO) std::cout<<"DIV_ZERO ERROR";
if(res==SYNTAX_ERROR) std::cout<<"SYNTAX ERROR\n";
if(res==UNKNOWN_SYMBOL) std::cout<<"UNKNOWN SYMBOL\n";
if(res==SIMPLE_EXPRESSION) std::cout<<"CORRECT\n";
if(res==EXIT)x=0;
}


    return 0;
}