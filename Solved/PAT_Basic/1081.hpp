//1081 检查密码

#ifndef PAT_1081_HPP
#define PAT_1081_HPP

#include <string>
#include <iostream>

int main() {
    size_t n;
    bool ef, nf, cf;
    scanf("%lld\n", &n);
    std::string str;
    for(size_t i=0;i!=n;++i) {
        ef = false, nf = false, cf = false;
        std::getline(std::cin, str);
        if(str.size()<6) {
            printf("Your password is tai duan le.\n");
        } else {
            for(auto const &iter:str) {
                if (('a'<=iter&&iter<='z')
                    ||('A'<=iter&&iter<='Z')) {
                    ef = true;
                } else if ('0'<=iter&&iter<='9') {
                    nf = true;
                } else if (iter == '.') {
                    continue;
                } else {
                    cf = true;
                    break;
                }
            }
            if (cf) {
                printf("Your password is tai luan le.\n");
            } else if (!nf) {
                printf("Your password needs shu zi.\n");
            } else if (!ef) {
                printf("Your password needs zi mu.\n");
            } else {
                printf("Your password is wan mei.\n");
            }
        }
    }
}

#endif //PAT_1081_HPP
