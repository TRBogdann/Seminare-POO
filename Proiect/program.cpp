#include <cstring>
#include <iostream>


double string_to_double(char *str,int n)
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

double evalExprt(char *str,int len,char flag=0)
{   double res=0;
    int r;
    int l;
    

    int i=0;
    while(i<len)
    {

    }

    return res;
}

 

int main()
{




    return 0;
}