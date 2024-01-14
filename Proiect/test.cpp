#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <istream>
#include <ostream>

struct Eq
{
    double x1;
    double x2;
    std::string expr;
};

void write()
{
std::ofstream t("testBinar.dat");
Eq e;
e.x1=1.111111;
e.x2=1.22222;
e.expr="1+13";

t.write(reinterpret_cast<char*>(&e),sizeof(Eq));
t.close();
}

void read()
{
    std::ifstream t("testBinar.dat");
    Eq e;
    t.read(reinterpret_cast<char*>(&e),sizeof(Eq));
    std::cout<<e.x1<<'\n'<<e.x2<<'\n'<<e.expr;
    t.close();
}

int main() {
write();
read();
    return 0;
}