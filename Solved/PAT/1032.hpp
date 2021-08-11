// 1032 Sharing

#ifndef PAT_1032_HPP
#define PAT_1032_HPP

#include <cstdio>

int main() {
    long long int a, b, n{}, begin1, begin2, arr[100000],
            stack1[100000], stack2[100000], si1 {}, si2{}, end;
    char c;
    bool has = false;
    scanf("%lld%lld%lld", &begin1, &begin2, &n);
    for (size_t i=0;i!=n;++i) {
        scanf("%lld %c %lld", &a, &c, &b);
        arr[a] = b;
    }
    while(begin1 != -1) {
        stack1[si1++] = begin1;
        begin1 = arr[begin1];
    }
    while(begin2 != -1) {
        stack2[si2++] = begin2;
        begin2 = arr[begin2];
    }
    while (si1>0&&si2>0&&
           stack1[si1-1] == stack2[si2-1]) {
        has = true;
        end = stack1[si1-1];
        --si1;
        --si2;
    }
    if (has) {
        printf("%05lld\n", end);
    } else {
        printf("-1\n");
    }
    return 0;
}

#endif //PAT_1032_HPP
