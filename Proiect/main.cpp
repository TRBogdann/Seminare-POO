#include "calculator.h"
#include "meniu.h"
#include <vector>

int main(int argc, char**argv)
{
std::vector<float> v1;
Calculator c(1000);
MeniuPrincipal mp;
MeniuCitireConsola mc;

bind_objects(c,mp,mc);
if(argc>1)
{
    std::cout<<argc<<'\n';
         c.clear();
    for(int i=1;i<argc;i++)
    {
     std::cout<<"Expresia"<<i<<":\n";
     c.setExpr(argv[i]);
     c.evalExpr();
     c.printResult();
    if(c.getErrorMessage()=="Exiting program")
        break;
    c.clear();
    }
}
c.loop();
    return 0;
}