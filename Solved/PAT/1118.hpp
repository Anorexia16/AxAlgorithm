//1118 Birds in Forest

#ifndef PAT_1118_HPP
#define PAT_1118_HPP

#include <cstdio>

constexpr int max=100000;
int grp[max], exist[max]{}, si[max]{};

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

inline int find(int x) {
    int r=x, tp;
    while(r!=grp[r]) r=grp[r];
    while(x != grp[x]) {
        tp=x;
        x=grp[x];
        grp[tp]=r;
    }
    return r;
}

inline void unit(int a, int b) {
    grp[find(a)]=find(b);
}

int main() {
    int n=read(), tp, fp, tn, br{}, s{};
    for(int i=0;i<=max;++i) grp[i]=i;
    while(n--) {
        tp=read()-1;
        fp=read(), ++exist[fp];
        while(tp--) {
            tn=read();++exist[tn];
            unit(fp, tn);
        }
    }
    for(int i=0;i!=max;++i) {
        if(exist[i]) {++si[find(i)];++br;}
    }
    for(int i=0;i!=max;++i) if(exist[i] && si[i]) ++s;
    printf("%d %d\n", s, br);
    n = read();
    while(n--) {
        tp=read(), tn=read();
        find(tp)==find(tn)?
        printf("Yes\n"):printf("No\n");
    }
    return 0;
}

#endif //PAT_1118_HPP
