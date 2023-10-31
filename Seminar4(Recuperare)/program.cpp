#include <iostream>
#include <cstring>
#include <string>

using namespace std;

enum Finantare 
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};


class Student
{
	string nume;
	char* adresa;
	int varsta;
	int an_studii;
public:


	//constructori
	Student() 
	{
	
	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, Finantare _finantare): 
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->adresa = new char[strlen(_adresa)+1];
 		strcpy(this->adresa,  _adresa);

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleazza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer

	/*
	Student(const Student& student):
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{
	
	}
	*/

	 //Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
	//				- copierea valorilor (in noul obiect) sa se realizeze corect  
	//              - dezalocarea memoriei sa se realizeze fara a genera exceptii
	
	/*
	Student(const Student& student)
	{

	}
	*/
	void set_nume(std::string _nume)
	{
		nume = _nume;
	}

	void set_varsta(int _varsta)
	{
		varsta=_varsta;
	}

	void set_an(int _an)
	{
		an_studii=_an;
	}
	void set_adresa(char* adr)
	{
			adresa = new char[strlen(adr)+1];
			strcpy(adresa, adr);
	}

	//setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note;

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	void set_numar_matricol(string _nr_matricol)
	{
		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(Finantare _finantare)
	{
		this->finantare = _finantare;
	}


	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	Finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		if(adresa) 
			delete this->adresa;
		
		if(note) 
			delete this->note;
	}

private:
	int* note;
	string numar_matricol;
	Finantare finantare;
	int numar_materii;


};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	Student s0;

	s0.set_nume("Anghel Mihai");

	s0.set_adresa((char*)"Bucuresti Sector1");


	s0.set_varsta(21);
	s0.set_an(2);

	//de ce este generata eroarea?
	//s0.note = new int[20];

	s0.set_numar_matricol("A689867");
	s0.set_finantare(Finantare::BUGET_BURSA);

	// discutie eroare invalid heap pointer
	int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	s0.set_note(note, 10);


	Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", Finantare::BUGET_BURSA);

	Student s2 = s1;
	s2.set_nume("Ionescu C") ;

	return 0;
}