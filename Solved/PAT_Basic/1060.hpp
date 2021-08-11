//1060 爱丁顿数

#ifndef PAT_1060_HPP
#define PAT_1060_HPP

#include <cstdio>
#include <algorithm>

int main () {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0;i!=n;++i) scanf("%d", a+i);
    std::sort(a, a+n);
    std::reverse(a, a+n);
    if (a[0]==0) {
        printf("0\n");
        return 0;
    }
    for(int j{};j!=n;++j) {
        if (a[j]<=j+1) {
            printf("%d\n", j);
            return 0;
        }
    }
    printf("%d\n", n);
    return 0;
}

#endif //PAT_1060_HPP
