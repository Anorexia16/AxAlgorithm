//1031 查验身份证

#ifndef PAT_1031_HPP
#define PAT_1031_HPP

#include <string>
#include <iostream>

constexpr int weight[17] {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
constexpr char check[11] {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

std::pair<size_t, bool> weight_sum(std::string const &x) {
    size_t ans{};
    for (size_t i=0;i!=17;++i) {
        if (x[i]!='X') {
            ans += weight[i]*(x[i]-'0');
        } else {
            return {0, false};
        }
    }
    return {ans%11, true};
}


int main() {
    int N;
    bool traveled {};
    std::string str;
    std::pair<size_t, bool> tp;
    scanf("%d", &N);
    for (size_t i=0;i!=N; ++i) {
        std::cin >> str;
        tp = weight_sum(str);
        if (!tp.second||check[tp.first]!=str[17]) {
            std::cout << str << std::endl;
            traveled = true;
        }
    }
    if (!traveled) printf("All passed\n");
}

#endif //PAT_1031_HPP
