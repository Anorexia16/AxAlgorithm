// 1030 完美数列

#ifndef PAT_1030_HPP
#define PAT_1030_HPP

#include <cstdio>
#include <algorithm>

int main(){
    size_t n,p;
    scanf("%lld%lld", &n, &p);
    size_t a[n];
    int max=0;
    for(int i=0;i<n;i++) scanf ("%lld", a+i);
    std::sort(a,a+n);
    int cnt=0;
    for(int i=0;i<n;i++){
        int j=cnt;
        while(j++<n)
            if(a[j]>a[i]*p)
                break;
        max= max > j - i ? max : j - i;
        cnt=j;
    }
    printf("%lld\n", max);
    return 0;
}


#endif //PAT_1030_HPP
