#include <iostream>
#include <cstring>
#include <ostream>
#include <string>

class Spital{
    public:
    Spital():nume(0),adresa(""),nrMedici(0),medici(0),CIF("")
    {

    }

    Spital(char *_nume,std::string _adresa, std::string _CIF,std::string* _medici,int _nrMedici):
    adresa(_adresa),CIF(_CIF),nrMedici(_nrMedici)
    {
        this->nume=new char[strlen(_nume)+1];
        strcpy(this->nume,_nume);

        this->medici=new std::string[nrMedici];
        for(int i=0;i<nrMedici;i++)
        {
            this->medici[i]=_medici[i];
        }
    nrSpitale++;
    }

    ~Spital()
    {
        if(medici)
        {
            delete[] medici;
        }
        if(nume)
        {
            delete[] nume;
        }
        //nrSpitale--;
    }

    Spital(const Spital& s):
    adresa(s.adresa),CIF(s.CIF),nrMedici(s.nrMedici)
    {
        this->nume=new char[strlen(s.nume)+1];
        strcpy(this->nume,s.nume);

        this->medici=new std::string[nrMedici];
        for(int i=0;i<nrMedici;i++)
        {
            this->medici[i]=s.medici[i];
        }
    }

    Spital& operator=(const Spital& s)
    {

        if(this==&s)return *this;

        adresa=s.adresa;
        std::string *str=(std::string*)(&CIF);
        *str=s.CIF;

        nrMedici=s.nrMedici;
                if(medici)
        {
            delete[] medici;
            medici=0;
        }
        if(nume)
        {
            delete[] nume;
            nume=0;
        }

        this->nume=new char[strlen(s.nume)+1];
        strcpy(this->nume,s.nume);

        this->medici=new std::string[nrMedici];
        for(int i=0;i<nrMedici;i++)
        {
            this->medici[i]=s.medici[i];
        }

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Spital &s)
    {
        os<<"Nr Spitale: "<<nrSpitale<<"\n";
        os<<"nume: "<<s.nume<<"\n";
        os<<"adresa: "<<s.adresa<<"\n";
        os<<"CIF: "<<s.CIF<<"\n"; 
        os<<"Nr Medici"<<s.nrMedici<<"\n";
        for(int i=0;i<s.nrMedici;i++)
        {
            os<<"Medic "<<i+1<<": "<<s.medici[i]<<'\n';
        }

        return os;
    }

    friend std::istream& operator>>(std::istream& is,Spital &s)
    {
        std::string buffer;
        if(s.nume)
        {
            delete[] s.nume;
            s.nume=0;
        }
        if(s.medici)
        {
            delete[] s.medici;
            s.medici=0;
        }
        std::cout<<"Nume: ";
        is>>buffer;
        s.nume=new char[buffer.length()+1];
        strcpy(s.nume,buffer.c_str());

        std::cout<<"Adresa: ";
        is>>buffer;
        s.adresa=buffer;

        std::cout<<"CIF: ";
        is>>buffer;
        std::string *adr=(std::string*)(&s.CIF);
        *adr=buffer;

        unsigned int nrMedici;
        std::cout<<"Nr Medici: ";
        is>>nrMedici;

        s.nrMedici=nrMedici;

        s.medici=new std::string[nrMedici];
        for(int i=0;i<nrMedici;i++)
        {   
            std::cout<<"Medic "<<i+1<<": ";
            is>>s.medici[i];
        }
        
        nrSpitale++;
        return is;
    }

    std::string operator[](unsigned int index)
    {
        if(index>=nrMedici)
            throw "Index out of bounds";

        return medici[index];
    }
    bool operator!()
    {
        return nrMedici!=0;
    }
    explicit operator int()
    {
        return nrSpitale;
    }

    std::string getCif(){return CIF;}
    std::string getAdresa(){return adresa;}
    std::string* getMedici()
    {
        std::string* copy=new std::string[nrMedici];
        for(int i=0;i<nrMedici;i++)
        {
            copy[i]=medici[i];
        }
        return copy;
    }
    int getNrMedici()
    {
        return nrMedici;
    }
    int getNrSpitale()
    {
        return nrSpitale;
    }

    void setNume(char *_nume)
    {
        if(this->nume)
        {
            delete[] this->nume;
            nume=0;
        }
        this->nume=new char[strlen(_nume)+1];
        strcpy(this->nume,_nume);
    }

    void setMedici(std::string *_medici,int _nrMedici)
    {   
        if(this->medici)
        {
            delete[] this->medici;
            medici=0;
        }
        this->nrMedici=_nrMedici;

        this->medici=new std::string[nrMedici];
        for(int i=0;i<_nrMedici;i++)
        {
            this->medici[i]=_medici[i];
        }

    }
    private:
    char *nume;
    std::string adresa;
    const std::string CIF;
    std::string* medici;
    int nrMedici;
    static int nrSpitale;
};

int Spital::nrSpitale=0;

int main()
{
    std::string medici[2]={"UnMedic","AltMedic"};
    Spital s1((char*)"Floreasca","Bucuresti","CIF123",medici,2);
    Spital s2;
    std::cin>>s2;
    Spital s3=s1;
    std::cout<<s3;
    return 0;
}