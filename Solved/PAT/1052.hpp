//1052 Linked List Sorting

#ifndef PAT_1052_HPP
#define PAT_1052_HPP

#include <cstdio>
#include <algorithm>
#include <unordered_map>

struct node {
    ssize_t adr, value, to;
    bool operator<(node const &op) const {return value<op.value;}
};

inline ssize_t read() {
    ssize_t x{}, c=getchar(), neg{};
    while((c>'9'||c<'0')&&c!='-') c=getchar();
    if (c=='-') {neg=1;c=getchar();}
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return neg?-x:x;
}

int main() {
    ssize_t n=read(), b=read(), f, v, t, q{};
    std::unordered_map<ssize_t, node> mp {};
    node arr[n];
    for(int i=0;i!=n;++i) {
        f=read(), v=read(), t=read();
        mp[f] = node{f, v, t};
    }
    while(b!=-1) {
        arr[q++] = mp[b];
        b = arr[q-1].to;
    }
    if(q==0) {
        printf("0 -1\n");
        return 0;
    }
    std::sort(arr, arr+q);
    printf("%lld %05lld\n", q, arr[0].adr);
    for(size_t i=0;i!=q-1;++i) {
        printf("%05lld %lld %05lld\n",
               arr[i].adr, arr[i].value, arr[i+1].adr);
    }
    printf("%05lld %lld -1\n", arr[q-1].adr, arr[q-1].value);
    return 0;
}

#endif //PAT_1052_HPP
