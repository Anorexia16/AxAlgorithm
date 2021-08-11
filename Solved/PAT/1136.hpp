//1136 A Delayed Palindrome

#ifndef PAT_1136_HPP
#define PAT_1136_HPP

#include <string>
#include <algorithm>
#include <iostream>

bool pld(std::string const &str) {
    auto s = str.size();
    for (size_t i=0;i!=s/2;++i) {
        if (str[i]!=str[s-1-i]) {
            return false;
        }
    }
    return true;
}

std::string r_sum(std::string const &str) {
    std::string res, rs = str;
    size_t s = str.size(), cf{};
    std::reverse(rs.begin(), rs.end());
    for (size_t i=0;i!=s;++i) {
        res.append(1, '0'+(cf+(str[i]-'0')+(rs[i]-'0'))%10);
        cf = (cf+(str[i]-'0')+(rs[i]-'0'))/10;
    }
    if (cf) res.append(1, '1');
    std::reverse(res.begin(), res.end());
    return res;
}

std::string r(std::string const &str) {
    std::string res {str};
    std::reverse(res.begin(), res.end());
    return res;
}

int main() {
    std::string str, tp, rt;
    std::cin >> str;
    if (pld(str)) {
        printf("%s is a palindromic number.", str.data());
        return 0;
    }
    for(size_t _=0;_!=10;++_) {
        rt = r(str), tp = r_sum(str);
        printf("%s + %s = %s\n", str.data(),
               rt.data(), tp.data());
        if (pld(tp)) {
            printf("%s is a palindromic number.", tp.data());
            return 0;
        } else {
            str = tp;
        }
    }
    printf("Not found in 10 iterations.\n");
    return 0;
}

#endif //PAT_1136_HPP
