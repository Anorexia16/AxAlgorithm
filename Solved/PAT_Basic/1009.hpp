//1009 说反话

#ifndef PAT_1009_HPP
#define PAT_1009_HPP

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<std::string> words;
    std::string temp;
    size_t pos{};
    std::getline(std::cin, temp);
    for (size_t i=0;i!=temp.size();++i) {
        if (temp[i]==' ') {
            words.emplace_back(temp.substr(pos, i-pos));
            pos=i+1;
        }
    }
    words.emplace_back(temp.substr(pos));
    std::reverse(std::begin(words), std::end(words));
    for(size_t i=0;i!=words.size();++i) {
        std::cout<<words[i];
        i<words.size()-1? printf(" "): printf("\n");
    }

    return 0;
}

#endif //PAT_1009_HPP
