//1047 编程团体赛

#ifndef PAT_1047_HPP
#define PAT_1047_HPP


#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

bool cmp(std::pair<int, int> const &a,
         std::pair<int, int> const &b) {
    return a.second>b.second;
}

int main() {
    std::map<int, int> ma;
    std::vector<std::pair<int, int>> vec {};
    int n, tp, v, va;
    scanf("%d", &n);
    for(int i=0;i!=n;++i) {
        scanf("%d-%d %d", &tp, &v, &va);
        ma[tp] += va;
    }
    vec.reserve(ma.size());
    for(auto const &iter:ma) {
        vec.emplace_back(std::pair<int, int>{iter.first, iter.second});
    }
    std::sort(vec.begin(), vec.end(), cmp);
    printf("%d %d\n",
           vec.front().first,
           vec.front().second);
    return 0;
}

#endif //PAT_1047_HPP
