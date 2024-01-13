#include "checker.h"
#include "meniu.h"
#define _CRT_SECURE_NO_WARNINGS
#include "calculator.h"
#include "equation.h"
#include <cstring>
#include <iostream>
#include <iomanip>

void bind_objects(Calculator& calculator,MeniuPrincipal& meniuPrincipal,MeniuCitireConsola& meniuConsola)
{
 calculator.bindMenu(meniuPrincipal,meniuConsola);
 meniuConsola.bindCalculator(calculator);
 meniuPrincipal.bindCalculator(calculator);
};

Calculator::Calculator(unsigned int buffer_size):
handler(EquationHandler(buffer_size)),_buffer_size(buffer_size)
{   
  if(_buffer_size<1)
        _buffer_size=1;

  this->expression=0; 
  this->last_result=0;
  this->error_message="";

  this->last_sol={0.0f,0.0f};
  this->lastType=0;

}

Calculator::~Calculator(){
    if(this->expression)
        delete[] this->expression;
}

void Calculator::clear()
{
  if(this->expression){
        delete[] this->expression;
        this->expression=0; 
  }

  this->last_result=0;
  this->error_message="";
}


void Calculator::setExpr(char* expr)
{
    str_functions::remove_spaces(expr,this->_buffer_size);
    if(this->expression)
    {
        delete[] this->expression;
        expression=0;
    }

    this->expression=new char[strlen(expr)+1];
    strcpy(this->expression,expr);

}



std::ostream& operator<<(std::ostream& os, const Calculator& c){
    os << c.expression;
    return os;
}

std::istream& operator>>(std::istream& is, Calculator& c){
    is >>c.expression;
    return is;
}

int Calculator::getPrecision()
{
    int count=0;
    int count_zero=0;
    double aux=this->last_result;

    while(count<4 && int(aux)!=aux){
        aux*=10.0f;
        if(int(aux)%10==0)count_zero++;
        count++;
    }

    if(count_zero==4)return 0;

    return count;

};

void Calculator::printResult()
{
    
    if(this->error_message!="")
    {   
        std::cout<<this->error_message<<'\n';
        return;
    }

    if(this->lastType==0){
    std::cout<<"Result: ";
    int precision=getPrecision();
    std::cout << std::fixed;
    std::cout<<std::setprecision(precision)<<this->last_result<<'\n';
    return;
    }

    std::cout<<"Solutii: \n";
    if(last_sol.x2==last_sol.x1){
    std::cout<<"x= "<<last_sol.x1<<'\n';
    }
    else{
    std::cout<<"x1= "<<last_sol.x1<<'\n';
    std::cout<<"x2= "<<last_sol.x2<<'\n';
    }

}

void Calculator::loop()
{   
    char *buffer=new char[_buffer_size+1];
    this->clear();
    while(this->error_message!="Exiting program")
    {
        std::cout<<"Read Expression: ";
        std::cin.getline(buffer,_buffer_size+1);
        this->setExpr(buffer);
        this->evalExpr();
        this->printResult();
    }
    this->clear();
    delete[] buffer;
}


char* Calculator::getExpr(){
    return expression;
}


Checker Calculator::getChecker(){
    return checker;
}

std::string Calculator::getErrorMessage(){return this->error_message;}
double Calculator::getResult(){return this->last_result;}


void Calculator::setChecker(Checker check){
    this->checker = check;
}


void Calculator::evalExpr()
{
    int type=checker.checkExpression(this->expression);
    bool equation =0;
    switch (type) {
        case SYNTAX_ERROR:
            this->error_message="SYNTAX ERROR";
            break;
        
        case UNKNOWN_SYMBOL:
            this->error_message="UNKNOWN SYMBOL";
            break;
        
        case EXIT:
            this->error_message="Exiting program";
            break;
        
        case DIVISION_BY_ZERO:
            this->error_message="DIV_0";
            break;
        
        case ECUATION:
            this->error_message="";
            equation=1;
            break;
        
        default:
            this->error_message="";
    }
    
    if(error_message==""){
        if(!equation)
            last_result=math_functions::evalSeg(this->expression,strlen(this->expression),0,this->error_message);
        else 
            {
                handler.setEquation(this->expression);
                int degree=1+(handler.getCoeficientOf(2)!=0);
                double *params=new double[4];
                if(degree==1)
                {
                    params[0]=0;
                    params[1]=handler.getCoeficientOf(1);
                    params[2]=handler.getCoeficientOf(0);
                    params[3]=0;
                }

                if(degree==2)
                {
                    params[0]=handler.getCoeficientOf(2);
                    params[1]=handler.getCoeficientOf(1);
                    params[2]=handler.getCoeficientOf(0);
                    params[3]=0;
                }
                
                std::cout<<'\n'
                    <<"a="<<params[0]<<"\n"
                    <<"b="<<params[1]<<"\n"
                    <<"c="<<params[2]<<"\n"
                    <<"d="<<params[3]<<'\n'
                    <<'\n';
                Equation eq(degree,'x',params);
                this->last_sol=eq.getSolutii(&error_message);
            };
    }

    if(error_message=="eq"){
        this->handler.setEquation(this->expression);
    }

    lastType=equation;
}

Calculator::Calculator(const Calculator& c):
handler(c.handler),_buffer_size(c._buffer_size),
checker(c.checker),last_result(c.last_result),
lastType(c.lastType),last_sol(c.last_sol),
error_message(c.error_message)
{
    this->expression=new char[strlen(c.expression)+1];
    strcpy(this->expression,c.expression);
};

Calculator& Calculator::operator=(const Calculator& c)
{
    this->handler=c.handler;
    this->_buffer_size=c._buffer_size;
    this->checker=c.checker;
    this->lastType=c.lastType;
    this->historyFile=c.historyFile;
    this->error_message=c.error_message;
    this->last_sol=c.last_sol;
    this->last_result=c.last_result;
    if(this->expression)
    {
        delete[] this->expression;
        this->expression=0;
    }
    this->expression=new char[strlen(c.expression)+1];
    strcpy(this->expression,c.expression);

    return *this;
}

solutii Calculator::getSolutii()
{
    return this->last_sol;
}
char Calculator::getType()
{
    return this->lastType;
}
int Calculator::getBufferSize()
{
    return this->_buffer_size;
}
EquationHandler Calculator::getHandler()
{
    return this->handler;
}

void  Calculator::setHandler(EquationHandler _handler)
{
    this->handler=_handler;
}

void Calculator::setBufferSize(int buffer_Size)
{
    if(buffer_Size>this->_buffer_size)
        this->_buffer_size=buffer_Size;
}

void Calculator::bindMenu(MeniuPrincipal& meniuPrincipal,MeniuCitireConsola& meniuConsola)
{
    this->mp=&meniuPrincipal;
    this->mc=&meniuConsola;
}