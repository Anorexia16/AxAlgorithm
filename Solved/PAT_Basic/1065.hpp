//1065 单身狗

#ifndef PAT_1065_HPP
#define PAT_1065_HPP

#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>

int main() {
    std::map<size_t, size_t> partner{};
    std::vector<size_t> guest, along;
    size_t pair, n, tp1, tp2;
    bool find;
    scanf("%lld", &pair);
    for(size_t i=0;i!=pair;++i) {
        scanf("%lld %lld", &tp1, &tp2);
        partner[tp1] = tp2;
        partner[tp2] = tp1;
    }
    scanf("%lld", &n);
    guest.reserve(n);
    along.reserve(n);
    for (size_t i=0;i!=n;++i) {
        scanf("%lld", &tp1);
        guest.emplace_back(tp1);
    }
    for (size_t i=0;i!=n;++i) {
        if (partner.find(guest[i])==partner.end()) {
            along.emplace_back(guest[i]);
        } else {
            find = false;
            tp1 = partner[guest[i]];
            for(size_t j=0;j!=n;++j) {
                if (guest[j]==tp1) {
                    find=true;
                    break;
                }
            }
            if (!find) along.emplace_back(guest[i]);
        }
    }
    tp2 = along.size();
    printf("%lld\n", tp2);
    std::sort(std::begin(along), std::end(along));
    for(size_t i=0;i!=tp2;++i) {
        i==tp2-1? printf("%05lld\n", along[i]):
        printf("%05lld ", along[i]);
    }
    return 0;
}

#endif //PAT_1065_HPP
