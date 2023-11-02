#include "calculator.h"

Calculator::Calculator()
{
    
}

Calculator::~Calculator()
{

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

    int i=0;


    //Layer1
    while(i<len && !Checker::isParanthesis(str[i]) && !(Checker::isOperator(str[i]) && str[i]!='.'))i++;
    if(i==len){
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
    this->expression=new char[strlen(expr)+1];
    strcpy(this->expression,expr);
}

char *Calculator::getExpr()
{
    return this->expression;
}

double Calculator::evalExpr()
{
    return evalSeg(this->expression,strlen(this->expression),0);
}