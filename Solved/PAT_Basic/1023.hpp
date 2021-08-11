//1023 组个最小数

#ifndef PAT_1023_HPP
#define PAT_1023_HPP

#include <cstdio>

int main() {
    size_t num[10]{};
    bool pt{};
    for(size_t i=0;i!=10;++i) scanf("%lld", &num[i]);
    for(size_t i=1;i!=10;++i) {
        if (num[i]!=0) {
            printf("%lld", i);
            --num[i];
            pt = true;
            break;
        }
    }
    if(!pt) {
        printf("0\n");
        return 0;
    }
    for(size_t i=0;i!=10;++i) {
        while(num[i]!=0) {
            printf("%lld", i);
            --num[i];
        }
    }
    printf("\n");
    return 0;
}

#endif //PAT_1023_HPP
