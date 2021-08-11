//1083 是否存在相等的差

#ifndef PAT_1083_HPP
#define PAT_1083_HPP

#include <cstdio>
#include <map>

inline int ab(int const &a) {return a>0?a:-a;}

int main() {
    int n, tp;
    std::map<int, int> map{};
    scanf("%d", &n);
    for(int i=0;i!=n;++i) {
        scanf("%d", &tp);
        ++map[ab(tp-i-1)];
    }
    for (auto iter=map.rbegin();iter!=map.rend();++iter) {
        if (iter->second>1) {
            printf("%d %d\n", iter->first, iter->second);
        }
    }
    return 0;
}

#endif //PAT_1083_HPP
