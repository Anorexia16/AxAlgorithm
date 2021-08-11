//1062 最简分数

#ifndef PAT_1062_HPP
#define PAT_1062_HPP

#include <cstdio>

bool hc(int i, int k) {
    for (int j = 2; j <= i; ++j) {
        if (i % j == 0 && k % j == 0) {
            return true;
        }
    }
    return false;
}

int main () {
    double a, b, tp;
    int k, x, y;
    bool f{};
    scanf("%d/%d", &x, &y);
    a = 1.0*x/y;
    scanf("%d/%d", &x, &y);
    b = 1.0*x/y;
    if (a>b) {
        tp = a;
        a = b;
        b = tp;
    }
    scanf("%d", &k);
    for (int i=1;;++i) {
        if (a<1.0*i/k&&1.0*i/k<b&&!hc(i, k)) {
            if (f) printf(" ");
            printf("%d/%d", i, k);
            f = true;
        } else if (1.0*i/k>=b) break;
    }
    printf("\n");
    return 0;
}

#endif //PAT_1062_HPP
