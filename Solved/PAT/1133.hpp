//1133 Splitting A Linked List

#ifndef PAT_1133_HPP
#define PAT_1133_HPP

#include <cstdio>
#include <unordered_map>

inline int read() {
    int x{}, c=getchar(), neg{};
    while((c>'9'||c<'0')&&c!='-') c=getchar();
    if(c=='-') {++neg;c=getchar();}
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return neg?-x:x;
}

struct node {
    int add, value, next;
};

int main() {
    int i=read(), n=read(), k=read(), f, v, t, ai{}, bi{}, ci{};
    std::unordered_map<int, node> mp{};
    node a[n], b[n], c[n];
    while(n--) {
        f=read(), v=read(), t=read();
        mp[f] = node{f, v, t};
    }
    while(i!=-1) {
        v=mp[i].value;
        if(v<0) {
            a[ai++]=mp[i];
        } else if (v>k) {
            c[ci++]=mp[i];
        } else {
            b[bi++]=mp[i];
        }
        i=mp[i].next;
    }
    for(int j=0;j<ai-1;++j) {
        printf("%05d %d %05d\n", a[j].add, a[j].value, a[j+1].add);
    }
    if(ai!=0) {
        if(bi!=0) {
            printf("%05d %d %05d\n", a[ai-1].add, a[ai-1].value, b[0].add);
        } else if(ci!=0) {
            printf("%05d %d %05d\n", a[ai-1].add, a[ai-1].value, c[0].add);
        } else {
            printf("%05d %d -1\n", a[ai-1].add, a[ai-1].value);
        }
    }
    for(int j=0;j<bi-1;++j) {
        printf("%05d %d %05d\n", b[j].add, b[j].value, b[j+1].add);
    }
    if(bi!=0) {
        if(ci!=0) {
            printf("%05d %d %05d\n", b[bi-1].add, b[bi-1].value, c[0].add);
        } else {
            printf("%05d %d -1\n", b[bi-1].add, b[bi-1].value);
        }
    }
    for(int j=0;j<ci-1;++j) {
        printf("%05d %d %05d\n", c[j].add, c[j].value, c[j+1].add);
    }
    if(ci!=0) {
        printf("%05d %d -1\n", c[ci-1].add, c[ci-1].value);
    }
    return 0;
}

#endif //PAT_1133_HPP
