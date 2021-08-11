//1091 N-自守数

#ifndef PAT_1091_HPP
#define PAT_1091_HPP

#include <cstdio>

int mod(int x) {
    if (x==0) return 10;
    int res = 1;
    while(x!=0) {
        res *=10;
        x /= 10;
    }
    return res;
}

int main() {
    int num, tp, find, m;
    scanf("%d", &num);
    for(size_t i=0;i!=num;++i) {
        scanf("%d", &tp);
        find = false, m= mod(tp);
        for(int j=1;j!=10;++j) {
            if (j*tp*tp%m==tp) {
                printf("%d %d\n", j, j*tp*tp);
                find = true;
                break;
            }
        }
        if (!find) printf("No\n");
    }
    return 0;
}

#endif //PAT_1091_HPP
