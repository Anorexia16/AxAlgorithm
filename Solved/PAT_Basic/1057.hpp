//1057 数零壹

#ifndef PAT_1057_HPP
#define PAT_1057_HPP

#include <string>
#include <iostream>

int main() {
    std::string str;
    std::getline(std::cin, str);
    size_t ans{}, zero{}, one{};
    for(auto const &iter: str) {
        if ('a'<=iter&&iter<='z') {
            ans+=iter-'a'+1;
        } else if ('A'<=iter&&iter<='Z') {
            ans+=iter-'A'+1;
        }
    }
    while(ans!=0) {
        ans%2 == 1? ++one:++zero;
        ans /=2;
    }
    printf("%lld %lld\n", zero, one);
    return 0;
}

#endif //PAT_1057_HPP
