//1025 反转链表

#ifndef PAT_1025_HPP
#define PAT_1025_HPP

#include <map>
#include <cstdio>
#include <algorithm>

struct node {
    int from, value, to;
};

int main() {
    std::map<int, node> map;
    int f, v, t, be, n, k, si{}, ri{};
    scanf("%d%d%d", &be, &n, &k);
    for(int i=0;i!=n;++i) {
        scanf("%d%d%d", &f, &v, &t);
        map[f] = node {f, v, t};
    }
    node arr[n];
    while(be!=-1) {
        arr[si++] = map[be];
        be = map[be].to;
    }
    while(true) {
        if (ri+k>si) {
            break;
        } else {
            std::reverse(arr+ri, arr+ri+k);
            ri += k;
        }
    }
    for(int i=0;i!=si-1;++i) {
        arr[i].to = arr[i+1].from;
    }
    for(int i=0;i!=si-1;++i) {
        printf("%05d %d %05d\n", arr[i].from, arr[i].value, arr[i].to);
    }
    printf("%05d %d -1\n", arr[si-1].from, arr[si-1].value);
    return 0;
}

#endif //PAT_1025_HPP
