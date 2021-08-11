//1142 Maximal Clique

#ifndef PAT_1142_HPP
#define PAT_1142_HPP

#include <unordered_set>
#include <cstdio>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    int n=read(), e=read(), l, r, fi;
    std::unordered_set<int> g[n+1], rx, rm;
    while(e--) {
        l=read(), r=read();
        g[l].insert(r), g[r].insert(l);
    }
    e=read();
    while(e--) {
        rx.clear(), rm.clear(), l=read(), fi=1;
        while(l--) {
            r=read();
            for(auto const &iter:rx) {
                if(g[iter].find(r)==g[iter].end()) {
                    fi=0;break;
                }
            }
            for(auto const &iter:g[r]) {
                rm.insert(iter);
            }
            rm.insert(r), rx.insert(r);
        }
        if(!fi) printf("Not a Clique\n");
        else {
            for(auto const &iter:rx) {
                rm.erase(rm.find(iter));
            }
            l=0;
            for(auto const &iter:rm) {
                l=1;
                for(auto const &iter2:rx) {
                    if(g[iter2].find(iter)==g[iter2].end()) {
                        l=0;break;
                    }
                }
                if(l==1) break;
            }
            l==0?printf("Yes\n"):printf("Not Maximal\n");
        }
    }
}

#endif //PAT_1142_HPP
