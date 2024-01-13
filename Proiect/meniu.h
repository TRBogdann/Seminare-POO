#pragma once
#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <fstream>
#define CodMeniuPrincipal 111
#define CodCitireConsola 222
#define CodCitireFisier 333
#define CodAfisareIstoric 444 

class Meniu{
public:
    virtual void ReadInput()=0; 
    virtual void Inapoi() = 0;
    virtual void SaveResult() = 0;  //aici sa vedem cum facem saveurile
protected:
    std::string input;
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
private:
    static char *y;

    //!!!!! Verificari dsa nu fie y null. daca e null, ghinion
}

char* MeniuCitireConsola::y=nullptr;

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
}

char* MeniuCitireFisier::l=nullptr;