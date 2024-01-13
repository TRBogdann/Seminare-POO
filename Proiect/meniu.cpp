#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <fstream>
#include "meniu.h"


    MeniuPrincipal::MeniuPrincipal(char* _y){
        y = new char[strlen(_y) + 1];
        strcpy(y,_y);
    }

    MeniuPrincipal::MeniuPrincipal(const MeniuPrincipal& mp){
        y=new char[strlen(mp.y) + 1];
        strcpy(y, mp.y);
    }

    MeniuPrincipal& MeniuPrincipal::operator=(const MeniuPrincipal& mp){
        if(this != &mp){
            if(y!=NULL){
                delete[] y;
            }
            y=new char[strlen(mp.y) + 1];
            strcpy(y,mp.y);
            return *this;
        }
        else return *this;
    }

    MeniuPrincipal::~MeniuPrincipal(){
        delete[] y;
    }

    void MeniuPrincipal::Inapoi(){
        //Iese din program, functioneaza ca un IESIRE()
        exit(0); 
    } 

    void MeniuPrincipal::CitireConsola(){
        //curata consola
        system("CLS");
        std::cout<<std::flush <<'\n';
        //creeaza nou obiect din clasa respectiva
        };
    void MeniuPrincipal::CitireFisier(){
        //curata consola
        system("CLS");
        std::cout<<std::flush <<'\n';
        //afiseaza fisierul de citire din fisier
               
    };

    void MeniuPrincipal::AfisareIstoric(){
        system("CLS");
        std::cout<<std::flush <<'\n';
        //creeare obj istoric
        //care contine
        // inapoi
    }

    void MeniuPrincipal::ReadInput(char* input){
        switch(y[0]){
            case '1':
                MeniuPrincipal::CitireConsola();
                break;
            case '2':
                MeniuPrincipal::CitireFisier();
                break;   
            case '3':
                MeniuPrincipal::AfisareIstoric();
                break;
            case '4':
                MeniuPrincipal::Inapoi();
                break;
        }
    }

    char* MeniuPrincipal::getY(){ return y;}


    //------------------------------------------------------------------------

    MeniuCitireConsola::MeniuCitireConsola(char* _y){
        y = new char[strlen(_y) + 1];
        strcpy(y,_y);
    }

    MeniuCitireConsola::MeniuCitireConsola(const MeniuCitireConsola& mcc){
        y=new char[strlen(mcc.y) + 1];
        strcpy(y, mcc.y);
    }

    MeniuCitireConsola& MeniuCitireConsola::operator=(const MeniuCitireConsola& mcc){
        if(this != &mcc){
            if(y!=NULL){
                delete[] y;
            }
            y=new char[strlen(mcc.y) + 1];
            strcpy(y,mcc.y);
            return *this;
        }
        else return *this;
    }

    MeniuCitireConsola::~MeniuCitireConsola(){
        delete[] y;
    }

    void MeniuCitireConsola::ReadInput(char* input){  //scot din asta si citesc ca e deja atribut in clasa abstr.
        //citire input
        switch(input[0]){
            case 'y':
                MeniuCitireConsola::InserareVariabilaVariabilaSalvata();
                break;
            case '2':
                MeniuCitireConsola::SaveResult();
                break;   
            case '3':
                MeniuCitireConsola::Citire();
                break;
            case '4':
                MeniuCitireConsola::Inapoi();
                break;
        }
    }
    

     void MeniuCitireConsola::Inapoi(){
        system("CLS");
        std::cout<<std::flush <<'\n';
        //Iese din program, functioneaza ca un IESIRE()
    } 

    void MeniuCitireConsola::SaveResult(){ 
        //salveaza in fisier rezultate
    }

    void MeniuCitireConsola::InserareVariabilaVariabilaSalvata(/*y, char* expresie*/){ 
        //insereaza in ecuatie variabila salvata
        //
    }

    void MeniuCitireConsola::Citire(/*char* expresie*/){
        //if(citire consola)
        //citire expresie
        //else{ desxhizi fisierul text si afisezi acolo       }
    }