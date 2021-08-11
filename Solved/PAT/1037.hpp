// 1037 Magic Coupon

#ifndef PAT_1037_HPP
#define PAT_1037_HPP

#include <algorithm>
#include <cstdio>

int main() {
    ssize_t nc [100000], np[100000];
    unsigned long N, P;
    scanf("%ul", &N);
    for(size_t i=0;i!=N;++i) {
        scanf("%lld", nc + i);
    }
    scanf("%ul", &P);
    for(size_t i=0;i!=P;++i) {
        scanf("%lld", np + i);
    }

    ssize_t sum {};
    std::make_heap(nc, nc+N);
    std::make_heap(np, np+P);
    while(nc[0]>=0&&np[0]>=0&&N>0&&P>0) {
        sum += nc[0] * np[0];
        std::pop_heap(nc, nc+N);
        std::pop_heap(np, np+P);
        --N;
        --P;
    }

    for(size_t i=0; i!=N; ++i) {
        nc[i] = -nc[i];
        np[i] = -np[i];
    }
    std::make_heap(nc, nc+N);
    std::make_heap(np, np+P);

    while(nc[0]>=0&&np[0]>=0&&N>0&&P>0) {
        sum += nc[0] * np[0];
        std::pop_heap(nc, nc+N);
        std::pop_heap(np, np+P);
        --N;
        --P;
    }

    printf("%lld", sum);

    return 0;
}


#endif //PAT_1037_HPP
