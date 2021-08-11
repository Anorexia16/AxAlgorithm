// 谷歌的招聘

#ifndef PAT_1094_HPP
#define PAT_1094_HPP

#include<iostream>
#include<string>

bool is_prime(int x) {
    if (x==0||x==1) return false;
    for(int i=2;i*i<=x;++i) if (x%i==0) return false;
    return true;
}

int main() {
    int L, K, tp;
    std::string str, t;
    std::cin >> L >> K >> str;
    for (int i = 0; i <= L - K; ++i) {
        tp = stoi(str.substr(i, K));
        if (is_prime(tp)) {
            std::cout << str.substr(i, K);
            return 0;
        }
    }
    std::cout << "404";
    return 0;
}



#endif //PAT_1094_HPP
