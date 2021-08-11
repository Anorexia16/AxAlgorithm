//1093 Count PAT'n

#ifndef PAT_1093_HPP
#define PAT_1093_HPP

#include <iostream>

int main() {
    size_t a{}, t{}, pk{}, sum{};
    std::string str;
    std::cin >> str;
    for(auto iter{str.rbegin()};iter!=str.rend();++iter) {
        switch (*iter) {
            case 'T':
                pk+=a*t;
                ++t;
                a=0;
                break;
            case 'A':
                ++a;
                break;
            default:
                sum+=pk+a*t;
                break;
        }
    }
    printf("%lld\n", sum%1000000007);
    return 0;
}


#endif //PAT_1093_HPP
