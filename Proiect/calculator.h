#include "checker.h"
#include "math_functions.h"
#include <cstring>

class Calculator
{
public:
Calculator();
~Calculator();
double evalExpr();
void setExpr(char *expr);
char* getExpr();

private:
Checker checker;
char *expression;
double evalSeg(char *str,int len,char flag);
double string_to_double(char *str,int len);

};