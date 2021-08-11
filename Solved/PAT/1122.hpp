//1122 Hamiltonian Cycle

#ifndef PAT_1122_HPP
#define PAT_1122_HPP

#include <cstdio>
#include <unordered_set>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    int v=read(), e=read(), a, b, n, aa;
    std::unordered_set<int> g[v+1], ans;
    bool flag;
    while(e--) {
        a=read(), b=read();
        g[a].insert(b);
        g[b].insert(a);
    }
    e=read();
    while(e--) {
        n=read();
        if(n==0) continue;
        a=read(), flag= true, ans.clear(), aa=a;
        for(int i=1;i<n;++i) {
            b=read();
            if(!flag) continue;
            if(g[a].find(b)==g[a].end()) {
                flag= false;
            }
            if(ans.find(b)==ans.end())ans.insert(b);
            else flag= false;
            a = b;
        }
        if(flag) flag=aa==a;
        if(ans.size()==v&&flag) printf("YES\n");
        else printf("NO\n");
    }
}


#endif //PAT_1122_HPP
