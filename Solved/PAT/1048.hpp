// 1048 Find Coins

#ifndef PAT_1048_HPP
#define PAT_1048_HPP

#include <cstdio>
#include <algorithm>
#include <map>

int main() {
    size_t n, tp, sum;
    std::map<size_t, size_t> map {};
    bool flag = false;
    scanf("%lld%lld", &n, &sum);
    for(size_t i=0;i!=n;++i) {
        scanf("%lld", &tp);
        map[tp]+=1;
    }
    for(auto const &iter: map) {
        if (2*iter.first==sum) {
            if (iter.second>=2) {
                printf("%lld %lld\n", iter.first, iter.first);
                flag = true;
                break;
            }
        } else {
            if (map.find(sum - iter.first) != map.end()) {
                printf("%lld %lld\n", iter.first, map.find(sum - iter.first)->first);
                flag = true;
                break;
            }
        }
    }
    if(!flag) printf("No Solution\n");
    return 0;
}

#endif //PAT_1048_HPP
