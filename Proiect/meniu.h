#pragma once
#include <iostream>
#include <stdlib.h> 
#include <cstring>
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
    //2 way binding;
    Calculator *calc=nullptr;
};

class MeniuPrincipal : public Meniu{
public:
    MeniuPrincipal();
    void DisplayMenu();
    void SaveResult() override;
    void ReadInput() override;
    void Inapoi() override;
    int CitireConsola();
    int CitireFisier(); 
    int AfisareIstoric();
    void FeelingLucky();
    //void HiddenOption();
};

class MeniuCitireConsola : public Meniu{
public:
    MeniuCitireConsola();
    MeniuCitireConsola(char* _y);
    MeniuCitireConsola(const MeniuCitireConsola& mcc);
    MeniuCitireConsola& operator=(const MeniuCitireConsola& mcc);
    ~MeniuCitireConsola();

    void ReadInput() override;
    void Inapoi() override;
    int InapoiMP();
    void SaveResult() override;
    int InserareVariabilaVariabilaSalvata();
    char* getY();
    int Citire();
    friend class MeniuPrincipal;
private:
    static char *y;



    //!!!!! Verificari dsa nu fie y null. daca e null, ghinion
};


