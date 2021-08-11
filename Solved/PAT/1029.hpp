//1029 Median

#ifndef PAT_1029_HPP
#define PAT_1029_HPP

#include <cstdio>

size_t read() {
    size_t x=0; char c= getchar();
    while(c<'0'||c>'9') c = getchar();
    while('0'<=c&&'9'>=c) {x=10*x+c-'0'; c= getchar();}
    return x;
}

int main() {
    size_t m, n, mi{}, ni{}, mid, i{};
    m = read();
    size_t a[m];
    for(size_t i=0;i!=m;++i) a[i] = read();
    n = read();
    size_t b[n];
    for(size_t i=0;i!=n;++i) b[i] = read();
    mid = (m+n-1)/2;
    while (mid>i&&mi<m&&ni<n)
    {
        if (a[mi] < b[ni]) ++mi;
        else ++ni;
        ++i;
    }
    if (mi==m) printf("%lld\n", b[mid-m]);
    else if (ni==n) printf("%lld\n", a[mid-n]);
    else printf("%lld\n", a[mi]<b[ni]?a[mi]:b[ni]);
    return 0;
}

#endif //PAT_1029_HPP
