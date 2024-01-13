#pragma once
#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <fstream>

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
    MeniuPrincipal(char* _y);
    MeniuPrincipal(const MeniuPrincipal& mp);
    MeniuPrincipal& operator=(const MeniuPrincipal& mp);
    ~MeniuPrincipal();


    //void DisplayMenu();
    void ReadInput() override;
    void Inapoi() override;
    void SaveResult() override;
    void CitireConsola();
    void CitireFisier(); 
    char* getY();
    void AfisareIstoric();
    //void FeelingLucky(rand)
    //hidden option
private:
    char *y = nullptr;
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
    void SaveResult() override;
    void InserareVariabilaVariabilaSalvata();
    char* getY();
    void Citire();

private:
    //static 
    char *y = nullptr;



    //!!!!! Verificari dsa nu fie y null. daca e null, ghinion
};