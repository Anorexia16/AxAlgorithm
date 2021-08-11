/*
P2835 刻录光盘
题目描述:
        在JSOI2005夏令营快要结束的时候，很多营员提出来要把整个夏令营期间的资料刻录成
    一张光盘给大家，以便大家回去后继续学习。组委会觉得这个主意不错！可是组委会一时没有
    足够的空光盘，没法保证每个人都能拿到刻录上资料的光盘，又来不及去买了，怎么办呢？！
        组委会把这个难题交给了LHC，LHC分析了一下所有营员的地域关系，发现有些营员是一个
    城市的，其实他们只需要一张就可以了，因为一个人拿到光盘后，其他人可以带着U盘之类的
    东西去拷贝啊！
        可是，LHC调查后发现，由于种种原因，有些营员并不是那么的合作，他们愿意某一些人
    到他那儿拷贝资料，当然也可能不愿意让另外一些人到他那儿拷贝资料，这与我们JSOI宣扬的
    团队合作精神格格不入！！！
        现在假设总共有N个营员（2<=N<=200），每个营员的编号为1~N。LHC给每个人发了一张
    调查表，让每个营员填上自己愿意让哪些人到他那儿拷贝资料。当然，如果A愿意把资料拷贝给
    B，而B又愿意把资料拷贝给C，则一旦A获得了资料，则B，C都会获得资料。
        现在，请你编写一个程序，根据回收上来的调查表，帮助LHC计算出组委会至少要刻录多少
    张光盘，才能保证所有营员回去后都能得到夏令营资料？
输入格式:
        先是一个数N，接下来的N行，分别表示各个营员愿意把自己获得的资料拷贝给其他哪些
    营员。即输入数据的第i+1行表示第i个营员愿意把资料拷贝给那些营员的编号，以一个0结束。
    如果一个营员不愿意拷贝资料给任何人，则相应的行只有1个0，一行中的若干数之间用一个
    空格隔开。
输出格式:
        一个正整数，表示最少要刻录的光盘数。
难度: 普及+/提高
历史分数--100
*/

#ifndef PAT_P2835_HPP
#define PAT_P2835_HPP

#include <cstdio>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int *grp; bool *trv;
inline int find(int x) {
    int r=x, tp;
    while(grp[r]!=r) r=grp[r];
    while(r!=x) {tp=x;x=grp[x];grp[tp]=r;}
    return r;
}

int main() {
    int n=read(), e, ans{};
    grp = new int[n+1];
    trv = new bool [n+1]{};
    for(int i=1;i<=n;++i) grp[i]=i;
    for(int i=1;i<=n;++i) {
        while((e=read())!=0) {
            trv[e]=true;
            e=find(e);
            if(e!=find(i)) grp[e]=find(i);
        }
    }
    for(int i=1;i<=n;++i) {
        if(grp[i]==i||!trv[i]) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}

#endif //PAT_P2835_HPP
