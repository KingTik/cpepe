#include <iostream>
#include <vector>






int main(){

    std::vector<int> v { 15, 1,2,3,4,5,6,7,8,9, 15};
    int userInput;
    std::cin >> userInput;
    std::cout << '\n';
    for( auto i = v.begin(); i != v.end(); i++){
        if (*i == userInput) {
            std::cout << std::distance(v.begin(), i) << '\n';
        }
    }



}