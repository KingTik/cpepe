#include<iostream>
#include<vector>
// what happens with inheritance and polimorphism
// TO DO: function that accepts  pointer to base class but pass derived class with and without virtual
// try to exeucte functions from both classes and pirint something in copy constructor
// translate this to smart pointers
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
        std::cout << "ryba zjadl\n"; 
    }
    virtual void daj_glos() noexcept{
        std::cout << "bool bool\n"; 
    }

};


zwierz * fabryka(char in){
    zwierz * tmp;
    switch ( in )  
      {  
         case 'k':  
            tmp = new kot(); 
            break;

         case 'p':  
            tmp = new pies();
            break;

         case 'r':  
            tmp = new ryba();
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
    
    zwierz * animal;
    std::vector<zwierz*> zoo;

    for (int i =0; i<4; i++){
        std::cin >> in ;
        animal = fabryka(in);
        
        if (animal != nullptr){
            zoo.push_back(animal);
            
        }
    }
    
    for( auto j = zoo.begin(); j != zoo.end(); j++ ){
        (*j)->zjedz();

        auto k = dynamic_cast<ryba*>(*j);
        if(k!=nullptr){
            k->daj_glos();
        }

        
        delete (*j);
    }

    

}