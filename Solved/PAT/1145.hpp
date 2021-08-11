// 1145 Hashing - Average Search Time

#ifndef PAT_1145_HPP
#define PAT_1145_HPP

#include <cstdio>

int main() {
    size_t table[10007]{}, failed[10006], s, m , n, fi{};
    bool prime, puts, found;
    scanf("%lld%lld%lld", &s, &m, &n);
    while(++s)
    {
        prime = true;
        for (size_t i=2;i<=s/2;++i) {
            if (s%i==0) {
                prime= false;
                break;
            }
        }
        if (prime) break;
    }
    size_t ads, num;
    for(size_t i=0;i!=m;++i) {
        scanf("%d", &num);
        ads = num % s;
        puts = false;
        for (size_t j=0;j!=s;++j) {
            if (table[(ads+j*j)%s]==0) {
                table[(ads+j*j)%s] = num;
                puts = true;
                break;
            }
        }
        if (!puts) failed[fi++] = num;
    }
    size_t time {};
    for (size_t i=0;i!=n;++i) {
        scanf("%d", &num);
        ads = num%s;
        found = false;
        for (size_t j=0;j!=s;++j) {
            ++time;
            if (table[(ads+j*j)%s]==num||table[(ads+j*j)%s]==0) {
                found = true;
                break;
            }
        }
        if (!found) ++time;
    }
    for (size_t i=0;i!=fi;++i) {
        printf("%d cannot be inserted.\n", failed[i]);
    }
    float arr = (float)(time)/n;

    printf("%.1lf", arr);

    return 0;

}

#endif //PAT_1145_HPP
