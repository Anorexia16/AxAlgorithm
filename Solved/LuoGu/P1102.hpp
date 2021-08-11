/*
P1102 A-B 数对
题目描述:
    出题是一件痛苦的事情！
    相同的题目看多了也会有审美疲劳，于是我舍弃了大家所熟悉的 A+B Problem，
    改用 A-B 了哈哈！
    好吧，题目是这样的：给出一串数以及一个数字 ，要求计算出所有 A−B=C 的数对
    的个数（不同位置的数字一样的数对算不同的数对）。
输入格式:
    输入共两行。
    第一行，两个整数 N, C。
    第二行，N 个整数，作为要求处理的那串数。
输出格式:
    一行，表示该串数中包含的满足 A - B = C 的数对的个数。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P1102_HPP
#define PAT_P1102_HPP

#include <cstdio>
#include <algorithm>

inline long long read() {
    int x{}, c=getchar(), neg{};
    while((c>'9'||c<'0')&&c!='-') c=getchar();
    if(c=='-') {++neg;c=getchar();}
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return neg?-x:x;
}

int main() {
    long long n=read(), dev=read(), arr[n], s{};
    for(int i=0;i!=n;++i) arr[i]=read();
    std::sort(arr, arr+n);
    for(int i=0;i!=n;++i)  {
        s+=std::upper_bound(arr, arr+i, arr[i]-dev)-
                std::lower_bound(arr, arr+i, arr[i]-dev);
    }
    printf("%ld", s);
}

#endif //PAT_P1102_HPP
