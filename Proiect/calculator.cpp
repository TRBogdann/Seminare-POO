#include "calculator.h"
#include "checker.h"
#include "cstring"
#include <iostream>

Calculator::Calculator()
{

  this->expression=0; 
  this->last_result=0;
  this->error_message="";
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

void Calculator::printSegment(char *str,int len)
{
    int i=0;
    while(i<len)
    {
        std::cout<<str[i];
    }
    std::cout<<'\n';
}

void Calculator::setExpr(char* expr)
{
    remove_spaces(expr);
    
    if(this->expression)
    {
        delete[] this->expression;
        expression=0;
    }

    this->expression=new char[strlen(expr)+1];
    strcpy(this->expression,expr);

}

void Calculator::remove_spaces(char *str)
{
    int i=0;
    while(i<strlen(str))
    {
        if(str[i]==' ')
            strcpy(str+i,str+i+1);

        else i++;
    }
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

    std::cout<<"Result: ";
    int precision=getPrecision();
    std::cout << std::fixed;
    std::cout<<std::setprecision(precision)<<this->last_result<<'\n';
}

void Calculator::loop(char buffer[],int buffer_size)
{
    this->clear();
    while(this->error_message!="Exiting program")
    {
        std::cout<<"Read Expression: ";
        std::cin.getline(buffer,buffer_size);
        this->setExpr(buffer);
        this->evalExpr();
        this->printResult();
    }
    this->clear();
}

char* Calculator::getExpr(){
    return expression;
}


Checker Calculator::getChecker(){
    return checker;
}

double Calculator::string_to_double(char *str,int len)
{
    double res=0;
    bool dot=0;
    int p=10;
    for(int i=0;i<len;i++)
    {
        
        if(str[i]=='.')dot=1;
        else
         {
            double num=str[i]-'0';
            if(!dot)
                res=res*10+num;
            else
            {
                res+=num/p;
                p*=10;
            }
         };
    }
    return res;
};


void Calculator::setChecker(Checker check){
    this->checker = check;
}

double Calculator::evalSeg(char *str,int len,char flag)
{   
    double res=0;
    

    int left_countpr=0,right_countpr=0;  //counts () pairs
    int left_countpsq=0,right_countpsq=0; //counts [] pairs
    int left_countpss=0,right_countpss=0; //counts {} pairs

    int i=0;
    bool sign=0;

    //Layer1
    
    if(str[i]=='-' && i==0)
    {
        i++;
        sign=1;
    }
    

    while(i<len && !Checker::isParanthesis(str[i]) && !(Checker::isOperator(str[i]) && str[i]!='.'))i++;
    if(i==len){
        if(sign) return -string_to_double(str+1, len-1);
        return string_to_double(str,len);
    }

    //Layer 2,3,4
    int start=0;
    int end;
    char ignore=0;
    char operator1, operator2;
    char newFlag;
    bool prev=0;
    bool insideParantethis=0;
    
    

    if(flag==0)
    {
        operator1='+';
        operator2='-';
    }

        if(flag==1)
    {
        operator1='*';
        operator2='/';
    }
        
         if(flag==2)
    {
        operator1='^';
        operator2='#';
    }

    i=0;
    char originalFlag = flag; 
        newFlag = flag + 1;
 

    while(i<len)
    {
        
        if((str[i]==operator1 || str[i]==operator2) && !insideParantethis) 
        {
            if(ignore==0){
            newFlag=originalFlag;
            end=i-1;
            //printSegment(&str[start],end-start+1);
            if(!prev){
                
                res+=evalSeg(&str[start],end-start+1,0);
                
            }

            else 
            switch(str[start-1])
            {
            case '+':
                res+=evalSeg(&str[start],end-start+1,0);
                break;
            case '-':
                res-=evalSeg(&str[start],end-start+1,0);
                break;
            case '*':
                res*=evalSeg(&str[start],end-start+1,0);
                break;
            case '/':
                res/=evalSeg(&str[start],end-start+1,0);
                break;
            case '^':
                res=math_functions::pow(res,evalSeg(&str[start],end-start+1,0));
                break;
            case '#':
                res=math_functions::sqrt(res,evalSeg(&str[start],end-start+1,0));
                break;
            }

        prev=1;
        start=i+1;
            }

             if(ignore==2){
            if(Checker::isParanthesis(str[i-1]))
                end=i-2;

            else
                 {
                start--;
                end=i-1;
            }

            newFlag=originalFlag;

           // printSegment(&str[start],end-start+1);

            if(!prev){
            res+=evalSeg(&str[start],end-start+1,0);
            }

            else switch(str[start-2])
            {
            case '+':
                res+=evalSeg(&str[start],end-start+1,0);
                break;
            case '-':
                res-=evalSeg(&str[start],end-start+1,0);
                break;
            case '*':
                res*=evalSeg(&str[start],end-start+1,0);
                break;
            case '/':
                res/=evalSeg(&str[start],end-start+1,0);
                break;
            case '^':
                res=math_functions::pow(res,evalSeg(&str[start],end-start+1,0));
                break;
            case '#':
                res=math_functions::sqrt(res,evalSeg(&str[start],end-start+1,0));
                break;
            }
            prev=1;
            ignore=0;
            start=i+1;
            }
            
            
        }

        switch(str[i])
        {
            case '(':
                if(ignore==0)
                {
                if(i==0 || !(str[i]!=operator1 || str[i]!=operator2))
                {
                ignore=1;
                start=i+1;
                }
                }

                left_countpr++;
                break;

          case ')':
                right_countpr++;
                break;

         case '[':
                if(ignore==0) {
                    if(i==0 || !(str[i]!=operator1 || str[i]!=operator2))
                {
                ignore=1;
                start=i+1;
                }
                }
                left_countpsq++;
                break;

          case ']':
                right_countpsq++;
                break;

         case '{':
                if(ignore==0) {
                  if(i==0 || !(str[i]!=operator1 || str[i]!=operator2))
                {
                ignore=1;
                start=i+1;
                }
                }
                left_countpss++;
                break;

          case '}':
                right_countpss++;
                break;



        }

            insideParantethis=0;
           if(left_countpr!=right_countpr)insideParantethis=1;
           if(left_countpsq!=right_countpsq)insideParantethis=1;
           if(left_countpss!=right_countpss)insideParantethis=1;

        if(ignore==1)
        {   
            ignore=2;
            if(left_countpr!=right_countpr)ignore=1;
            if(left_countpsq!=right_countpsq)ignore=1;
            if(left_countpss!=right_countpss)ignore=1;
        }

        i++;

        if(i==len)
        {
            if(originalFlag==newFlag)
            {
                end=len-1;
                int num=1;
                if(ignore==2)
                {
                    end=len-2;
                    num=2;
                }
            if(start<2)
                res+=evalSeg(&str[start],end-start+1,0);
            //printSegment(&str[start],len-start);
             switch(str[start-num])
            {
            case '+':
                res+=evalSeg(&str[start],end-start+1,0);
                break;
            case '-':
                res-=evalSeg(&str[start],end-start+1,0);
                break;
            case '*':
                res*=evalSeg(&str[start],end-start+1,0);
                break;
            case '/':
                res/=evalSeg(&str[start],end-start+1,0);
                break;
            case '^':
                res=math_functions::pow(res,evalSeg(&str[start],end-start+1,0));
                break;
            case '#':
                res=math_functions::sqrt(res,evalSeg(&str[start],end-start+1,0));
                break;
            }
                
            }
        }
    }
    

    
    
    if(newFlag==3)
    {   
        res+=evalSeg(&str[1],len-2, 0);
        
    }

    if(newFlag>3) return 0;

   

    if(originalFlag!=newFlag)
        res+=evalSeg(str, len,newFlag);

     

    

    

    

    

     return res;
}


void Calculator::evalExpr()
{
    int type=checker.checkExpression(this->expression);
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
            this->error_message="Can t solve ecuations yet";
            break;
        
        default:
            this->error_message="";
    }
    
    if(error_message=="")
        last_result=evalSeg(this->expression,strlen(this->expression),0);

}