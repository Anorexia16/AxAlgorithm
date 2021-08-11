//1097 Deduplication on a Linked List

#ifndef PAT_1097_HPP
#define PAT_1097_HPP

#include <cstdio>
#include <set>
#include <cmath>
#include <vector>

struct und {
    int value{}, pos{};
};

int main() {
    std::vector<int> a, b{};
    std::set<int> abv{};
    int bg, n, t1, v, t2;
    scanf("%d%d", &bg, &n);
    und map[100000] {};
    while(n--) {
        scanf("%d%d%d", &t1, &v, &t2);
        map[t1].value = v, map[t1].pos = t2;
    }
    while(bg!=-1) {
        if (abv.find(std::abs(map[bg].value))==abv.end()) {
            a.emplace_back(bg);
            abv.insert(std::abs(map[bg].value));
        } else {
            b.emplace_back(bg);
        }
        bg = map[bg].pos;
    }
    size_t as=a.size(), bs=b.size();
    for(int i=0;i!=as;++i) {
        i==as-1?
        printf("%05d %d %d\n", a[i],
               map[a[i]].value, -1):
        printf("%05d %d %05d\n", a[i],
               map[a[i]].value, a[i+1]);
    }
    for(int i=0;i!=bs;++i) {
        i==bs-1?
        printf("%05d %d %d\n", b[i],
               map[b[i]].value, -1):
        printf("%05d %d %05d\n", b[i],
               map[b[i]].value, b[i+1]);
    }
    return 0;
}

#endif //PAT_1097_HPP
