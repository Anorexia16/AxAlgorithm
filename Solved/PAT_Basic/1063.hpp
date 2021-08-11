//1063 计算谱半径

#ifndef PAT_1063_HPP
#define PAT_1063_HPP

#include <cstdio>
#include <algorithm>
#include <cmath>

int main() {
    size_t a, b, n;
    scanf("%lld", &n);
    size_t r[n];
    for(size_t i=0;i!=n;++i) {
        scanf("%lld%lld", &a, &b);
        r[i] = a*a+b*b;
    }
    std::sort(r, r+n, std::greater<>());
    printf("%.2f\n", std::sqrt(r[0]));
    return 0;
}

#endif //PAT_1063_HPP
