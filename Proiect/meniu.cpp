#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <fstream>
#include "meniu.h"

    void MeniuPrincipal::DisplayMenu(){
        std::ifstream file("MeniuPrincipal.txt");
        std::string line;
        while (getline(file, line)) 
            std::cout << line << '\n';
        file.close();
    }

    void MeniuPrincipal::Inapoi(){
        //Iese din program, functioneaza ca un IESIRE()
        exit(0); 
    } 

    int MeniuPrincipal::CitireConsola(){
        //curata consola
        system("CLS");
        std::cout<<std::flush <<'\n';
        return CodCitireConsola;
        };
    int MeniuPrincipal::CitireFisier(){
        //curata consola
        system("CLS");
        std::cout<<std::flush <<'\n';
        return CodCitireFisier;
               
    };

    int MeniuPrincipal::AfisareIstoric(){
        system("CLS");
        std::cout<<std::flush <<'\n';
        return CodAfisareIstoric;
    }

    void MeniuPrincipal::FeelingLucky(){
        int r= 1 + rand() % 5;
        switch(r){
            case 1:
                MeniuPrincipal::CitireConsola();
                break;
            case 2:
                MeniuPrincipal::CitireFisier();
                break;   
            case 3:
                MeniuPrincipal::AfisareIstoric();
                break;
            case 4:
                MeniuPrincipal::Inapoi();
                break;
            // case '5':
            //     MeniuPrincipal::HiddenOption();
            //     break;
        }
    }

    void MeniuPrincipal::ReadInput(){
        std::cin>>input;
        switch(input[0]){
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
            // case '5':
            //     MeniuPrincipal::HiddenOption();
            //     break;
            case '?':
                MeniuPrincipal::FeelingLucky();
                break;
            default:
                std::cout<<"Unknown input, please choose from the list. Try again."<<std::endl;
                system("CLS");
                std::cout<<std::flush <<'\n';
                MeniuPrincipal::ReadInput();
                break;
        }
    }



    //------------------------------------------------------------------------



    MeniuCitireConsola::MeniuCitireConsola(char* _y){
        if(_y!=nullptr){
        y = new char[strlen(_y) + 1];
        strcpy(y,_y);
        }
    }

    void MeniuPrincipal::SaveResult()
    {

    };

    MeniuCitireConsola::MeniuCitireConsola(const MeniuCitireConsola& mcc){
        if(mcc.y != nullptr ){
        y=new char[strlen(mcc.y) + 1];
        strcpy(y, mcc.y);
    }
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
        if(y!=nullptr){
        delete[] y;
        }
    }

    void MeniuCitireConsola::ReadInput(){  //scot din asta si citesc ca e deja atribut in clasa abstr.
        std::cin>>input;
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
             default:
                std::cout<<"Unknown input, please choose from the list. Try again."<<std::endl;
                system("CLS");
                std::cout<<std::flush <<'\n';
                MeniuCitireConsola::ReadInput();
                break;
        }
    }
    
    void MeniuCitireConsola::Inapoi()
    {

    };

     int MeniuCitireConsola::InapoiMP(){
        system("CLS");
        std::cout<<std::flush <<'\n';
        return CodMeniuPrincipal;
    } 

    void MeniuCitireConsola::SaveResult(){ 
        //salveaza in fisier rezultate
        std::cout<<"\nSalvati rezultatul?(da/nu)\n";
            std::string dn;
            std::cin>>dn;
            if( dn == "da") {
                //salvam rezultatul in y   
            }
    }

    int MeniuCitireConsola::InserareVariabilaVariabilaSalvata(/*y, char* expresie*/){
        system("CLS");
        std::cout<<std::flush <<'\n';
        std::cout<<"Unde afisati rezultatele? (fisier/cosola)"<< '\n';
        std::string fc;
        std::cin>>fc;
        if( fc == "consola"){
            system("CLS");
            std::cout<<std::flush <<'\n';
            std::cout<<"Scrieti expresia: "<<'\n';
            std::cout<<y<<' ';
            //insereaza in ecuatie variabila salvata
            //calculeaza ecuatia
            MeniuCitireConsola::SaveResult();
        }
        if(fc == "fisier"){
            std::ifstream Rezfile("Rezultate.txt");
            std::string Rezline;
            //calculeaza expresia
            //o pune in fisier pe o linie noua
            //mai jos afiseaza linia respectiva
            while (getline(Rezfile, Rezline)) {
                std::cout << Rezline << std::endl;
            }

            // Close the file
            Rezfile.close();
            system("CLS");
            std::cout<<std::flush <<'\n';
            MeniuCitireConsola::SaveResult();
        }
        else {
            std::cout<<"\nCalea oferita nu este o optiune. Va rugam incercati din nou."<<std::endl;
        }
        return CodCitireConsola;
    }

    int MeniuCitireConsola::Citire(/*char* expresie*/){
        system("CLS");
        std::cout<<std::flush <<'\n';
        
        std::cout<<"Unde afisati rezultatele? (fisier/cosola)"<< '\n';
        std::string fc;
        std::cin>>fc;
        if( fc == "consola"){
            system("CLS");
            std::cout<<std::flush <<'\n';
            std::cout<<"Scrieti expresia: "<<'\n';
            //insereaza in ecuatie variabila salvata
            //calculeaza ecuatia
            MeniuCitireConsola::SaveResult();
        }
        if(fc == "fisier"){
            std::ifstream Rezfile("Rezultate.txt");
            std::string Rezline;
            //calculeaza expresia
            //o pune in fisier pe o linie noua
            //mai jos afiseaza linia respectiva
            while (getline(Rezfile, Rezline)) {
                std::cout << Rezline << std::endl;
            }
            MeniuCitireConsola::SaveResult();
            // Close the file
            Rezfile.close();            
        }
        else {
            std::cout<<"Calea oferita nu este o optiune. Va rugam incercati din nou"<<std::endl;
        }
        return CodCitireConsola;
    }

    char* MeniuCitireConsola::y=nullptr;