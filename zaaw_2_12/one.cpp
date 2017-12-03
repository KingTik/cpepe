#include<iostream>
#include<vector>
#include<memory>
// what happens with inheritance and polimorphism
// TO DO: function that accepts  pointer to base class but pass derived class with and without virtual
// try to exeucte functions from both classes and pirint something in copy constructor

class zwierz{
    public:
    virtual void zjedz() noexcept{
        std::cout << "zwierz zjadl\n"; 
    }

};


class kot: public zwierz {
    public:
    virtual void zjedz() noexcept{
        std::cout << "kot zjadl\n"; 
    }
};


class pies: public zwierz {
    public:
    virtual void zjedz() noexcept{
        std::cout << "pies zjadl\n"; 
    }
};


class ryba: public zwierz {
    public:
    virtual void zjedz() noexcept{
        std::cout << "ryba zjadla\n"; 
    }
    virtual void daj_glos() noexcept{
        std::cout << "bool bool\n"; 
    }

};


std::shared_ptr<zwierz> fabryka(char in){
    std::shared_ptr<zwierz> tmp;

    switch ( in )  
      {  
         case 'k':  
            tmp = std::make_shared<kot>(); 
            break;

         case 'p':  
            tmp = std::make_shared<pies>();
            break;

         case 'r':  
            tmp = std::make_shared<ryba>();;
            break;

         default:  
            std::cout << "nie ma takiego zwierza\n"; 
            tmp = nullptr; 
      }  

      return tmp;
}


int main(){


    std::cout << "k: kot\np: pies\nr: ryba\n";
    char in;
    
    std::shared_ptr<zwierz> animal;
    std::vector<std::shared_ptr<zwierz>> zoo;

    for (int i =0; i<4; i++){
        std::cin >> in ;
        animal = fabryka(in);
        
        if (animal != nullptr){
            zoo.push_back(animal);
            
        }
    }
    
    for( auto j = zoo.begin(); j != zoo.end(); j++ ){
        (*j)->zjedz();

        auto k = std::dynamic_pointer_cast<ryba>(*j);
        if(k!=nullptr){
            k->daj_glos();
        }

        
        
    }

    

}