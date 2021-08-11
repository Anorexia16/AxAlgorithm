//1020 月饼

#ifndef PAT_1020_HPP
#define PAT_1020_HPP

#include <algorithm>
#include <cstdio>

struct pie{
    double num, piece;
};

int cmp(const void *a, const void *b) {
    return (((pie*)(a))->piece/((pie*)(a))->num)<
           (((pie*)(b))->piece/((pie*)(b))->num)?1:-1;
}

int main() {
    size_t n;
    double tp, m, sum{};
    scanf("%lld%lf", &n, &m);
    pie all[n];
    for(size_t i=0;i!=n;++i) {
        scanf("%lf", &all[i].num);
    }
    for(size_t i=0;i!=n;++i) {
        scanf("%lf", &all[i].piece);
    }
    std::qsort(all, n, sizeof(pie), cmp);
    for(size_t i=0;i!=n;++i) {
        if (all[i].num<m) {
            m-=all[i].num;
            sum += all[i].piece;
        } else {
            sum+=all[i].piece/all[i].num*m;
            break;
        }
    }
    printf("%.2f\n", sum);
    return 0;
}

#endif //PAT_1020_HPP
