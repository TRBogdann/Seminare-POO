#include "checker.h"
#include "math_functions.h"
#include <cstring>

class Calculator
{
public:
Calculator();
~Calculator();
void evalExpr();
void setExpr(char *expr);
char* getExpr();
std::string getErrorMessage();
double getResult();
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