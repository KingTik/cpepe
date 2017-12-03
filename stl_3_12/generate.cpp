#include <iostream>
#include <algorithm>
#include <array>
// generate array elements with functor and lambda
struct param{

    int operator()(){
        return 100;
    }
};

int main(){


    std::array<int, 10> tablica;
    int tmp =1;
    // std::generate(tablica.begin(), tablica.end(), [](){return 5;});
    std::generate(tablica.begin(), tablica.end(), param{});
    std::for_each(tablica.begin(), tablica.end(), [](int z){ std::cout << z << '\n'; });

}