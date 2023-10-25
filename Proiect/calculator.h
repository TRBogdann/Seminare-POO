#include "checker.h"

class Calculator
{
public:
Calculator();
~Calculator();
void evalExpr();
void setExpr(char *expr);

private:
Checker checker;
char *expression;

};