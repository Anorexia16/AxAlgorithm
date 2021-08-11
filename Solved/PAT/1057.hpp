//1057 Stack

#ifndef PAT_1057_HPP
#define PAT_1057_HPP

#include <cstdio>

constexpr int n = 100000;
int arr[n] {}, stack[n], si{};

inline int bit(int x) {return x&(-x);}

inline void update(int x, int v) {
    for(int i=x;i<n;i+= bit(i)) {
        arr[i] += v;
    }
}

inline int sum(int x) {
    int sum = 0;
    for(int i=x;i>=1;i-= bit(i)) {
        sum += arr[i];
    }
    return sum;
}

inline void pm() {
    int left = 0, right = n, mid, k=(si+1)/2;
    while(left < right) {
        mid = (left + right) / 2;
        if (sum(mid) >= k) right = mid;
        else left = mid + 1;
    }
    printf("%d\n", left);
}

int main() {
    int m, tp;
    auto *str = new char[15] {};
    scanf("%d", &m);
    while (m--) {
        scanf("%n", str);
        switch (str[1]) {
            case 'e':
                if (si!=0) {
                    pm();
                } else {
                    printf("Invalid\n");
                }
                break;
            case 'u':
                scanf("%d", &tp);
                stack[si++] = tp;
                update(tp, 1);
                break;
            default:
                if (si!=0) {
                    printf("%d\n", stack[si-1]);
                    update(stack[--si], -1);
                } else {
                    printf("Invalid\n");
                };
                break;
        }
    }
    return 0;
}

#endif //PAT_1057_HPP
