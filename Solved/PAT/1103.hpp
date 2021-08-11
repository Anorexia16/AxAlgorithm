//1103 Integer Factorization

#ifndef PAT_1103_HPP
#define PAT_1103_HPP

#include <algorithm>
#include <cstdio>

size_t *ps, p;

inline size_t read() {
    size_t x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

size_t *var, *ans, num, n;

size_t pow(size_t const &b) {
    size_t base=b, tp=p, res=1;
    if(b==0) return 0;
    if(ps[b]!=0) return ps[base];
    while(tp) {
        if(tp&1) {res*=base;--tp;}
        if(tp) {base*=base;tp/=2;}
    }
    ps[b] = res;
    return res;
}

bool cmp() {
    for(int i=0;i!=n;++i) {
        if (var[i]>ans[i]) {
            return true;
        } else if (var[i]<ans[i]) {
            return false;
        }
    }
}

int main() {
    num = read(), n = read(), p=read();
    ps = new size_t [num] {};
    var = new size_t [num] {};
    ans = new size_t [num] {};
    size_t si{}, sum{}, as{}, ts;
    while(true) {
        sum-=pow(var[si]);
        ++var[si];
        sum+=pow(var[si]);
        if(sum==num&&n-1==si) {
            ts=0;
            std::sort(var, var+n);
            std::reverse(var, var+n);
            for(size_t i=0;i!=n;++i) ts+=var[i];
            if(ts>=as&&cmp()) {
                for(size_t i=0;i!=n;++i) ans[i]=var[i];
                as=ts;
            }
        }
        if(sum>=num||(si!=0&&var[si]>var[si-1])) {
            if(si==0) {
                break;
            } else {
                sum-=pow(var[si]);
                var[si]=0;
                --si;
            }
        } else {
            if(si!=n-1) ++si;
        }
    }
    if(ans[0]==0) {printf("Impossible\n");return 0;}
    printf("%lld = ", num);
    for(int i=0;i!=n;++i) {
        printf("%lld^%lld", ans[i], p);
        i==n-1? putchar('\n'): printf(" + ");
    }
}

#endif //PAT_1103_HPP
