// 1024 Palindromic Number

#ifndef PAT_1024_HPP
#define PAT_1024_HPP

#include <iostream>
#include <string>

inline bool is_palindromic(std::string const &str) {
    size_t const size = str.size();
    for (size_t i = 0; i != size / 2; ++i) {
        if (str[i]!=str[size-1-i]) return false;
    }
    return true;
}

inline std::string reverse(std::string const& str) {
    std::string _res;
    _res.resize(str.size());
    std::copy(std::rbegin(str), std::rend(str),std::begin(_res));
    return _res;
}

std::string plus(std::string const& str) {
    std::string rst = reverse(str), res;
    size_t const size = str.size();
    unsigned int temp;
    bool cf = false;
    res.resize(str.size());
    for (unsigned int i=size-1;i!=-1;--i) {
        temp = (str[i] - '0') + (rst[i] - '0') + cf;
        cf = false;
        if (temp>=10) {
            temp-=10;
            cf= true;
        }
        res[i] = static_cast<char>('0'+temp);
    }
    return cf? "1" + res: res;
}

int main() {
    std::string num{}, temp{};
    unsigned int step;
    std::cin >> num >> step;

    if (is_palindromic(num)) {
        std::cout << num << '\n' << 0;
        return 0;
    } else {
        for (unsigned int i = 0; i != step; ++i) {
            num = plus(num);
            if (is_palindromic(num)) {
                std::cout << num << '\n' <<i+1;
                return 0;
            }
        }
    }
    std::cout << num << '\n'<<step;
    return 0;
}

#endif //PAT_1024_HPP
