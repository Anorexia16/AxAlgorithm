// 1044 Shopping in Mars

#ifndef PAT_1044_HPP
#define PAT_1044_HPP

#include <cstdio>

int main() {
    unsigned long long N, M, chain[100000], bi{}, sum{}, oi{}, left[100000], right[100000], min;
    bool no_am = true;
    scanf("%ull", &N);
    scanf("%ull", &M);
    for(size_t i=0;i!=N;++i) scanf("%uul", chain+i);
    for(size_t i=0;i!=N;++i) {
        sum+=chain[i];
        while(bi<=i) {
            if (sum<M) {
                break;
            } else {
                if (sum-chain[bi]<M) {
                    if (no_am) {
                        no_am= false;
                        min=sum-M;
                        left[oi] = bi;
                        right[oi++] = i;
                    } else if (sum-M<min) {
                        min=sum-M;
                        oi=0;
                        left[oi] = bi;
                        right[oi++] = i;
                    } else if (sum-M==min) {
                        left[oi] = bi;
                        right[oi++] = i;
                    }
                    break;
                } else {
                    sum-=chain[bi++];
                }
            }
        }
    }

    for (size_t i=0;i!=oi;++i) {
        printf("%d-%d\n", left[i]+1, right[i]+1);
    }
}

#endif //PAT_1044_HPP
