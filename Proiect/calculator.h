
#include "equation.h"
#include "equationHandler.h"
#include "checker.h"
#include "str_functions.h"
#include "math_functions.h"
#include "meniu.h"
#include <cstddef>

void bind_objects(Calculator& calculator,MeniuPrincipal& meniuPrincipal,MeniuCitireConsola& meniuConsola,MeniuCitireFisier& meniuFisier);

class Calculator{
public:
//Constructor/ Destructor
Calculator(unsigned int buffer_size);
Calculator(char* expression);

Calculator(const Calculator&);
Calculator& operator=(const Calculator&);

~Calculator();
//Getter
char* getExpr();
Checker getChecker();
std::string getErrorMessage();
double getResult();
std::string getHistoryFileName();

solutii getSolutii();
char getType();
int getBufferSize();
EquationHandler getHandler();

//Setteri
void setHandler(EquationHandler _handler);
void setBufferSize(int buffer_Size);


void setExpr(char *expr);
void setChecker(Checker checker);

//Overload
friend std::ostream& operator<<(std::ostream& os, const Calculator& c);
friend std::istream& operator>>(std::istream& is, Calculator& c);

//Metode diverse
void evalExpr();
void clear();
void printResult();
void loop();
void loopF2();
void bindMenu(MeniuPrincipal& meniuPrincipal,MeniuCitireConsola& meniuConsola,MeniuCitireFisier& meniuFisier);


private:
unsigned int _buffer_size;
Checker checker;
char *expression;
char lastType;
double last_result;
solutii last_sol;
std::string error_message;
EquationHandler handler;
std::string historyFile;
int getPrecision();

//2 way bindings
MeniuPrincipal* mp=nullptr;
MeniuCitireConsola* mc=nullptr;
MeniuCitireFisier* mf=nullptr;

};