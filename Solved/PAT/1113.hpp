// 1113 Integer Set Partition

#ifndef PAT_1113_HPP
#define PAT_1113_HPP

#include <cstdio>
#include <algorithm>

int main() {
    size_t N, num[100000], sum{};
    scanf("%lld", &N);
    for(size_t i=0;i!=N; ++i) {
        scanf("%lld", num+i);
    }
    printf("%lld ", N%2);
    std::sort(num, num+N);
    for(size_t i=0;i!=N/2;++i) {
        sum += num[N-1-i] - num[i];
    }
    if (N%2==1) sum+= num[N/2];
    printf("%lld\n", sum);
    return 0;
}

#endif //PAT_1113_HPP
