/*
P3367 并查集
题目描述:
   如题，现在有一个并查集，你需要完成合并和查询操作。
输入格式:
    第一行包含两个整数 N,M ,表示共有 N 个元素和 M 个操作。
    接下来 M 行，每行包含三个整数 Zi,Xi,Yi。
    当 Zi=1 时，将 Xi 与 Yi 所在的集合合并。
    当 Zi=2 时，输出 Xi 与 Yi 是否在同一集合内，是的输出Y；否则输出N 。
输出格式:
    对于每一个 Zi=2 的操作，都有一行输出，每行包含一个大写字母，为Y或者N。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P3367_HPP
#define PAT_P3367_HPP

#include <cstdio>

int *grp;

int find(int x) {
    int r=x, tp;
    while(r!=grp[r]) r=grp[r];
    while(x!=r) {
        tp=x;
        x=grp[x];
        grp[tp]=r;
    }
    return r;
}

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    int n=read(), q=read(), z, l, r, tp;
    grp = new int [n+1];
    for(int i=1;i<=n;++i) grp[i]=i;
    while(q--) {
        z=read(), l=read(), r=read();
        if(l>r) {tp=l;l=r;r=tp;}
        if(z==1) {
            grp[find(l)]=grp[find(r)];
        } else {
            find(l)==find(r)?printf("Y\n"):printf("N\n");
        }
    }
    return 0;
}

#endif //PAT_P3367_HPP
