#include <vector>
#include <iostream>

int main(){
    std::vector<int> v;

    // v.size() returns an unsigned member type named size_type or std::size_t
    // unsigned integers can only be 0 and positive, never negative
    // comparing int < size_t could cause bugs but the compiler will likely optimize it
    for(int i = 0; i < v.size(); i++){}
    
    // solves the problem of the comparing int to size_t and also does pre increment
    // for integers barely any efficieny improvement
    for(size_t i{}; i < v.size(); ++i){}

    // 0: probably deduced as int
    // 0u: unsigned int
    // 0L: long
    // 0ul: unsigned long
    // 0ll: long long
    // 0ull: unsigned long long
    
    //c++23 additions
    // 0z: signed version of std::size_t or std::ptrdiff_t
    // 0uz: unsigned std::size_t
    
    for(auto i{0uz}; i < v.size(); ++i){}

    for(auto i{v.size()}; i-- > 0;){}

    return 0;
}
        
