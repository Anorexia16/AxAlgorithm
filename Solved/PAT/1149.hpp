//1149 Dangerous Goods Packaging

#ifndef PAT_1149_HPP
#define PAT_1149_HPP

#include <unordered_map>
#include <vector>
#include <cstdio>

int main() {
    std::unordered_map<size_t, std::vector<size_t>> danger {};
    size_t box[1000];
    size_t m, n, q, tp1, tp2;
    bool flag;
    scanf("%lld %lld", &m, &n);
    for(size_t i=0;i!=m;++i) {
        scanf("%lld %lld", &tp1, &tp2);
        danger[tp1].emplace_back(tp2);
        danger[tp2].emplace_back(tp1);
    }
    for(size_t i=0;i!=n; ++i) {
        scanf("%lld", &q);
        flag = true;
        for(size_t j=0;j!=q;++j)
            scanf("%lld", box+j);
        for(size_t j=0;j!=q;++j) {
            for(auto const &iter: danger[box[j]]) {
                for (size_t k=0;k!=q;++k) {
                    if (box[k]==iter) {
                        flag = false;
                        break;
                    }
                }
                if (!false) break;
            }
        }
        flag? printf("Yes\n"):
        printf("No\n");
    }
    return 0;
}

#endif //PAT_1149_HPP
