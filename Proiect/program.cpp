#include <cstring>
#include <iomanip>
#include <iostream>
#include "calculator.h"

void modifyEcuation(char* equation)
{
 
}

void simplifyEcuation(char* equation)
{

}

void reorderEcutation(char* equation)
{

}

char* multiplyEcuations(char* eq1,char* eq2)
{
    char eq[500];
    char *finalEq;

    strcpy(eq,"");

    int start1=0,start2=0;
    int end1=0,end2=0;

    int i=0;
    int j=0;

    while(i<strlen(eq1))
    {
        if(eq1[i]=='+' || eq1[i]=='-')
        {

        }
        i++;
    }


    return finalEq;
}

int main()
{
Calculator c;
char buffer[500];
c.loop(buffer,500);


    return 0;
}