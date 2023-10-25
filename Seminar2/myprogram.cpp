#include <iostream>
using namespace std;


 
class Student{

 public:

 Student(){

 };
 ~Student(){

 };

 void calcmedie()
 {
   this->medie= (this->nota1 + this-> nota2 + this->nota3) / 3; 
 };

string nume;
 int CNP;
 int nota1,nota2,nota3;
 float medie;
 
 private:

};


int main()
{
 Student s;
 cin>> s.nota1 >> s.nota2 >> s.nota3 ;
 s.calcmedie();
 cout << s.medie << endl;
	return 0;
};