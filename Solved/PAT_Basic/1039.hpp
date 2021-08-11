//1039 到底买不买

#ifndef PAT_1039_HPP
#define PAT_1039_HPP

#include <iostream>
#include <string>

size_t index(char c) {
    if ('a'<=c&&c<='z') {
        return c-'a';
    } else if ('A'<=c&&c<='Z') {
        return c-'A'+26;
    } else {
        return c-'0'+52;
    }
}

int main() {
    std::string a, b;
    size_t dev{}, shop[62]{}, need[62]{};
    bool lake {};
    std::getline(std::cin, a);
    std::getline(std::cin, b);
    for(auto const &iter:a) {
        ++shop[index(iter)];
    }
    for(auto const &iter:b) {
        ++need[index(iter)];
    }
    for (size_t i=0;i!=62;++i) {
        if (!lake) {
            if (need[i] <= shop[i]) {
                dev += shop[i] - need[i];
            } else {
                dev = need[i] - shop[i];
                lake = true;
            }
        } else {
            if (shop[i]<need[i]) {
                dev += need[i] - shop[i];
            }
        }
    }
    lake? printf("No %lld\n", dev):
    printf("Yes %lld\n", dev);
    return 0;
}

#endif //PAT_1039_HPP
