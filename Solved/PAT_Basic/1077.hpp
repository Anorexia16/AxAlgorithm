//1077 互评成绩计算

#ifndef PAT_1077_HPP
#define PAT_1077_HPP

#include <algorithm>
#include <cmath>
#include <cstdio>

int main() {
    int n, f, tp, tt, si;
    scanf("%d %d", &n, &f);
    int arr[n-1];
    double x;
    for(int i=0;i!=n;++i) {
        x=0.0, si=0;
        scanf("%d", &tt);
        for(int j=0;j!=n-1;++j) {
            scanf("%d", &tp);
            if (tp>=0&&tp<=f) {
                arr[si++] = tp;
            }
        }
        std::sort(arr, arr+si);
        for(int j=1;j<si-1;++j) x+=arr[j];
        if (si>2) x/=(si-2);
        x+=tt;
        if (si>2) x/=2;
        printf("%.0f\n", std::round(x));
    }
}

#endif //PAT_1077_HPP
