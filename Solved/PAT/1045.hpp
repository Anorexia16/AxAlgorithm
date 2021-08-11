//1045 Favorite Color Stripe

#ifndef PAT_1045_HPP
#define PAT_1045_HPP

#include <unordered_map>
#include <cstdio>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

inline void write(int x) {
    if(x/10!=0) write(x/10);
    putchar(x%10+'0');
}
int id[10000], mp[201]{}, arr[10000];

int main() {
    read();
    int n=read(), m, s{}, tp, ans=0;
    for(int i=0;i!=n;++i) mp[read()] = i+1;
    m=read();
    for(int i=0;i<m;++i) {
        tp=read();
        if(mp[tp]!=0) arr[s++] = mp[tp];
    }
    for(int i=0;i<s;++i) {
        id[i] = 1;
        for(int j=0;j<i;++j) {
            if(arr[i]>=arr[j]&&id[j]+1>id[i]) {
                id[i]=id[j]+1;
            }
        }
        ans=ans>id[i]?ans:id[i];
    }
    write(ans);
    putchar('\n');
    return 0;
}

#endif //PAT_1045_HPP
