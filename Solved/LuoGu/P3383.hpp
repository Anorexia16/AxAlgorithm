/*
P1836 数页码
题目描述:
    如题，给定一个范围 n，有 q 个询问，每次输出第 k 小的素数。
输入格式:
    第一行包含两个正整数 n,q，分别表示查询的范围和查询的个数。
    接下来 q 行每行一个正整数 k，表示查询第 k 小的素数。
输出格式:
    输出 q 行，每行一个正整数表示答案。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P3383_HPP
#define PAT_P3383_HPP

#include <cstdio>
#include <cstring>

bool isPrime[100000001];
int arr[6000000], si = 0;

inline int read() {
    int x{}, c= getchar();
    while(c>'9'||c<'0') c= getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

inline void write(int x) {
    if(x/10!=0) write(x/10);
    putchar('0'+x%10);
}

void GetPrime(int n)
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for(int i = 2; i <= n; ++i)
    {
        if(isPrime[i]) arr[++si] = i;
        for(int j = 1; j <= si && i * arr[j] <= n; ++j)
        {isPrime[i * arr[j]] = false;if(i % arr[j] == 0)break;}
    }
}

int main()
{
    int n=read(), q=read();
    GetPrime(n);
    while (q--)
    {
        int k=read();
        write(arr[k]);
        putchar('\n');
    }
    return 0;
}

#endif //PAT_P3383_HPP
