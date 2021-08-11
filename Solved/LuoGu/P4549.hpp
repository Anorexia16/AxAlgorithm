/*
P4549 裴蜀定理
题目描述:
   给定一个包含 n 个元素的整数序列 A，记作 A1,A2,A3,...,An。
    求另一个包含 n 个元素的待定整数序列 X，记 S = ∑ Ai ×Xi ，
    使得 S>0 且 S 尽可能的小。
输入格式:
    第一行一个整数 n，表示序列元素个数。
    第二行 n 个整数，表示序列 A。
输出格式:
    一行一个整数，表示 S>0 的前提下 S 的最小值。
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P4549_HPP
#define PAT_P4549_HPP

#include <cstdio>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

inline int gcd(int x, int y) {
    return  y?gcd(y, x%y):x;
}

inline void write(int x) {
    if(x/10!=0) write(x/10);
    putchar(x%10+'0');
}

int main() {
    int n=read(), ans=0, tp;
    while(n--) {
        tp=read();
        ans=gcd(ans, tp);
    }
    write(ans);
    return 0;
}

#endif //PAT_P4549_HPP
