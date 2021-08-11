//1070 结绳

#ifndef PAT_1070_HPP
#define PAT_1070_HPP

#include <algorithm>
#include <cstdio>
#include <cmath>

int main() {
    long long arr[10000];
    long double length;
    size_t n;
    scanf("%lld", &n);
    for (size_t i=0;i!=n;++i) scanf("%lld", arr+i);
    std::sort(arr, arr+n);
    length = arr[0];

    for(size_t i=1;i!=n;++i) {
        length+=arr[i];
        length/=2;
    }
    printf("%lld\n", (size_t)(length));
}

#endif //PAT_1070_HPP
