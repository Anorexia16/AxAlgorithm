//1045 快速排序

#ifndef PAT_1045_HPP
#define PAT_1045_HPP

#include <cstdio>
#include <algorithm>
#include <vector>

int main() {
    size_t n, m{};
    std::vector<size_t> vec;
    scanf("%lld", &n);
    size_t arr[n], sort[n];
    for(size_t i=0;i!=n;++i) scanf("%lld", arr+i);
    for(size_t i=0;i!=n;++i) sort[i]=arr[i];
    std::sort(sort, sort+n);
    for(size_t i=0;i!=n;++i) {
        if (m<arr[i]) m = arr[i];
        if (arr[i]==sort[i]&&sort[i]==m)
            vec.emplace_back(arr[i]);
    }
    n = vec.size();
    printf("%lld\n", n);
    for(size_t i=0;i!=n;++i) {
        if (i!=0) printf(" ");
        printf("%lld", vec[i]);
    }
    printf("\n");
    return 0;
}

#endif //PAT_1045_HPP
