/*
P1536 村村通
题目描述:
        某市调查城镇交通状况，得到现有城镇道路统计表。表中列出了每条道路直接连通的城镇。
    市政府 "村村通工程" 的目标是使全市任何两个城镇间都可以实现交通（但不一定有直接的道
    路相连，只要相互之间可达即可）。请你计算出最少还需要建设多少条道路？
输入格式:
        输入包含若干组测试测试数据，每组测试数据的第一行给出两个用空格隔开的正整数，分
    别是城镇数目 n 和道路数目 m ；随后的 m 行对应 m 条道路，每行给出一对用空格隔开的
    正整数，分别是该条道路直接相连的两个城镇的编号。简单起见，城镇从 1 到 n 编号。
        注意：两个城市间可以有多条道路相通。
输出格式:
    对于每组数据，对应一行一个整数。表示最少还需要建设的道路数目。
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P1536_HPP
#define PAT_P1536_HPP

#include <unordered_set>
#include <cstdio>

int *grp;
inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

inline int find(int x) {
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
    std::unordered_set<int> gs;
    while(true) {
        int n=read();
        if(n==0) return 0;
        int r=read(), a, b, t;
        if(r<=1) {printf("%d\n", n-1-r);continue;}
        gs.clear();
        grp = new int [n+1];
        for(int i=1;i<=n;++i) grp[i]=i;
        while(r--) {
            a=read(),b=read();
            if(a>b) {t=a;a=b;b=t;}
            grp[find(a)]=find(b);
        }
        for(int i=1;i<=n;++i) {
            gs.insert(find(i));
        }
        printf("%d\n", gs.size()-1);
    }
}

#endif //PAT_P1536_HPP
