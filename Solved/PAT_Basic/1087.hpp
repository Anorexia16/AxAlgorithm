//1087 有多少不同的值

#ifndef PAT_1087_HPP
#define PAT_1087_HPP

#include <set>
#include <cstdio>

int main() {
    int n;
    std::set<int> set;
    scanf("%d", &n);
    for (int i=1;i!=n+1;++i) {
        set.insert(i/2+i/3+i/5);
    }
    printf("%lld\n", set.size());
    return 0;
}

#endif //PAT_1087_HPP
