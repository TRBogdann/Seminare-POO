#pragma once
#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <string>
#include <fstream>
#define CodMeniuPrincipal 111
#define CodCitireConsola 222
#define CodCitireFisier 333
#define CodAfisareIstoric 444 

class Calculator;


class Meniu{
public:
    virtual void ReadInput()=0; 
    virtual void Inapoi() = 0;
    virtual void SaveResult() = 0;  //aici sa vedem cum facem saveurile
    void bindCalculator(Calculator &calculator);
protected:
    std::string input;
    Calculator *calc=nullptr;
};

class MeniuPrincipal : public Meniu{
public:
    MeniuPrincipal();
    void DisplayMenu();
    void ReadInput() override;
    void Inapoi() override;
    int CitireConsola();
    int CitireFisier(); 
    int AfisareIstoric();
    void FeelingLucky();
    //void HiddenOption();
    void SaveResult() override;
};

class MeniuCitireConsola : public Meniu{
public:
    MeniuCitireConsola();
    ~MeniuCitireConsola();

    void DisplayMenu();
    void ReadInput() override;
    int InapoiMP();
    void SaveResult() override;
    int InserareVariabilaVariabilaSalvata();
    char* getY();
    int Citire();
    void Inapoi() override;
private:
    static char *y;

    //!!!!! Verificari dsa nu fie y null. daca e null, ghinion
};


class MeniuCitireFisier : public Meniu{
public:
    MeniuCitireFisier();
    ~MeniuCitireFisier();

    void DisplayMenu();
    void ReadInput() override;
    int InapoiMP();
    void SaveResult() override;
    void Inapoi() override;
    int Citire();
private:
    static char* l;
};

class AfisareIstorical : public Meniu{
public:
    
private:
};

