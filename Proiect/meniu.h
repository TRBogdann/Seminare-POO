#pragma once
#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <string>
#include <fstream>

//folosit la reintoarcerea in meniu
#define CodMeniuPrincipal 100

#define CodCitireConsola 200
#define CodCitireEcuatie 210

#define CodCitireFisier 300

#define CodAfisareIstoric 400


struct Rezultat_expr
{
    double res;
    std::string expr;
};

struct Rezultat_eq
{
    double x1;
    double x2;
    std::string expr;
};

class Calculator;

class Meniu{
public:
    virtual int ReadInput()=0; 
    virtual void Inapoi() = 0;
    virtual void SaveResult() = 0;  //aici sa vedem cum facem saveurile
    void bindCalculator(Calculator &calculator);
    void writeRes();
protected:
    std::string input;
    Calculator *calc=nullptr;
};

class MeniuPrincipal : public Meniu{
public:
    MeniuPrincipal();
    void DisplayMenu();
    int ReadInput() override;
    void Inapoi() override;
    int CitireConsola();
    int CitireFisier(); 
    void FeelingLucky();
    //void HiddenOption();
    void SaveResult() override;
    int AfisareIstoric();
};

class MeniuCitireConsola : public Meniu{
public:
    MeniuCitireConsola();
    ~MeniuCitireConsola();

    void DisplayMenu();
    int ReadInput() override;
    int InapoiMP();
    void SaveResult() override;
    int InserareVariabilaVariabilaSalvata();
    char* getY();
    int Citire();
    void Inapoi() override;
    friend class MeniuCitireFisier;
private:
    static char *y;

    //!!!!! Verificari dsa nu fie y null. daca e null, ghinion
};

class MeniuCitireFisier : public Meniu{
public:
    MeniuCitireFisier();
    ~MeniuCitireFisier();

    void DisplayMenu();
    int ReadInput() override;
    int InapoiMP();
    void SaveResult() override;
    void Inapoi() override;
    int Citire();
    friend class MeniuCitireConsola;
private:
    static char* l;
};


