//1081 Rational Sum

#ifndef PAT_1081_HPP
#define PAT_1081_HPP

#include <cstdio>
#include <algorithm>

inline long long read() {
    long long x{}, c=getchar(), neg{};
    while((c>'9'||c<'0')&&c!='-') c=getchar();
    if(c=='-') {++neg;c=getchar();}
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return neg?-x:x;
}

void ft(long long &an, long long &bn) {
    long long i=2, nf= true, a=an>0?an:-an, b=bn>0?bn:-bn;
    while(nf) {
        nf= false;
        for(;i<=a/2&&i<=b/2;++i) {
            if(a%i==0&&b%i==0) {
                nf= true;break;
            }
        }
        if(nf) an/=i, bn/=i, a/=i, b/=i;
    }
}

int main() {
    long long n=read(), ai=0, bi=1, at, bt;
    while(n--) {
        at=read(), bt=read();
        if(bt<0) bt=-bt, at=-at;
        ft(at, bt);
        ai=ai*bt+bi*at;
        bi*=bt;
        ft(ai, bi);
    }
    if(ai==0) {
        printf("0\n");
    }
    else if (ai>=bi) {
        printf("%d", ai/bi);
        if(ai%bi!=0) {
            putchar(' ');
            printf("%d/%d", ai%bi, bi);
        }
    } else {
        printf("%d/%d\n", ai, bi);
    }
}

#endif //PAT_1081_HPP
