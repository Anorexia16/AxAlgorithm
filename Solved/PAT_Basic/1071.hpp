//1071 小赌怡情

#ifndef PAT_1071_HPP
#define PAT_1071_HPP

#include <cstdio>

int main() {
    size_t total, n, f, e, bit, dev;
    scanf("%lld %lld", &total, &n);
    for(size_t i=0;i!=n;++i) {
        scanf("%lld%lld%lld%lld", &f, &bit, &dev, &e);
        if (dev>total) {
            printf("Not enough tokens.  Total = %lld.\n", total);
        } else if ((e>f&&bit==1)||(e<f&&bit==0)) {
            total += dev;
            printf("Win %lld!  Total = %lld.\n", dev, total);
        } else {
            total-=dev;
            printf("Lose %lld.  Total = %lld.\n", dev, total);
        }
        if (total==0) {
            printf("Game Over.\n");
            return 0;
        }
    }
    return 0;
}


#endif //PAT_1071_HPP
