//1077 Kuchiguse

#ifndef PAT_1077_HPP
#define PAT_1077_HPP

#include <iostream>
#include <algorithm>

int main() {
    std::string str;
    unsigned long n, min=270;
    std::cin >> n;
    std::string vec[n];
    char c; getchar();
    for(int i=0;i!=n;++i) {
        std::getline(std::cin, str);
        vec[i]=str;
        min=min<str.size()?min:str.size();
    }
    for(int i=0;i!=n;++i) {
        std::reverse(vec[i].begin(), vec[i].end());
    }
    for(int i=0;i!=min;++i) {
        c=vec[0][i];
        for(int j=1;j!=n;++j) {
            if(vec[j][i]!=c) {
                if(i==0) {printf("nai\n");return 0;}
                for(int k=0;k!=i;++k) {
                    putchar(vec[0][i-1-k]);
                }
                return 0;
            }
        }
    }
    for(int k=0;k!=min;++k) {
        putchar(vec[0][min-1-k]);
    }
    return 0;
}

#endif //PAT_1077_HPP
