//errors
#define SYNTAX_ERROR 1  //done
#define UNKNOWN_SYMBOL 2 //done
#define NOT_A_FIRST_OR_SECOND_DEGREE_ECUATION 3 //not done
#define DIVISION_BY_ZERO 4 //done

//types
#define FIRST_GRADE_ECUATION 7 //not done
#define SECOND_GRADE_ECUATION 8 //not done
#define SIMPLE_EXPRESSION 9 //not done

//commands
#define EXIT 10 //done

class Checker{
public:
Checker();
~Checker();
static bool checkExit(char *str);
static bool checkDivZero(char *str);
static bool checkDots(char *str);
//static bool checkCharacters(char *str);
//static bool checkDivZero(char *str);
//static bool checkDecimals(char *str);
//static bool checkSyntax(char *str);
//static bool checkIfEcuation(char *str);
char checkExpression(char *str);
private:
static bool isOperator(char c);
static bool isParanthesis(char c);
static bool isLeftParanthesis(char c);
static bool isRightParanthesis(char c);
};