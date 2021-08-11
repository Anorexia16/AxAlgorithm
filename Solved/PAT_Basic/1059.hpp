//1059 C语言竞赛

#ifndef PAT_1059_HPP
#define PAT_1059_HPP

#include<cstdio>
#include<set>
#include <vector>

int main() {
    bool pool[10000] {};
    size_t tp, m, n;
    for (size_t i=2;i!=10000;++i) {
        tp = 2;
        while (i*tp<10000) {
            pool[i*tp] = true;
            ++tp;
        }
    }
    std::vector<size_t> rank{};
    std::set<size_t> check{}, join{};
    scanf("%lld", &m);
    rank.reserve(m);
    for(size_t i=0;i!=m;++i) {
        scanf("%lld", &tp);
        rank.emplace_back(tp);
        join.insert(tp);
    }
    scanf("%lld", &n);
    for(size_t i=0;i!=n;++i) {
        scanf("%lld", &tp);
        if (tp==rank.front()&&check.find(tp)==check.end()) {
            printf("%04d: Mystery Award\n", tp);
            check.insert(tp);
        } else if (check.find(tp)==check.end()&&join.find(tp)!=join.end()) {
            size_t j=0;
            for(;j!=m;++j) if (rank[j]==tp) break;
            if (!pool[j+1]) {
                printf("%04d: Minion\n", tp);
            } else {
                printf("%04d: Chocolate\n", tp);
            }
            check.insert(tp);
        } else if (check.find(tp)!=check.end()) {
            printf("%04d: Checked\n", tp);
        } else if (join.find(tp)==join.end()) {
            printf("%04d: Are you kidding?\n", tp);
        }
    }
    return 0;
}

#endif //PAT_1059_HPP
