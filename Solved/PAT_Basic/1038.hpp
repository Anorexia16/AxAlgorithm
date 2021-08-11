//1038 统计同成绩学生

#ifndef PAT_1038_HPP
#define PAT_1038_HPP

#include <cstdio>

int main() {
    size_t grade[101]{}, tp, m, n;
    scanf("%lld", &m);
    for(size_t i=0;i!=m;++i) {
        scanf("%lld", &tp);
        ++grade[tp];
    }
    scanf("%lld", &n);
    for(size_t i=0;i!=n;++i) {
        scanf("%lld", &tp);
        printf("%lld", grade[tp]);
        i == n-1? printf("\n") : printf(" ");
    }
    return 0;
}

#endif //PAT_1038_HPP
