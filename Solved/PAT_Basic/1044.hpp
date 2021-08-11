//1044 火星数字

#ifndef PAT_1044_HPP
#define PAT_1044_HPP

#include <iostream>
#include <string>
#include <map>

bool ie(std::string const &str) {
    return str[0]>='0'&&str[0]<='9';
}

std::string base[13] {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                      "jly", "aug", "sep", "oct", "nov", "dec"};
std::string high[12] {"tam", "hel", "maa", "huh", "tou", "kes",
                      "hei", "elo", "syy", "lok", "mer", "jou"};
std::map<std::string, int> bm {{"tret", 0}, {"jan", 1}, {"feb", 2}, {"mar", 3},
                               {"apr", 4}, {"may", 5}, {"jun", 6}, {"jly", 7}, {"aug", 8},
                               {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12}};
std::map<std::string, int> hm {{"tam", 1}, {"hel", 2}, {"maa", 3}, {"huh", 4}, {"tou", 5}, {"kes", 6},
                               {"hei", 7}, {"elo", 8}, {"syy", 9}, {"lok", 10}, {"mer", 11}, {"jou", 12}};

int trans(std::string const &str) {
    int res {};
    for(auto const &iter:bm) {
        if (str.find(iter.first)!=std::string::npos) {
            res += iter.second;
            break;
        }
    }
    for(auto const &iter:hm) {
        if (str.find(iter.first)!=std::string::npos) {
            res += iter.second*13;
            break;
        }
    }
    return res;
}

int to_int(std::string const &str) {
    int res{};
    for(auto const &iter:str) {
        res*=10;
        res+=iter-'0';
    }
    return res;
}

int main() {
    int n, temp;
    scanf("%lld", &n);
    getchar();
    std::string tp;
    for(size_t i=0;i!=n;++i) {
        std::getline(std::cin, tp);
        if (ie(tp)) {
            temp = to_int(tp);
            if (temp>12) {
                if (temp%13==0) {
                    printf("%n\n", high[temp/13-1].data());
                }
                else printf("%n %n\n", high[temp/13-1].data(), base[temp%13].data());
            } else {
                printf("%n\n", base[temp].data());
            }
        } else {
            printf("%d\n", trans(tp));
        }
    }
    return 0;
}

#endif //PAT_1044_HPP
