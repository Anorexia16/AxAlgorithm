//1066 部分A+B

#ifndef PAT_1016_HPP
#define PAT_1016_HPP

#include<cstdio>

int main() {
    size_t a, da, b, db, sa{}, sb{};
    scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
    while(a!=0) {
        if ((a%10)==da) {
            sa*=10;
            sa+=da;
        }
        a/=10;
    }
    while(b!=0) {
        if ((b%10)==db) {
            sb*=10;
            sb+=db;
        }
        b/=10;
    }
    printf("%lld\n", sa+sb);
    return 0;
}

#endif //PAT_1016_HPP
