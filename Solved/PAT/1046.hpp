// 1046 Shortest Distance

#ifndef PAT_1046_HPP
#define PAT_1046_HPP

#include <cstdio>

size_t left_dis(size_t const &a, size_t const&b,
                size_t*arr, size_t const&n, size_t const &dis) {
    return arr[b] - arr[a];
}

size_t right_dis(size_t const &a, size_t const&b,
                 size_t*arr, size_t const&n, size_t const &dis) {
    return arr[n-1] - arr[b] + arr[a] + dis;
}

size_t min(size_t const &a, size_t const &b) {
    return a>b? b: a;
}

void swap(size_t &a, size_t &b) {
    size_t temp = a;
    a = b;
    b= temp;
}

int main() {
    size_t arr[100000], n, m, dis, left, right;
    scanf("%lld", &n);
    arr[0] = 0;
    for (size_t i=1;i!=n;++i) {
        scanf("%lld", arr+i);
        arr[i] += arr[i-1];
    }
    scanf("%lld", &dis);
    scanf("%lld", &m);
    for(size_t i=0;i!=m; ++i) {
        scanf("%lld %lld", &left, &right);
        left-=1;
        right-=1;
        if (left > right) swap(left, right);
        printf("%lld\n", min(
                left_dis(left, right, arr, n, dis),
                right_dis(left, right, arr, n, dis)));
    }
    return 0;
}

#endif //PAT_1046_HPP
