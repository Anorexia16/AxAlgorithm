//1093 字符串A+B

#ifndef PAT_1093_HPP
#define PAT_1093_HPP

#include<cstdio>

int main() {
    bool traveled[127] {};
    char c;
    while(scanf("%c", &c)!=EOF) {
        if (!traveled[c] && c!='\n') {
            traveled[c] = true;
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}

#endif //PAT_1093_HPP
