//1032 挖掘机技术哪家强

#ifndef PAT_1032_HPP
#define PAT_1032_HPP

#include <algorithm>
#include <cstdio>

int main() {
    size_t n, tp, id, mi{1}, m{};
    scanf("%lld", &n);
    size_t s[n] {};
    for(size_t i=0;i!=n;++i) {
        scanf("%lld%lld", &id, &tp);
        s[id] += tp;
    }
    for(size_t i=1;i!=n;++i) {
        if (m<s[i]) {
            m = s[i];
            mi = i;
        }
    }
    printf("%lld %lld\n", mi, m);
    return 0;
}

#endif //PAT_1032_HPP
