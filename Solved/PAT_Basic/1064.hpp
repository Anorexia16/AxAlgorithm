//1064 朋友数

#ifndef PAT_1064_HPP
#define PAT_1064_HPP

#include <set>
#include <cstdio>

size_t sum(size_t x) {
    size_t ans{};
    while(x!=0) {
        ans+=x%10;
        x/=10;
    }
    return ans;
}

int main() {
    size_t n, tp;
    std::set<size_t> set {};
    scanf("%lld", &n);
    size_t num[n];
    for(size_t i=0;i!=n;++i) {
        scanf("%lld", &tp);
        num[i] = sum(tp);
    }
    for(size_t i=0;i!=n;++i) {
        for(size_t j=i;j!=n;++j) {
            if (num[i]==num[j]) {
                set.insert(num[i]);
                break;
            }
        }
    }
    n = set.size(), tp = 0;
    printf("%lld\n", n);
    for(auto const &iter: set) {
        printf("%lld", iter);
        if (tp++!=n-1) printf(" ");
    }
    printf("\n");
    return 0;
}

#endif //PAT_1064_HPP
