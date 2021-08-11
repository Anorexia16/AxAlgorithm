//1152 Google Recruitment

#ifndef PAT_1152_HPP
#define PAT_1152_HPP

#include <iostream>

bool prime(std::string const &str) {
    unsigned long long x{};
    for(auto &iter:str) {
        x*=10;
        x+=iter-'0';
    }
    if (x==1||x==0) return false;
    for(unsigned long long i=2;i*i<=x;++i) {
        if (x%i==0) return false;
    }
    return true;
}


int main() {
    std::string str;
    int m, n;
    scanf("%d%d", &m, &n);
    std::cin >> str;
    for(int i=0;i+n<=m;++i) {
        if (prime(str.substr(i, n))) {
            printf("%n\n", str.substr(i, n).data());
            return 0;
        }
    }
    printf("404\n");
    return 0;
}

#endif //PAT_1152_HPP
