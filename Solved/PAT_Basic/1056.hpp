//1056 组合数的和

#ifndef PAT_1056_HPP
#define PAT_1056_HPP

#include<cstdio>

int main() {
    int m, sum{}, tp;
    scanf("%d", &m);
    for(int i=0;i!=m;++i) {
        scanf("%d", &tp);
        sum+=11*(m-1)*tp;
    }
    printf("%d\n", sum);
    return 0;
}

#endif //PAT_1056_HPP
