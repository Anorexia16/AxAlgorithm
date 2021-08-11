//1034 有理数四则运算

#ifndef PAT_1034_HPP
#define PAT_1034_HPP

#include <cstdio>

inline long long abs(long long x) {return x>0?x:-x;}

long long max(long long a, long long b) {
    return b==0? a:max(b, a%b);
}

long long gcd(long long a, long long b) {
    if (a*b==0) return 1;
    a = abs(a), b= abs(b);
    return max(a, b);
}

void ipr(long long x, long long y) {
    bool neg{};
    if (y==0) {
        printf("Inf");
    } else if (x==0) {
        printf("0");
    } else {
        if (x<0) {
            printf("(-");
            neg = true;
            x=-x;
        }
        if (x>=y) {
            printf("%lld", x/y);
            if (x%y!=0) {
                printf(" %lld/%lld", x%y, y);
            }
        } else {
            printf("%lld/%lld", x, y);
        }
        if (neg) printf(")");
    }
}

int main() {
    long long a, b, c, d, t1, t2, r1, r2;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    if (b<0) a=-a, b=-b;
    if (d<0) c=-c, d=-d;
    t1 = gcd(a, b), t2 = gcd(c, d);
    a/=t1, b/=t1, c/=t2, d/=t2;

    r2 = b*d;
    r1 = a*d+b*c;
    t1 = gcd(r1, r2);
    r2/=t1, r1/=t1;
    ipr(a, b), printf(" + "), ipr(c, d),
            printf(" = "), ipr(r1, r2), printf("\n");

    r2 = b*d;
    r1 = a*d-b*c;
    t1 = gcd(r1, r2);
    r2/=t1, r1/=t1;
    ipr(a, b), printf(" - "), ipr(c, d),
            printf(" = "), ipr(r1, r2), printf("\n");

    r2 = b*d;
    r1 = a*c;
    t1 = gcd(r1, r2);
    r2/=t1, r1/=t1;
    ipr(a, b), printf(" * "), ipr(c, d),
            printf(" = "), ipr(r1, r2), printf("\n");

    r2 = b*c;
    r1 = a*d;
    if (r2<0) r2=-r2, r1=-r1;
    t1 = gcd(r1, r2);
    r2/=t1, r1/=t1;
    ipr(a, b), printf(" / "), ipr(c, d),
            printf(" = "), ipr(r1, r2), printf("\n");

    return 0;
}

#endif //PAT_1034_HPP
