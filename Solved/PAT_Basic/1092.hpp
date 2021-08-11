//1092 最好吃的月饼

#ifndef PAT_1092_HPP
#define PAT_1092_HPP

#include <cstdio>
#include <algorithm>

struct pd {
    size_t num, value;
    bool operator<(pd const &op) const {
        if (value!=op.value) return value>op.value;
        else return num<op.num;
    }
};

int main() {
    size_t m, n, tp;
    scanf("%lld%lld", &m, &n);
    pd cp[m];
    for(size_t i=0;i!=m;++i) cp[i] = pd{i+1, 0};
    for(size_t j=0;j!=n;++j) {
        for(size_t i=0;i!=m;++i) {
            scanf("%d", &tp);
            cp[i].value += tp;
        }
    }
    std::sort(cp, cp+m);
    tp = cp[0].value;
    printf("%lld\n", tp);
    for(size_t i=0;;++i) {
        if (cp[i].value==tp) {
            if (i!=0) printf(" ");
            printf("%lld", cp[i].num);
        } else break;
    }
    printf("\n");
    return 0;
}

#endif //PAT_1092_HPP
