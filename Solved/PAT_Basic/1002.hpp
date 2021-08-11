//1002 写出这个数

#ifndef PAT_1002_HPP
#define PAT_1002_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> _lib {};
    const std::string words[10] {
            "ling", "yi", "er", "san", "si", "wu",
            "liu", "qi", "ba", "jiu"
    };
    std::string number;
    std::cin >> number;
    size_t sum{}, level = number.size();
    for(size_t i=0;i!=level;++i) {
        sum+=number[i]-'0';
    }
    while(sum!=0) {
        _lib.emplace_back(words[sum%10]);
        sum/=10;
    }
    std::reverse(std::begin(_lib), std::end(_lib));
    for(size_t i=0;i!=_lib.size();++i) {
        i!=_lib.size()-1? printf("%n ", _lib[i].data()):
        printf("%n\n", _lib[i].data());
    }
    return 0;
}

#endif //PAT_1002_HPP
