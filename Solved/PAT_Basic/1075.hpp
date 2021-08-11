//1075 链表元素分类

#ifndef PAT_1075_HPP
#define PAT_1075_HPP

#include <algorithm>
#include <map>
#include <cstdio>

struct node {
    int from, value, to;
};
int n, k, pos;

int type(node const &a) {
    if (a.value<0) {
        return 2;
    } else if (0<=a.value&&a.value<=k) {
        return 1;
    } else {
        return 0;
    }
}

bool cp(node const &a, node const &b) {
    return type(a) > type(b);
}

int main() {
    std::map<int, int> mem{};
    scanf("%d%d%d", &pos, &n, &k);
    node list[n], sorted[n];
    for(int i=0;i!=n;++i) {
        scanf("%d%d%d", &list[i].from, &list[i].value, &list[i].to);
        mem[list[i].from] = i;
    }
    n=0;
    do {
        sorted[n++] = list[mem[pos]];
        pos = list[mem[pos]].to;
    } while (pos!=-1);
    std::stable_sort(sorted, sorted+n, cp);
    for(size_t i=0;i!=n;++i) {
        i==n-1?printf("%05d %d -1\n", sorted[i].from, sorted[i].value):
        printf("%05d %d %05d\n", sorted[i].from, sorted[i].value, sorted[i+1].from);
    }
    return 0;
}

#endif //PAT_1075_HPP
