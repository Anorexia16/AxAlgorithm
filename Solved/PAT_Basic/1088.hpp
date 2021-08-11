//1088 三人行

#ifndef PAT_1088_HPP
#define PAT_1088_HPP

#include <cstdio>

inline double abs(double const &x) {
    return x>=0?x:-x;
}

double self, x, y, j, k;

void cmp(double const &num) {
    if (num>self) {
        printf(" Cong");
    } else if (num<self) {
        printf(" Gai");
    } else {
        printf(" Ping");
    }
}

int main() {

    scanf("%lf%lf%lf", &self, &x, &y);
    for (int i=99;i!=9;--i) {
        j = 10*(i%10) + i/10;
        k = j/y;
        if (abs(i - j)==x*k) {
            printf("%d", i);
            cmp(i);
            cmp(j);
            cmp(k);
            printf("\n");
            return 0;
        }
    }
    printf("No Solution\n");
    return 0;
}

#endif //PAT_1088_HPP
