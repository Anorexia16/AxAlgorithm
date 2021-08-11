//1066 图像过滤

#ifndef PAT_1066_HPP
#define PAT_1066_HPP

#include <cstdio>

int main() {
    size_t m, n, min, max, re, tp;
    scanf("%lld%lld%lld%lld%lld", &m, &n, &min, &max, &re);
    for(size_t i=0;i!=m;++i) {
        for(size_t j=0;j!=n;++j) {
            scanf("%lld", &tp);
            if (tp>=min&&tp<=max) {
                printf("%03lld", re);
            } else {
                printf("%03lld", tp);
            }
            if(j != n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}

#endif //PAT_1066_HPP
