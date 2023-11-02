#include <cstring>
#include <iostream>
#include "calculator.h"

int main()
{
Calculator c;
c.setExpr((char*)"{{1.23*12^(1+1)+[123.1^2.1]}+1}+1");
std::cout<<c.evalExpr();
    


    return 0;
}