// 1128 N Queens Puzzle

#ifndef PAT_1128_HPP
#define PAT_1128_HPP

#include <cstdio>
#include<cmath>

int main() {
    ssize_t k, n, table[1000];
    bool flag;
    scanf("%d", &k);
    for(ssize_t i=0;i!=k;++i) {
        scanf("%d", &n);
        flag = true;
        for(ssize_t j=0;j!=n;++j) {
            scanf("%d", table+j);
            for(ssize_t k=0;k<j-1;++k) {
                if(table[k]==table[j]||(std::abs(table[j]-table[k])==std::abs(j-k))) {
                    flag = false;
                    break;
                }
                if (!flag) break;
            }
        }
        flag? printf("YES\n") : printf("NO\n");
    }
}

#endif //PAT_1128_HPP
