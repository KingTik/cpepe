#include <iostream>
#include <map>


struct customHash{
    std::int64_t _value;
    template<typename T>
    customHash(T&& data){
        _value = std::hash<typename std::decay<T>::type>{}(data);
    }

};

//funktor sortujacy hash mape
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
    //customHash a("pepe");
    month[customHash("pepe")] = "pipi";


    std::cout << "-> " << month[customHash("pepe")] << "\n";



}
