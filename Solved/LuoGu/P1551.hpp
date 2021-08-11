/*
P1551 亲戚
题目描述:
        若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个
    亲戚关系图，求任意给出的两个人是否具有亲戚关系。
        规定：x 和 y 是亲戚，y 和 z 是亲戚，那么 x 和 z 也是亲戚。如果 x，y 是
    亲戚，那么 x 的亲戚都是 y 的亲戚，y 的亲戚也都是 x 的亲戚。
输入格式:
        第一行：三个整数 n,m,p（n,m,p≤5000），分别表示有 n 个人，m 个亲戚关系，
    询问 p 对亲戚关系。
        以下 m 行：每行两个数 Mi，Mj，1<= Mi,M <=N，表示 Mi和Mj具有亲戚关系。
    接下来 p 行：每行两个数 Pi,Pj，询问 Pi和 Pj是否具有亲戚关系。
输出格式:
    p 行，每行一个 Yes 或 No。表示第 i 个询问的答案为“具有”或“不具有”亲戚关系。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P1551_HPP
#define PAT_P1551_HPP

#include <cstdio>

inline int read() {
    int x{}, c=getchar();
    while (c>'9'||c<'0') c=getchar();
    while (c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int *grp;
int find(int x) {
    int r=x, tp;
    while(r!=grp[r]) r=grp[r];
    while(x!=r) {tp=x;x=grp[x];grp[tp]=r;}
    return r;
}

int main() {
    int n=read(), p=read(), q=read(), l, r, t;
    grp=new int [n+1];
    for(int i=1;i<=n;++i) grp[i]=i;
    while(p--) {
        l=read(), r=read();
        if(l>r) {t=l;l=r;r=t;}
        grp[find(l)] = find(r);
    }
    while(q--) {
        l=read(), r=read();
        find(l)==find(r)?printf("Yes\n"):printf("No\n");
    }
    return 0;
}

#endif //PAT_P1551_HPP
