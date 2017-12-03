#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include <functional>

struct Ingidient{

    std::string _name;
    int _mass; // in grams
    Ingidient(int mass, std::string name): _mass(0), _name(""){
        this->_mass = mass;
        this->_name = name;
    }
};


struct Recepie{
    int _total_mass;
    std::vector<Ingidient> _all_ingridients;

    void add_ingridient(Ingidient obj) noexcept{
        this->_all_ingridients.push_back(obj);
        this->sum_up_ingridients();
    }

    void sum_up_ingridients() noexcept{
        int sum = 0;
        std::for_each(this->_all_ingridients.begin(), this->_all_ingridients.end(), [&sum](Ingidient z){sum += z._mass;});
        this->_total_mass = sum;
    }

    
};

struct RecepieCmp{
    bool operator()(const Recepie &obj1,const Recepie &obj2 ) noexcept{
        if(obj1._total_mass > obj2._total_mass){
            return true;
        }else{
            return false;
        }
    }
};

struct CookBook{
    std::multimap<Recepie, std::pair<std::string, std::vector<std::string>>,  RecepieCmp> _all_recepies;

    void add_recepie(Recepie new_recepie, std::string title, std::vector<std::string> keywords){
        auto tmp_pair = make_pair(title, keywords);
        this->_all_recepies.emplace(new_recepie, tmp_pair);
     
    }

};

int main(){


    Recepie nalesnik;
    Ingidient mleko {1000, "mleko" };
    Ingidient jajka { 200, "jajka"} ;
    nalesnik.add_ingridient(mleko);
    nalesnik.add_ingridient(jajka);

    Recepie pierogi;
    Ingidient maka {500, "maka"};
    Ingidient grzyby {100, "grzyby" };
    Ingidient kapusta {250, "kapusta"};
    pierogi.add_ingridient(maka);
    pierogi.add_ingridient(grzyby);
    pierogi.add_ingridient(kapusta);

    Recepie barszcz;
    Ingidient woda {400, "woda"};
    Ingidient buraki{200, "buraki"};
    barszcz.add_ingridient(woda);
    barszcz.add_ingridient(buraki);
    barszcz.add_ingridient(grzyby);


    CookBook ksiazka;
    //std::vector<std::string> k1 = {"pyszny", "grzybki", "swieta bozego narodzenia"}
    ksiazka.add_recepie(barszcz, "barszcz",std::vector<std::string>{"pyszny", "grzybki", "swieta bozego narodzenia"} );
    ksiazka.add_recepie(pierogi, "pierogi", std::vector<std::string>{"maka", "kapusta z grzybami"} );
    ksiazka.add_recepie(nalesnik, "nalesnik", std::vector<std::string>{"caloroczne"});

    for(auto z: ksiazka._all_recepies){
        std::cout << z.second.first << '\n';
    }

}