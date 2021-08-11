// 1132 Cut Integer

#ifndef PAT_1132_HPP
#define PAT_1132_HPP

#include <iostream>
#include <string>

size_t to_size(std::string const &s) {
    size_t _res {};
    for (auto const &iter:s) {
        _res *= 10;
        _res += iter-'0';
    }
    return _res;
}

int main() {
    int N;
    std::string str {}, temp{};
    size_t ti, t2, t3;
    scanf("%d", &N);
    for (unsigned int i=0;i!=N;++i) {
        std::cin >> str;
        ti = to_size(str);
        t2 = to_size(str.substr(0, str.size()/2));
        t3 = to_size(str.substr(str.size()/2));
        if (t2==0||t3==0) {
            printf("No\n");
            continue;
        } if (ti%(t2*t3)==0) {
            printf("Yes\n");
            continue;
        }
        printf("No\n");
    }
}

#endif //PAT_1132_HPP
