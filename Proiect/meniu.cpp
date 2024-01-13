#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h> 
#include <cstring>
#include <fstream>
#include "meniu.h"
#include "calculator.h"

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
                return CodMeniuPrincipal;
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
        std::ifstream file("MeniuConsola.txt");
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
            case '1':
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
                return CodMeniuPrincipal;
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
                y=str_functions::double_to_string(calc->getResult());
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
            
        char *buffer=new char[calc->getBufferSize()+1];

        if(y!=nullptr){
         strcpy(buffer,y);
         std::cout<<y;
        }
        else {
         strcpy(buffer,"0");
         std::cout<<'0';
        }

        std::cin.get();
        std::cin.getline(buffer+strlen(buffer),calc->getBufferSize()+1-strlen(buffer));
        calc->setExpr(buffer);
        calc->evalExpr();
        calc->printResult();

    delete[] buffer;
            MeniuCitireConsola::SaveResult();
        }
        else {
            if(fc == "fisier")
                {

        std::ofstream Rezfile("Rezultate.txt",std::ios::app);
        std::string Rezline;
        std::cout<<"Scrieti expresia: "<<'\n';
  char *buffer=new char[calc->getBufferSize()+1];

        if(y!=nullptr){
         strcpy(buffer,y);
         std::cout<<y;
        }
        else {
         strcpy(buffer,"0");
         std::cout<<'0';
        }

        std::cin.get();
        std::cin.getline(buffer+strlen(buffer),calc->getBufferSize()+1-strlen(buffer));;
        calc->setExpr(buffer);
        calc->evalExpr();
        calc->printResult();
         delete[] buffer;
        if(calc->getErrorMessage()!="")
         {
        if(calc->getErrorMessage()=="Exiting program")
                return 0;
        return CodCitireConsola;
         }
         Rezfile<<"Expresie: "<<calc->getExpr()<<'\n';
         Rezfile<<"Rezultat: ";
         if(calc->getType())
         {
            if(calc->getSolutii().x1==calc->getSolutii().x2)
            {
                Rezfile<<"x="<<calc->getSolutii().x1<<"\n\n";
            }
            else 
            {
                Rezfile<<"x1="<<calc->getSolutii().x1<<' ';
                Rezfile<<"x2="<<calc->getSolutii().x2<<"\n\n";
            }
         }
         else
        {
            Rezfile<<calc->getResult()<<"\n\n";
        }
            std::cout<<"Rezultatul a fost adaugat fisierului Rezultate.txt";
        

            // Close the file
            Rezfile.close();
            system("CLS");
            std::cout<<std::flush <<'\n';
            MeniuCitireConsola::SaveResult();
              }
            else {
            std::cout<<"\nCalea oferita nu este o optiune. Va rugam incercati din nou."<<std::endl;
                  }
        }
        return CodCitireConsola;
    }

    int MeniuCitireConsola::Citire(/*char* expresie*/){
        system("CLS");
        std::cout<<std::flush <<'\n';
        
        std::cout<<"Unde afisati rezultatele? (fisier/consola)"<< '\n';
        std::string fc;
        std::cin>>fc;
        if( fc == "consola"){
            system("CLS");
            std::cout<<std::flush <<'\n';
            std::cout<<"Scrieti expresia: "<<'\n';
    char *buffer=new char[calc->getBufferSize()+1];
        std::cin.get();
        std::cin.getline(buffer,calc->getBufferSize()+1);
        calc->setExpr(buffer);
        calc->evalExpr();
        calc->printResult();
    delete[] buffer;
    if(calc->getErrorMessage()!="")
    {
        if(calc->getErrorMessage()=="Exiting program")
                return 0;
        return CodCitireConsola;
    }
            MeniuCitireConsola::SaveResult();
        }
        else{
        if(fc == "fisier"){
            system("CLS");
            std::cout<<std::flush <<'\n';
        std::ofstream Rezfile("Rezultate.txt",std::ios::app);
        std::string Rezline;
        std::cout<<"Scrieti expresia: "<<'\n';
        char *buffer=new char[calc->getBufferSize()+1];
        std::cin.get();
        std::cin.getline(buffer,calc->getBufferSize()+1);
        calc->setExpr(buffer);
        calc->evalExpr();
        calc->printResult();
         delete[] buffer;
        if(calc->getErrorMessage()!="")
         {
        if(calc->getErrorMessage()=="Exiting program")
                return 0;
        return CodCitireConsola;
         }
         Rezfile<<"Expresie: "<<calc->getExpr()<<'\n';
         Rezfile<<"Rezultat: ";
         if(calc->getType())
         {
            if(calc->getSolutii().x1==calc->getSolutii().x2)
            {
                Rezfile<<"x="<<calc->getSolutii().x1<<"\n\n";
            }
            else 
            {
                Rezfile<<"x1="<<calc->getSolutii().x1<<' ';
                Rezfile<<"x2="<<calc->getSolutii().x2<<"\n\n";
            }
         }
         else
        {
            Rezfile<<calc->getResult()<<"\n\n";
        }
            std::cout<<"Rezultatul a fost adaugat fisierului Rezultate.txt";
        

            // Close the file
            Rezfile.close();
            MeniuCitireConsola::SaveResult();           
        }
        else {
            std::cout<<"Calea oferita nu este o optiune. Va rugam incercati din nou"<<std::endl;
        }
        }
        return CodCitireConsola;
    }

  

  //MENIU CITIRE FISIER
 //------------------------------------------------------------------------

 MeniuCitireFisier::MeniuCitireFisier()
        {

        }

    MeniuCitireFisier::~MeniuCitireFisier(){
        if(l!=nullptr) delete l;
    }

    void MeniuCitireFisier::DisplayMenu(){
        system("CLS");
        std::cout<<std::flush <<'\n';
        std::ifstream file("MeniuFisier.txt");
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
        std::string filename;
        std::cout<<"Nume Fisier:";
        std::cin>>filename;
        std::cout<<'\n';

        std::ifstream fisierCitire(filename);
        if(fisierCitire.fail())
        {
            std::cout<<"Fisierul nu a fost gasit";
            return CodMeniuPrincipal;
        }
        
        std::cout<<"Unde afisati rezultatele? (fisier/consola)"<< '\n';
        std::string fc;
        std::cin>>fc;
        if( fc == "consola"){
            system("CLS");
            std::cout<<std::flush <<'\n';
         char *buffer=new char[calc->getBufferSize()+1];
         std::cin.get();
            while(fisierCitire.getline(buffer,calc->getBufferSize()+1))
            {
            std::cout<<"Expresie: "<<buffer;
            std::cout<<'\n';
            calc->setExpr(buffer);
            calc->evalExpr();
            calc->printResult();
            char a;
            std::cout<<"\nPress Enter to Continue.";
            std::cin.get();
            std::cout<<"\n\n";
            }
            delete[] buffer;
            MeniuCitireFisier::SaveResult();
        }
        else{if(fc == "fisier"){
            
            system("CLS");
            std::cout<<std::flush <<'\n';
        std::ofstream Rezfile("Rezultate.txt",std::ios::app);
        std::string Rezline;
        char *buffer=new char[calc->getBufferSize()+1];
        while(fisierCitire.getline(buffer,calc->getBufferSize()+1))
        {
        calc->setExpr(buffer);
        calc->evalExpr();
        if(calc->getErrorMessage()!="")
         {
        if(calc->getErrorMessage()=="Exiting program")
                return 0;
        return CodCitireConsola;
         }
         Rezfile<<"Expresie: "<<calc->getExpr()<<'\n';
         Rezfile<<"Rezultat: ";
         if(calc->getType())
         {
            if(calc->getSolutii().x1==calc->getSolutii().x2)
            {
                Rezfile<<"x="<<calc->getSolutii().x1<<"\n\n";
            }
            else 
            {
                Rezfile<<"x1="<<calc->getSolutii().x1<<' ';
                Rezfile<<"x2="<<calc->getSolutii().x2<<"\n\n";
            }
         }
         else
        {
            Rezfile<<calc->getResult()<<"\n\n";
        }
            }
        delete[] buffer;
            std::cout<<"Rezultatul a fost adaugat fisierului Rezultate.txt";
        

            // Close the file
            Rezfile.close();    
            MeniuCitireFisier::SaveResult();      
        }
             else {
            std::cout<<"Calea oferita nu este o optiune. Va rugam incercati din nou"<<std::endl;
        }
        }
        return CodCitireFisier;
    }

    void MeniuCitireFisier::SaveResult(){

        std::cout<<"\nSalvati rezultatul?(da/nu)\n";
            std::string dn;
            std::cin>>dn;
            if( dn == "da") {
                l=str_functions::double_to_string(calc->getResult());
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