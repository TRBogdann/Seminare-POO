#include "calculator.h"

Calculator::Calculator()
{
  this->expression=0; 
  this->last_result=0;
  this->error_message="";
}

Calculator::~Calculator()
{
    if(!expression)
     delete[] expression;
}

void Calculator::clear()
{
  this->expression=0; 
  this->last_result=0;
  this->error_message="";
}

void Calculator::printResult()
{
    
    if(this->error_message!="")
    {   
        std::cout<<this->error_message<<'\n';
        return;
    }

    std::cout<<"Result: ";
    std::cout<<this->last_result<<'\n';
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

double Calculator::string_to_double(char *str,int n)
{
    double res=0;
    int dot=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='.')dot=10;

        else
         {
            double decimal=(str[i]-'0');
            if(dot==0)
             res=res*10+decimal;

            else
             {
                res+=decimal/dot;
                dot*=10;
             };


        };
    }
    return res;
}

double Calculator::evalSeg(char *str,int len,char flag)
{   
    double res=0;
    

    int left_countpr=0,right_countpr=0;  //counts () pairs
    int left_countpsq=0,right_countpsq=0; //counts [] pairs
    int left_countpss=0,right_countpss=0; //counts {} pairs

    bool sign=0;
    int i=0;


    //Layer1
    if(str[i]=='-' && !i)
    {
        i++;
        sign=1;
    }

    while(i<len && !Checker::isParanthesis(str[i]) && !(Checker::isOperator(str[i]) && str[i]!='.'))i++;
    
    if(i==len){

        if(sign) return -string_to_double(str+1,len-1);
        
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
            switch(str[i])
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

            else switch(str[i])
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

void Calculator::setExpr(char *expr)
{   
    if(!expression)delete[] expression;

    this->expression=new char[strlen(expr)+1];
    strcpy(this->expression,expr);

}

char *Calculator::getExpr()
{
    return this->expression;
}

void Calculator::evalExpr()
{
    int type=checker.checkExpression(this->expression);

    switch (type) {
        case UNKNOWN_SYMBOL:
            this->error_message="UNKNOWN SYMBOL";
            break;

        case SYNTAX_ERROR:
            this->error_message="SYNTAX ERROR";
            break;

        case DIVISION_BY_ZERO:
            this->error_message="DIV_0";
            break;

        case NOT_A_FIRST_OR_SECOND_DEGREE_ECUATION:
            this->error_message="Incorrect input or input unsupported";
            break; 

        case EXIT:
            this->error_message="Exiting program";
            break;

        default:
            this->error_message="";
    }

    if(this->error_message=="")
        this->last_result=evalSeg(this->expression,strlen(this->expression),0);
}

std::string Calculator::getErrorMessage()
{
    return this->error_message;
}

double Calculator::getResult()
{
    return this->last_result;
}