#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <string>

class Product
{  
 public:
    Product()
    {
        this->id=0;
        this->description=0;
        this->name=0;
        this->price=0;
        this->priceHistory=0;
        this->nrOfPrices=0;
    }

    ~Product()
    {
        if(this->name)
        {
            delete[] this->name;
        }

        if(this->priceHistory)
        {
            delete[] this->priceHistory;
        }

        if(this->description)
        {
            delete[] this->description;
        }
    }

    Product(int _id,char* _name,double _price,char* _description,int _nrOfPrices=0,const double* _priceHistory=0):
    price(_price),id(_id),nrOfPrices(_nrOfPrices)
    {
        this->name=new char[strlen(_name)+1];
        strcpy(this->name,_name);

        this->description=new char[strlen(_description)+1];
        strcpy(this->description,_description);

        
        if(nrOfPrices==0){  

            if(price>0.0f){
        nrOfPrices++;
        this->priceHistory=new double[1];
        this->priceHistory[0]=price;
            }

            else {
        this->priceHistory=0;
            }

        }

        else {
        nrOfPrices++;
        this->priceHistory=new double[nrOfPrices];
        for(int i=0;i<nrOfPrices-1;i++)
        {
            this->priceHistory[i]=_priceHistory[i];
        }
            this->priceHistory[nrOfPrices-1]=price;
        }

    }

    Product(const Product &product):
    price(product.price),id(product.id),nrOfPrices(product.nrOfPrices)
    {
        this->name=0;
        this->description=0;
        priceHistory=0;

        if(product.name){
        this->name=new char[strlen(product.name)+1];
        strcpy(this->name,product.name);
        }

        if(product.description){
        this->description=new char[strlen(product.description+1)];
         strcpy(this->description,product.description);
        }

        if(product.priceHistory){
        this->priceHistory=new double[this->nrOfPrices];

        for(int i=0;i<this->nrOfPrices;i++)
        {
            this->priceHistory[i]=product.priceHistory[i];
        }
        }

    }

    float AveragePrice()
    {
        float x=0.0f;
        for(int i=0;i<nrOfPrices;i++)
        {
            x+=this->priceHistory[i];
        }

        if(nrOfPrices>0)
            x=x/nrOfPrices;
        
        return x;
    };
    
    char* getName(){return name;}
    float getPrice(){return price;}
    char* getDescription(){return description;}
    int getId(){return id;}
    double* getPriceHistory(){return priceHistory;}
    int getNrOfPrevPrices(){return nrOfPrices;}

    void setName(char *_name)
    {
        if(this->name)
        {
            delete[] this->name;
        }
        this->name=new char[strlen(_name)+1];
        strcpy(name,_name);
    }

    void setDescription(char* _description)
    {
       if(this->description)
        {
            delete[] this->description;
        }
        this->description=new char[strlen(_description)+1];
        strcpy(description,_description);
    }

    void setNewPrice(float newPrice)
    {
        if(newPrice<=0)return;

        float *newPrices=new float[this->nrOfPrices+1];

        for(int i=0;i<this->nrOfPrices;i++)
        {
            newPrices[i]=this->priceHistory[i];
        }

        newPrices[this->nrOfPrices]=newPrice;
        price=newPrice;
        nrOfPrices++;

        if(priceHistory)
        {
            delete[] priceHistory;
        }

        this->priceHistory=new double[this->nrOfPrices];
        for(int i=0;i<this->nrOfPrices;i++)
        {
            this->priceHistory[i]=newPrices[i];
        }

        delete[] newPrices;
        

    }

    private:

    int id;
    char *name;
    double price;
    char *description;
    double *priceHistory;
    int nrOfPrices;
};

int main()
{
    Product p1(1,(char*)"Mere",2.0f,(char*)"Fructe");
    p1.setNewPrice(4.3f);

    Product p2=p1;
    p2.setName((char*)"Pere");
    
    std::cout<<"Product1: "<<p1.getName()<<'\n';
    std::cout<<"Product2: "<<p2.getName()<<'\n';
    //daca constructorul de copiere nu ar gestiona copierea valorilor dintr un obiect in altul
    //valoarea campului nume s ar fi schimbat atat pentru p2 cat si pentru p1 in urma executiei instructiunii set
    //deoarece campul nume din ambele obiecte indica aceiasi zona de memorie

    char *name=new char[30];
    char *description=new char[100];
    int id;
    double price;
    int nr;
    double *History;

    std::cout<<"Product ID: ";
    std::cin>>id;

    std::cin.get();
    std::cout<<"Product name: ";
    std::cin.getline(name,30);

    std::cout<<"Price: ";
    std::cin>>price;

    std::cin.get();
    std::cout<<"Description: ";
    std::cin.getline(description,100);

    std::cout<<"Nr of prev prices:";
    std::cin>>nr;

    History=new double[nr];
    for(int i=0;i<nr;i++)
    {
        std::cout<<"price "<<i+1<<": ";
        std::cin>>History[i];
    }



    Product p3(id,name,price,description,nr,History);
    delete[] History;
    delete[] name;
    delete[] description;

    std::cout<<"Average: "<<p3.AveragePrice();


    

    return 0;
}