/*
P3390 矩阵快速幂
题目描述:
   给定n×n 的矩阵 A，求 A^k。
输入格式:
    第一行两个整数 n,k 接下来n行，每行n个整数，第i行的第j的数表示 A[i,j]。
输出格式:
    输出 A^k
    共n行，每行n个数，第i行第j个数表示 (A^k)[i,j]，每个元素对 10^9+7取模。
难度:
    普及/提高-
历史分数--100
*/
#ifndef PAT_P3390_HPP
#define PAT_P3390_HPP

#include <cstdio>

constexpr long Mod = 1000000007;
inline long read() {
    long x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}
struct Matrix {
    long long c[101][101];
} A,I;
long long n,p;

Matrix operator*(const Matrix &x,const Matrix &y) {
    Matrix a{};
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            a.c[i][j]=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            for(int k=1; k<=n; k++) {
                a.c[i][j]+=x.c[i][k]*y.c[k][j]%Mod;
                a.c[i][j]%=Mod;
            }
    return a;
}

int main() {
    n=read(), p=read();
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            A.c[i][j]=read();
    for(int i=1; i<=n; i++)
        I.c[i][i]=1;
    while(p>0) {
        if(p%2==1) I=I*A;
        if(p>1)A=A*A;
        p=p>>1;
    }
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            printf("%ld ", I.c[i][j]);
        putchar('\n');
    }
    return 0;
}


#endif //PAT_P3390_HPP
