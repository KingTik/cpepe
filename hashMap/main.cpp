#include <iostream>
#include <map>


struct customHash{
    std::int64_t _value;
    customHash(std::string str){
        _value = std::hash<std::string>{}(str);
    }

};

struct customHashCmp{
    bool operator()(const customHash& one, const customHash& two){
        if( one._value > two._value){
            return true; 
        }
        return false;
        
    }
};


int main(){

    std::map<customHash, std::string, customHashCmp> month;

    // int hash = std::hash<std::string> {}("a");
    customHash a("pepe");
    month[a] = "pipi";


    std::cout << "-> " << month[a] << "\n";



}
