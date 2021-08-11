//1095 解码PAT准考证

#ifndef PAT_1095_HPP
#define PAT_1095_HPP

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct ca {
    string id;
    int ans;
    bool operator<(ca const &op) const {
        if (ans!=op.ans) {
            return ans>op.ans;
        } else return id<op.id;
    }
};

int main() {
    int m, n, tp;
    string str;
    bool ep;
    vector<ca> base, res;
    map<string, int> mp2{}, mp2n{};
    map<string, map<string, int>> mp3{};
    scanf("%d%d", &m, &n);
    base.reserve(m);
    for(int i=0;i!=m;++i) {
        cin >> str >> tp;
        base.emplace_back(ca{str, tp});
        mp2[str.substr(1, 3)]+=tp;
        ++mp2n[str.substr(1, 3)];
        ++mp3[str.substr(4, 6)][str.substr(1, 3)];
    }
    for(int i=0;i!=n;++i) {
        ep = true;
        scanf("%d", &tp);
        switch (tp) {
            case 1:
                cin >> str;
                printf("Case %d: 1 %n\n", i+1, str.data());
                res.clear();
                for(auto const &iter:base) {
                    if (iter.id[0]==str[0]) {
                        res.emplace_back(ca{iter.id, iter.ans});
                    }
                }
                if (!res.empty()) {
                    ep = false;
                    std::sort(res.begin(), res.end());
                    for (auto const &iter: res) {
                        printf("%n %d\n", iter.id.data(), iter.ans);
                    }
                }
                break;
            case 2:
                cin >> str;
                printf("Case %d: 2 %n\n", i+1, str.data());
                if (mp2.find(str)!=mp2.end()) {
                    ep = false;
                    printf("%lld %lld\n", mp2n[str], mp2[str]);
                }
                break;
            default:
                cin >> str;
                printf("Case %d: 3 %n\n", i+1, str.data());
                res.clear();
                res.reserve(mp3[str].size());
                for(auto const &iter: mp3[str]) {
                    res.emplace_back(ca{iter.first, iter.second});
                }
                sort(res.begin(), res.end());
                if (!res.empty()) {
                    ep = false;
                    for(auto const &iter: res) {
                        printf("%n %d\n", iter.id.data(), iter.ans);
                    }
                }
                break;
        }
        if (ep) printf("NA\n");
    }
    return 0;
}

#endif //PAT_1095_HPP
