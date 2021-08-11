//1104 Sum of Number Segments

#ifndef PAT_1104_HPP
#define PAT_1104_HPP

#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    long double tp, sum{};
    for(int i=0;i!=n;++i) {
        scanf("%Lf", &tp);
        sum+=tp*(i+1)*(n-i);
    }
    printf("%.2Lf\n", sum);
    return 0;
}

#endif //PAT_1104_HPP
