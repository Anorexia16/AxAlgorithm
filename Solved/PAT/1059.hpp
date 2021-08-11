//1059 arr Factors

#ifndef PAT_1059_HPP
#define PAT_1059_HPP

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cstdio>

struct pr {
    long int base{}, t{};
    bool operator<(pr const &op) const {return base<op.base;}
};

int main() {
    std::unordered_map<long int ,long int> mp;
    std::vector<pr> vec; bool pd{};
    int t, n, i; scanf("%ld", &n); t=n;
    while(n!=1) {
        for(i=2;i<=n;) {
            if(n%i==0) {
                ++mp[i], n/=i;
            } else {
                ++i;
            }
        }
    }
    if(mp.empty()) {
        printf("%ld=%ld\n", t, t);
        return 0;
    }
    vec.reserve(mp.size());
    for(auto const &iter:mp) {
        vec.emplace_back(pr{iter.first, iter.second});
    }
    std::sort(vec.begin(), vec.end());
    printf("%ld=", t);
    for(auto const &iter:vec) {
        if(pd) putchar('*');
        pd= true;
        printf("%ld", iter.base);
        if(iter.t>1) printf("^%ld", iter.t);
    }
    putchar('\n');
    return 0;
}

#endif //PAT_1059_HPP
