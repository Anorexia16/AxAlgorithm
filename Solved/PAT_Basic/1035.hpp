//1035 插入与归并

#ifndef PAT_1035_HPP
#define PAT_1035_HPP

#include<iostream>
#include<algorithm>

int n, a[101] = {0}, b[101] = {0}, temp[101] = {0};
bool flag = false;

bool isSame() {
    for (int i = 1; i <= n; ++i)
        if (a[i] != b[i]) return false;
    return true;
}

void print(int t) {
    if (t == 0) printf("Insertion Sort\n");
    else if (t == 1)printf("Merge Sort\n");
    else;
    for (int i = 1; i <= n; ++i) {
        printf("%d", a[i]);
        if (i < n) printf(" ");
    }
    printf("\n");
}

void insertSort() {
    for (int i = 2; i <= n; ++i) {
        if (a[i] < a[i - 1]) {
            int j = i;
            a[0] = a[i];
            while (a[j - 1] > a[0]) {
                a[j] = a[j - 1];
                --j;
            }
            a[j] = a[0];
        }
        if (isSame() && flag == false) {
            flag = true;
            continue;
        }
        if (flag == true) {
            print(0);
            return;
        }
    }
}

void mergeSort() {
    for (int step = 2; step / 2 <= n; step *= 2) {
        for (int i = 1; i <= n; i += step)
            std::sort(a + i, a + std::min(i + step, n + 1));
        if (isSame() && flag == false) {
            flag = true;
            continue;
        }
        if (flag == true) {
            print(1);
            return;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        temp[i] = a[i];
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", b+i);
    insertSort();
    if (flag == false) {
        for (int i = 1; i <= n; ++i)
            a[i] = temp[i];
        mergeSort();
    }
}

#endif //PAT_1035_HPP
