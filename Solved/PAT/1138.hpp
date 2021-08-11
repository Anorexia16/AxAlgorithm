// 1138 Postorder Traversal

#ifndef PAT_1138_HPP
#define PAT_1138_HPP

#include <cstdio>

int main () {
    size_t n, pre[50000], in[50000], root{},bg{},  i, pre_iter{};
    scanf("%lld", &n);
    for (size_t j=0;j!=n;++j) scanf("%lld", pre+j);
    for (size_t j=0;j!=n;++j) scanf("%lld", in+j);
    for (i=0;i!=n;++i) if (in[i] == pre[root]) break;
    if (n == 1) {
        printf("%lld", in[i]);
        return 0;
    } else {
        root = i;
        ++pre_iter;
    }
    while(true) {
        i = bg;
        if (bg + 1 == n) {
            printf("%lld\n", in[bg]);
            return 0;
        }
        for (;i!=n;++i) {
            if (in[i] == pre[pre_iter]) break;
        }
        if (i < root) {
            ++pre_iter;
            n = root;
            root=i;
        } else if (i > root) {
            ++pre_iter;
            bg = root+1;
            root = i;
        }
    }
}

#endif //PAT_1138_HPP
