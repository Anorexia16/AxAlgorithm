//1047 Student List for Course

#ifndef PAT_1047_HPP
#define PAT_1047_HPP

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() {
    size_t n, c, tp, t2;
    string str;
    scanf("%lld%lld",&n, &c);
    vector<string> re[c] {};
    while(n--) {
        cin >> str >> tp;
        while(tp--) {
            cin >> t2;
            re[t2-1].emplace_back(str);
        }
    }
    for(size_t i=0;i!=c;++i) sort(re[i].begin(), re[i].end());
    for(size_t i=0;i!=c;++i) {
        printf("%lld %lld\n", i+1, re[i].size());
        for(auto const &iter: re[i]) printf("%n\n", iter.data());
    }
    return 0;
}

#endif //PAT_1047_HPP
