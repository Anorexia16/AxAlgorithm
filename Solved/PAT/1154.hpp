//1154 Vertex Coloring

#ifndef PAT_1154_HPP
#define PAT_1154_HPP

#include <unordered_set>
#include <cstdio>

inline void read(int &x) {
    x=0; int c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
}

int main() {
    int v, e, a, b;
    read(v), read(e);
    std::unordered_set<int> gr[v], num;
    int cl[v], tp; bool fg;
    while(e--) {
        read(a), read(b);
        gr[a].insert(b);
        gr[b].insert(a);
    }

    read(e);
    while(e--) {
        num.clear(); fg = true;
        for(int i=0;i!=v;++i) {read(cl[i]);num.insert(cl[i]);}
        for(int i=0;i!=v;++i) {
            tp=cl[i];
            for(auto const &iter:gr[i]) {
                if(cl[iter]==tp) {
                    fg = false; break;
                }
            }
            if(!fg) break;
        }
        if(fg) printf("%d-coloring\n", num.size());
        else printf("No\n");
    }

    return 0;
}

#endif //PAT_1154_HPP
