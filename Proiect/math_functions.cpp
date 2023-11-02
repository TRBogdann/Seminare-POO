
#include "math_functions.h"

double math_functions::abs(double number)
{
    if(number<0)return -number;

    return number;
}

double math_functions::log(double number) //using mclaurin series
{

    if(number==1)
        return 0;

    double rest=0;

    //error fix 
    while(number>1) //bacause log(23)=2*ln(10)+ln(0.23), log(1123)=4*log(10)+ln(0.1123)
    {
        rest+=LOG_OF_TEN;
        number/=10.0f;
    }

    //function
    long long  step=2;
    number=number-1; //log(x)=log(1+y)=>y=x-1;

    double currentNr=-number*number;
    double res=number;
    double change=currentNr/step;

    

    while(math_functions::abs(change)>DX) //y-y^2/2+y^3/3-y^4/4+....
    {
        res+=change;

        currentNr*=-number;
        step++;

        change=currentNr/step;
    
    }

    return res+rest;
    

}

double math_functions::pow(double base, double power) //using mclaurin series
{
    
double res=1;

    if(int(power)==power) // for integer a^n=a*a*a*a...*a (n times)
    {
        if(power>0)
        for(int i=0; i<power; i++)
        {
            res*=base;
        }
        

        else    
             for(int i=0; i>power; i--)
        {
            res/=base;
        }

        return res;
    }   

    power=power*math_functions::log(base); // a ^ x = e ^ (log(a) * x);
    double change=power;
    double currentNr=power;
    long long div=1;
    long long step=1;
    
    while(math_functions::abs(change)>DX) // for real numbers => 1+x+x^2/2!+x^3/3!+x^4/4!+....
    {
        res+=change;

        step++;
        div*=step;
        currentNr*=power;

        change=currentNr/div;

    }

    return res;

}

double math_functions::sqrt(double base, double order) //using mclaurin series
{
    return math_functions::pow(base,1/order);
}