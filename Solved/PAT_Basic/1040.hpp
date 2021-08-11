// 1040 有几个PAT

#ifndef PAT_1040_HPP
#define PAT_1040_HPP

#include <string>
#include <iostream>

int main () {
    size_t a{}, t{}, sum{}, group{};
    std::string str;
    std::cin >> str;
    for(auto iter=str.rbegin();iter!=str.rend();++iter) {
        switch(*iter) {
            case 'T':
                group+=a*t;
                ++t;
                a=0;
                break;
            case 'A':
                ++a;
                break;
            default:
                sum+=a*t+group;
                break;
        }
    }
    printf("%lld", sum%1000000007);
}

#endif //PAT_1040_HPP
