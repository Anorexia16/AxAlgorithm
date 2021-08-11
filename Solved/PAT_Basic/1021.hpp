//1021 个位数统计

#ifndef PAT_1021_HPP
#define PAT_1021_HPP

#include <string>
#include <iostream>

int main() {
    std::string str;
    std::cin >> str;
    size_t n[10] {}, s=str.size();
    for(size_t i=0;i!=s;++i) {
        ++n[str[i]-'0'];
    }
    for(size_t i=0;i!=10;++i) {
        if (n[i]!=0) {
            printf("%d:%lld\n", i, n[i]);
        }
    }
    return 0;
}

#endif //PAT_1021_HPP
