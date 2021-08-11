/*
P3374 树状数组 1
题目描述：
    如题，已知一个数列，你需要进行下面两种操作：
    1.将某一个数加上 x
    2.求出某区间每一个数的和
输入格式：
    第一行包含两个正整数 n,m，分别表示该数列数字的个数和操作的总个数。
    第二行包含 nn 个用空格分隔的整数，其中第 i 个数字表示数列第 i 项的初始值。
    接下来 m 行每行包含 3 个整数，表示一个操作，具体如下：
    1 x k 含义：将第 x 个数加上 k
    2 x y 含义：输出区间 [x,y] 内每个数的和
输出格式：
    输出包含若干行整数，即为所有操作 22 的结果。
难度:
    普及/提高-
历史分数--100
*/

#ifndef PAT_P3374_HPP
#define PAT_P3374_HPP

#include <cstdio>

constexpr int const n = 500000;

int arr[n] {};

inline int bit(int x) {
    return x&(-x);
}

void add(int x, int v) {
    for(;x<=n;x += bit(x)) arr[x] += v;
}

int sum(int x) {
    int s{};
    for(;x>0;x-= bit(x)) s+=arr[x];
    return s;
}

int main() {
    int m, op, t1, t2;
    scanf("%d%d", &m, &op);
    for(int i=1;i<=m;++i) {
        scanf("%d", &t1);
        add(i, t1);
    }
    while(op--) {
        scanf("%d", &t1);
        if(t1==1) {
            scanf("%d%d", &t1, &t2);
            add(t1, t2);
        } else {
            scanf("%d%d", &t1, &t2);
            printf("%d\n", sum(t2) - sum(t1-1));
        }
    }
    return 0;
}

#endif //PAT_P3374_HPP
