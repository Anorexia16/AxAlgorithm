//1039 Course List for Student

#ifndef PAT_1039_HPP
#define PAT_1039_HPP

#include<unordered_map>
#include<set>
#include<iostream>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    std::unordered_map<std::string, std::set<int>> mp;
    int n=read(), m=read(), idx, tp;
    std::string str;
    while(m--) {
        idx=read(), tp=read();
        while(tp--) {
            std::cin>>str;
            mp[str].insert(idx);
        }
    }
    while(n--) {
        std::cin>>str;
        printf("%s %d", str.data(), mp[str].size());
        for(auto const &iter:mp[str]) {
            printf(" %d", iter);
        }
        putchar('\n');
    }
}

#endif //PAT_1039_HPP
