/*
P2078 朋友
题目描述:
    小明在 A 公司工作，小红在 B 公司工作。
    这两个公司的员工有一个特点：一个公司的员工都是同性。
    A 公司有 N 名员工，其中有 P 对朋友关系。B 公司有 M 名员工，其中有 Q 对朋友关系。
朋友的朋友一定还是朋友。
    每对朋友关系用两个整数 (Xi,Yi) 组成，表示朋友的编号分别为 Xi,Yi。男人的编号是正
数，女人的编号是负数。小明的编号是 11，小红的编号是 -1−1。
    大家都知道，小明和小红是朋友，那么，请你写一个程序求出两公司之间，通过小明和小红认识
的人最多一共能配成多少对情侣（包括他们自己）。
    输入格式:
    输入的第一行，包含 4 个空格隔开的正整数 N,M,P,Q。
    之后 P 行，每行两个正整数 Xi,Yi。
    之后 Q 行，每行两个负整数 Xi,Yi。
输出格式:
   输出一行一个正整数，表示通过小明和小红认识的人最多一共能配成多少对情侣（包括他们
自己）。
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P2078_HPP
#define PAT_P2078_HPP

#include <cstdio>

#define r(i,a,b) for(int (i)=a;i<=b;i++)

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

inline int find(int *grp, int x) {
    int r=x, tp;
    while(grp[r]!=r) r=grp[r];
    while(x!=r) {
        tp=x;
        x=grp[x];
        grp[tp]=r;
    }
    return r;
}

int main() {
    int n=read(), m=read(), p=read(), q=read(), l, r, t;
    int fn[n+1];for(int i=1;i<=n;++i) fn[i]=i;
    int fm[m+1];for(int i=1;i<=m;++i) fm[i]=i;
    while(p--) {
        l=read(), r=read();
        fn[find(fn, r)] = find(fn, l);
    }
    while(q--) {
        l=read(), r=read();
        fm[find(fm, r)] = find(fm, l);
    }
    l=0, r=0;
    for(int i=1;i<=n;++i) {
        if(find(fn, i)==find(fn, 1)) ++l;
    }
    for(int i=1;i<=m;++i) {
        if(find(fm, i)==find(fm, 1)) ++r;
    }
    printf("%d\n", l>r?r:l);
    return 0;
}

#endif //PAT_P2078_HPP
