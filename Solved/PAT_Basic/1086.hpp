//1086 就不告诉你

#ifndef PAT_1086_HPP
#define PAT_1086_HPP

#include <cstdio>

int main () {
    size_t a, b;
    scanf("%lld%lld", &a, &b);
    a*=b;
    b=0;
    while(a!=0) {
        b*=10;
        b+=a%10;
        a/=10;
    }
    printf("%lld", b);
    return 0;
}

#endif //PAT_1086_HPP
