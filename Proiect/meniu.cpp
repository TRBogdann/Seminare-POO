#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <fstream>
#include "meniu.h"

void Meniu::bindCalculator(Calculator &calculator){
        this->calc=&calculator;
    }

    MeniuPrincipal::MeniuPrincipal()
    {

    };

    MeniuCitireConsola::MeniuCitireConsola()
    {

    };

    void MeniuPrincipal::SaveResult()
    {

    };

       void MeniuCitireConsola::Inapoi()
    {

    };

    char* MeniuCitireFisier::l=nullptr;
    
    char* MeniuCitireConsola::y=nullptr;


//MENIU PRINCIPAL 
    //-----------------------------------------------------------------------------

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

    int MeniuPrincipal::ReadInput(){
        std::cin>>input;
        switch(input[0]){
            case '1':
                return MeniuPrincipal::CitireConsola();
                break;
            case '2':
                return MeniuPrincipal::CitireFisier();
                break;   
            case '3':
                return MeniuPrincipal::AfisareIstoric();
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
        return 0;
    }

    int MeniuPrincipal::AfisareIstoric(){
        system("CLS");
        std::cout<<std::flush <<'\n';
        std::cout<<"[Afisare Istoric]\n\n<1> Inapoi <1/>\n\n";
        //afisare din fisierul binar al istoricului
        int a=0;
        while(a!=1){
            std::cin>>a;
        } 
        return CodMeniuPrincipal;
    }
//MENIU CITIRE CONSOLA
    //------------------------------------------------------------------------

    
    void MeniuCitireConsola::DisplayMenu(){
        system("CLS");
        std::cout<<std::flush <<'\n';
        std::ifstream file("MeniuCitireConsola.txt");
        std::string line;
        while (getline(file, line)) 
        std::cout << line << '\n';
        file.close();
    }



    MeniuCitireConsola::~MeniuCitireConsola(){
        if(y!=nullptr){
        delete[] y;
        }
    }

    int MeniuCitireConsola::ReadInput(){  
        std::cin>>input;
        switch(input[0]){
            case 'y':
                return MeniuCitireConsola::InserareVariabilaVariabilaSalvata();
                break;   
            case '2':
                return MeniuCitireConsola::Citire();
                break;
            case '3':
                return MeniuCitireConsola::InapoiMP();
                break;
             default:
                std::cout<<"Unknown input, please choose from the list. Try again."<<std::endl;
                system("CLS");
                std::cout<<std::flush <<'\n';
                MeniuCitireConsola::ReadInput();
                break;
        }
        return 0;
    }
    

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
                
                //si in l
                if(MeniuCitireFisier::l!=nullptr)
                    delete[] MeniuCitireFisier::l;
                MeniuCitireFisier::l = new char[strlen(y)+1];
                strcpy(MeniuCitireFisier::l,y);
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
            system("CLS");
            std::cout<<std::flush <<'\n';
            //calculeaza expresia
            //o pune in fisier pe o linie noua
            //mai jos afiseaza linia respectiva
            while (getline(Rezfile, Rezline)) {
                std::cout << Rezline << std::endl;
            }
            MeniuCitireConsola::SaveResult();
            Rezfile.close();            
        }
        else {
            std::cout<<"Calea oferita nu este o optiune. Va rugam incercati din nou"<<std::endl;
        }
        return CodCitireConsola;
    }

  

  //MENIU CITIRE FISIER
 //------------------------------------------------------------------------


    MeniuCitireFisier::~MeniuCitireFisier(){
        if(l!=nullptr) delete l;
    }

    void MeniuCitireFisier::DisplayMenu(){
        system("CLS");
        std::cout<<std::flush <<'\n';
        std::ifstream file("MeniuCitireFisier.txt");
        std::string line;
        while (getline(file, line)) 
        std::cout << line << '\n';
        file.close();
    }

    int MeniuCitireFisier::ReadInput(){
        std::cin>>input;
        switch(input[0]){
            case '1':
                return MeniuCitireFisier::Citire();
                break;
            case '2':
                return MeniuCitireFisier::InapoiMP();
             default:
                std::cout<<"Unknown input, please choose from the list. Try again."<<std::endl;
                system("CLS");
                std::cout<<std::flush <<'\n';
                MeniuCitireFisier::ReadInput();
                break;
        }
        return 0;
    }    

    int MeniuCitireFisier::InapoiMP(){ 
        system("CLS");
        std::cout<<std::flush <<'\n';
        return CodMeniuPrincipal;
    }

    int MeniuCitireFisier::Citire(){ 
        system("CLS");
        std::cout<<std::flush <<'\n';
        
        std::cout<<"Unde afisati rezultatele? (fisier/cosola)"<< '\n';
        std::string fc;
        std::cin>>fc;
        if( fc == "consola"){
            system("CLS");
            std::cout<<std::flush <<'\n';
            //citeste expresia
            //calculeaza ecuatia
            MeniuCitireFisier::SaveResult();
        }
        if(fc == "fisier"){
            
            system("CLS");
            std::cout<<std::flush <<'\n';
            std::ifstream Rezfile("Rezultate.txt");
            std::string Rezline;
            //calculeaza expresia
            //o pune in fisier pe o linie noua
            //mai jos afiseaza linia respectiva
            while (getline(Rezfile, Rezline)) {
                std::cout << Rezline << std::endl;
            }

            MeniuCitireFisier::SaveResult();
            Rezfile.close();            
        }
        else {
            std::cout<<"Calea oferita nu este o optiune. Va rugam incercati din nou"<<std::endl;
        }
        return CodCitireFisier;
    }

    void MeniuCitireFisier::SaveResult(){

        std::cout<<"\nSalvati rezultatul?(da/nu)\n";
            std::string dn;
            std::cin>>dn;
            if( dn == "da") {
                //salvam rezultatul in l 
                
                //si in y 
                if(MeniuCitireConsola::y!=nullptr)
                    delete[] MeniuCitireConsola::y;
                MeniuCitireConsola::y = new char[strlen(l)+1];
                strcpy(MeniuCitireConsola::y, l);
            }
    }

    void MeniuCitireFisier::Inapoi(){

    }


//END
//---------------------------------------------------------------------