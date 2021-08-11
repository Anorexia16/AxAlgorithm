// 1041 Be Unique

#ifndef PAT_1041_HPP
#define PAT_1041_HPP

#include <unordered_map>
#include <cstdio>

inline int read() {
    int x{}, c=getchar();
    while (c>'9'||c<'0') c=getchar();
    while (c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}


int main() {
    std::unordered_map<int, int> ti;
    int n=read(), arr[n];
    for(int i=0;i!=n;++i) arr[i]=read(), ++ti[arr[i]];
    for(int i=0;i!=n;++i) {
        if(ti[arr[i]]==1) {
            printf("%d\n", arr[i]);
            return 0;
        }
    }
    printf("None\n");
    return 0;
}

#endif //PAT_1041_HPP
