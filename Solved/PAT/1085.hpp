//1085 Perfect Sequence

#ifndef PAT_1085_HPP
#define PAT_1085_HPP

#include <algorithm>
#include <cstdio>

inline long long read() {
    long long x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    long long n=read(), p=read(), arr[n], wid, max=0;
    for(size_t i=0;i!=n;++i) arr[i]=read();
    std::sort(arr, arr+n);
    for(int i=0;i<n;i++){
        wid=std::upper_bound(arr+i, arr+n, p*arr[i])-arr-i;
        max=max>wid?max:wid;
    }
    printf("%lld\n", max);
    return 0;
}

#endif //PAT_1085_HPP
