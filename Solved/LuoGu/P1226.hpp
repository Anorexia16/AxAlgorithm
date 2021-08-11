/*
P1226 快速幂||取余运算
题目描述:
    给你三个整数 a,b,pa,b,p，求 a^b mod p。
输入格式:
    输入只有一行三个整数，分别代表 a,b,p。
输出格式:
    输出一行一个字符串 a^b mod p=s，其中 a,b,p 分别为题目给定的值，
    s 为运算结果。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P1226_HPP
#define PAT_P1226_HPP

#include <cstdio>

inline size_t read() {
    size_t x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

inline size_t pow(size_t base, size_t p, size_t r) {
    if(base==0) return 0;
    size_t ans = 1;
    while(p) {
        if(p&1) {ans*=base;ans%=r;--p;}
        if(p) {base*=base;base%=r;p/=2;}
    }
    return ans%r;
}

int main() {
    size_t a=read(), b=read(), r=read();
    printf("%lld^%lld mod %lld=%lld", a, b, r, pow(a, b, r));
    return 0;
}

#endif //PAT_P1226_HPP
