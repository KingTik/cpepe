#include <iostream>
#include  <unordered_set>
#include <algorithm>

struct Dictionary {
    std::unordered_set<std::string> _set;

    void addWord(std::string word){
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        _set.insert(word);

    }

    void removeWord(std::string word){
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if( this->check(word)){
            _set.erase(word);
        }
    }

    bool check(std::string word){
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        auto result = _set.find(word);
        if( result != _set.end()){
            return true;
        
        }
        return false;
    }

};


int main(){

    Dictionary d1;
    d1.addWord("czesiek");
    std::cout << d1.check("Czesiek") << '\n';
    d1.removeWord("czesiek");
    std::cout << d1.check("czesiek") << '\n';

}