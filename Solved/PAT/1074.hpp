// 1074 Reversing Linked List

#ifndef PAT_1074_HPP
#define PAT_1074_HPP

#include <algorithm>
#include <cstdio>
#include <map>

struct node {
    ssize_t add;
    ssize_t data;
    ssize_t next;
};

ssize_t min(ssize_t const&a, ssize_t const &b) {
    return a>b?b:a;
}

int main() {
    std::map<ssize_t, node> map;
    ssize_t data[100000], add[100000], next[100000],
            n, l, b, ad, da, ne, c{};
    scanf("%lld%lld%lld", &b, &n, &l);
    for (ssize_t i=0;i!=n;++i) {
        scanf("%lld%lld%lld", &ad, &da, &ne);
        map[ad] = node{ad, da, ne};
    }
    while (b!=-1) {
        data[c] = map[b].data;
        add[c++] = map[b].add;
        b= map[b].next;
    }
    for (ssize_t i=0;i!=c/l;++i) {
        std::reverse(data+i*l, data+(i+1)*l);
        std::reverse(add+i*l, add+(i+1)*l);
    }
    for (ssize_t i=0;i!=c-1;++i) next[i] = add[i+1];
    next[c-1] = -1;
    for (size_t i=0;i!=c;++i) {
        if (i!=c-1) {
            printf("%05lld %lld %05lld\n",
                   add[i], data[i], next[i]);
        } else {
            printf("%05lld %lld -1\n",
                   add[i], data[i]);
        }
    }
    return 0;
}

#endif //PAT_1074_HPP
