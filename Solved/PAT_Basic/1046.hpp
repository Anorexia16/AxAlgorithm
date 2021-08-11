//1046 划拳

#ifndef PAT_1046_HPP
#define PAT_1046_HPP

#include <cstdio>

int main() {
    size_t a{}, b{}, n, as, bs, ar, br;
    scanf("%lld", &n);
    for(size_t i=0;i!=n;++i) {
        scanf("%lld%lld%lld%lld", &ar, &as, &br, &bs);
        if (ar+br==as&&ar+br!=bs) ++a;
        if (ar+br!=as&&ar+br==bs) ++b;
    }
    printf("%lld %lld", b, a);
}

#endif //PAT_1046_HPP
