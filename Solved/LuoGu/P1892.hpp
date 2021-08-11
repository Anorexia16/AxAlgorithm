/*
P1892 团伙
题目描述:
    给定 n 个人，他们之间有两个种关系，朋友与敌对。可以肯定的是：
        与我的朋友是朋友的人是我的朋友
        与我敌对的人有敌对关系的人是我的朋友
    现在这 n 个人进行组团，两个人在一个团队内当且仅当他们是朋友。

求最多的团体数。
输入格式:
    第一行一个整数 nn 代表人数。
    第二行一个整数 mm 代表每个人之间的关系。
    接下来 m 行每行一个字符 opt 与两个整数 p,q
输出格式:
    一行一个整数代表最多的团体数。
难度: 普及+/提高
历史分数--100
*/

#ifndef PAT_P1892_HPP
#define PAT_P1892_HPP

#include <unordered_set>
#include <cstdio>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int *grp;
inline int find(int x) {
    int r=x, tp;
    while(r!=grp[r]) r=grp[r];
    while(x!=r) {tp=x;x=grp[x];grp[tp]=r;}
    return r;
}

int main() {
    std::unordered_set<int> ans;
    int m=read(), r=read(), a, b, s{};
    grp=new int [2*m+1];
    for(int i=1;i<=2*m;++i) grp[i]=i;
    while(r--) {
        switch (getchar()) {
            case 'E':
                a=read(), b=read();
                grp[find(b+m)]=find(a);
                grp[find(a+m)]=find(b);
                break;
                default:
                    a=read(), b=read();
                    grp[find(b)]=find(a);
                    break;
        }
    }
    for(int i=1;i<=m;++i) {
        if(find(i)==i) ++s;
    }
    printf("%d", s);
    return 0;
}

#endif //PAT_P1892_HPP
