//1033 旧键盘打字

#ifndef PAT_1033_HPP
#define PAT_1033_HPP

#include <iostream>
#include <string>
#include <unordered_set>

int main () {
    std::string broken, str;
    std::unordered_set<char> set {};
    std::getline(std::cin, broken);
    std::getline(std::cin, str);
    for(auto const &iter:broken) {
        if (iter=='+') {
            for(size_t i=0;i!=26;++i) set.insert('A'+i);
            continue;
        }
        set.insert(iter);
        if (iter>='A'&&iter<='Z') set.insert(iter-'A'+'a');
    }

    for(auto const &iter:str) {
        if (set.find(iter)==set.end()) {
            printf("%c", iter);
        }
    }
    printf("\n");
    return 0;
}

#endif //PAT_1033_HPP
