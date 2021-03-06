/*
P1918 保龄球
题目描述:
        DL 算缘分算得很烦闷，所以常常到体育馆去打保龄球解闷。因为他保龄球已经
    打了几十年了，所以技术上不成问题，于是他就想玩点新花招。
        DL 的视力真的很不错，竟然能够数清楚在他前方十米左右每个位置的瓶子的
    数量。他突然发现这是一个炫耀自己好视力的借口——他看清远方瓶子的个数后从某个
    位置发球，这样就能打倒一定数量的瓶子。
    1 OOO
    2 OOOO
    3 O
    4 OO
        如上图，每个“O”代表一个瓶子。如果 DL 想要打倒 3 个瓶子就在 1 位置
    发球，想要打倒 4 个瓶子就在 2 位置发球。
        现在他想要打倒 m 个瓶子。他告诉你每个位置的瓶子数，请你给他一个发球位置。
输入格式:
    输入文件名为 bowling.in。
        第一行包含一个正整数 n，表示位置数。
        第二行包含 n 个正整数，第 i 个数。表示第 i 个位置的瓶子数，保证各个
    位置的瓶子数不同。
        第三行包含一个正整数 Q，表示 DL 发球的次数。
        第四行至文件末尾，每行包含一个正整数 m，表示 DL 需要打倒 m 个瓶子。
输出格式:
    输出文件名为 bowling.out。
        共 Q 行。每行包含一个整数，第 i 行的整数表示 DL 第 i 次的发球位置。
    若无解，则输出 0。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P1918_HPP
#define PAT_P1918_HPP
#include <cstdio>
#include <unordered_map>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    std::unordered_map<int, int> mp;
    int n=read(), tp;
    for(int i=0;i!=n;++i) {
        tp=read();
        mp[tp]=i+1;
    }
    tp=read();
    while(tp--) {
        printf("%d\n", mp[read()]);
    }
    return 0;
}

#endif //PAT_P1918_HPP
