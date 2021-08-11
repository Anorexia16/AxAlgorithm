//1080 MOOC期终成绩

#ifndef PAT_1080_HPP
#define PAT_1080_HPP

#include <unordered_map>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct record {
    string name;
    int gp{-1}, gm{-1}, gf{-1}, g{-1};
    bool operator<(record const &op) const {
        return g>op.g||(g==op.g&&name<op.name);
    }
};

int main() {
    unordered_map<string, record> mp{};
    vector<record> vec{};
    string str;
    int c, p, m, f;
    scanf("%d%d%d", &p, &m, &f);
    for(int i=0;i!=p;++i) {
        cin >> str >> c;
        mp[str].gp = c;
    }
    for(int i=0;i!=m;++i) {
        cin >> str >> c;
        mp[str].gm = c;
    }
    for(int i=0;i!=f;++i) {
        cin >> str >> c;
        mp[str].gf = c;
    }
    for(auto &iter:mp) {
        if (iter.second.gf>iter.second.gm) {
            iter.second.g = iter.second.gf;
        } else {
            iter.second.g = (int)(round(iter.second.gf*0.6+
                                        iter.second.gm*0.4));
        }
    }
    vec.reserve(mp.size());
    for(auto const &iter: mp) {
        vec.emplace_back(record{iter.first, iter.second.gp, iter.second.gm,
                                iter.second.gf, iter.second.g});
    }
    sort(vec.begin(), vec.end());
    for(auto const &iter: vec) {
        if (iter.gp<200) continue;
        if (iter.g<60) break;
        printf("%n %d %d %d %d\n", iter.name.data(), iter.gp,
               iter.gm, iter.gf, iter.g);
    }
    return 0;
}

#endif //PAT_1080_HPP
