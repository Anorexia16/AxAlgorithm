/*
P3865 ST表
题目描述:
        这是一道 ST 表经典题——静态区间最大值
    请注意最大数据时限只有 0.8s，数据强度
    不低，请务必保证你的每次查询复杂度为 O(1)。
    若使用更高时间复杂度算法不保证能通过。
        如果您认为您的代码时间复杂度正确但是 TLE，
    可以尝试使用快速读入。
    给定一个长度为 N 的数列，和 M 次询问，求出每一
    次询问的区间内数字的最大值。

输入格式:
    第一行包含两个整数 N,M, 分别表示数列的长度和询问的个数。
    第二行包含 N 个整数（记为 a_ia依次表示数列的第 i 项。
    接下来 M 行，每行包含两个整数 l_i,r_i，表示查询的区
    间为 [l_i,r_i]
输出格式:
    输出包含 M 行，每行一个整数，依次表示每一次询问的结果。
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P3865_HPP
#define PAT_P3865_HPP

#include<cstdio>
#include<cmath>
int ST[100005][20];
int lgs[100005],n,m, l, r, lg;

inline int read()
{
    int x=0,fs=1;char ch=static_cast<char>(getchar());
    while (ch<'0'||ch>'9'){if (ch=='-') fs=-1;ch=static_cast<char>(getchar());}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=static_cast<char>(getchar());}
    return x * fs;
}

int main()
{
    n=read(),m=read();
    lgs[1]=0, lgs[2]=1;
    for(int i=3;i<=n;i++)
        lgs[i]= lgs[i / 2] + 1;
    for(int i=1;i<=n;i++)
        ST[i][0]=read();
    for(int i=1; i <= 20; i++)
        for(int j=1; j + (1 << i) - 1 <= n; j++)
            ST[j][i]=std::max(ST[j][i - 1], ST[j + (1 << (i - 1))][i - 1]);
    for(size_t i=0;i!=m;++i) {
        l=read(), r=read();
        lg=lgs[r - l + 1];
        printf("%d\n",std::max(ST[l][lg], ST[r - (1 << lg) + 1][lg]));
    }
    return 0;
}


#endif //PAT_P3865_HPP
