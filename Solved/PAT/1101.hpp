// 1101 Quick Sort

#ifndef PAT_1101_HPP
#define PAT_1101_HPP

#include<cstdio>

int main() {
    long n, arr[100000], max[100000], min[100000], t{}, ans[100000];
    scanf("%d", &n);
    for(long i=0;i!=n;++i) scanf("%d", arr+i);
    max[0] = 0;
    for(long i=1;i<n;++i) max[i]=max[i-1]>arr[i-1]?max[i-1]:arr[i-1];
    min[n-1] = 1000000000;
    for(long i=n-2;i>=0;--i) {
        min[i] = min[i + 1] < arr[i + 1] ? min[i + 1] : arr[i + 1];
    }
    for(long i=0; i!=n;++i) {
        if (arr[i]>max[i]&&arr[i]<min[i]) {
            ans[t++] = arr[i];
        }
    }
    printf("%d\n", t);
    for(long i=0;i!=t;++i)
    {
        printf("%d", ans[i]);
        i<t-1? printf(" "):printf("\n");
    }
    if (t==0) printf("\n");
    return 0;
}

#endif //PAT_1101_HPP
