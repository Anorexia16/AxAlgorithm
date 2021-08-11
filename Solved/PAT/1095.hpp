//1095 Cars on Campus

#ifndef PAT_1095_HPP
#define PAT_1095_HPP

#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct record {
    string id;
    int t;
    bool operator<(record const &op) const {
        return t!=op.t?t>op.t:id<op.id;
    }
};

struct sr{
    int t;
    bool ii;
    bool operator<(sr const &op) const {
        return t<op.t;
    }
};

int ti(int const &hh, int const &mm, int const &ss) {
    return 3600*hh+60*mm+ss;
}

int main() {
    unordered_map<string, vector<sr>> rp;
    unordered_map<string, int> mp;
    unordered_set<string> set;
    vector<int> ig, og;
    vector<record> vec;
    int hh, mm, ss, n, q;
    string str, tr;bool sf;
    cin >> n >> q;
    while(n--) {
        cin>>str>>hh;
        getchar(), cin>>mm, getchar(), cin>>ss;
        cin>>tr;
        hh = ti(hh, mm, ss);
        set.insert(str);
        tr=="in"?rp[str].emplace_back(sr{hh, true}):
        rp[str].emplace_back(sr{hh, false});
    }
    for(auto const &iter:set) {
        sf = false; vector<sr> &ir=rp[iter];
        std::sort(ir.begin(), ir.end());
        for(auto const &i:ir) {
            if(i.ii) {
                n=i.t, sf= true;
            } else if ((!i.ii)&&sf) {
                ig.emplace_back(n), og.emplace_back(i.t);
                mp[iter]+=i.t-n, sf= false;
            }
        }
    }
    sort(ig.begin(), ig.end());
    sort(og.begin(), og.end());
    while(q--) {
        cin>>hh, getchar(), cin>>mm, getchar(), cin>>ss;
        ss=ti(hh, mm, ss);
        mm = distance(ig.begin(), upper_bound(ig.begin(), ig.end(), ss));
        hh = distance(og.begin(), upper_bound(og.begin(), og.end(), ss));
        printf("%d\n", mm-hh);
    }

    vec.reserve(mp.size());
    for(auto const &iter:mp) {
        vec.emplace_back(record{iter.first, iter.second});
    }
    sort(vec.begin(), vec.end());
    ss=vec.front().t;

    for(auto const &iter:vec) {
        if(iter.t==ss) {
            printf("%n ", iter.id.data());
        } else break;
    }
    printf("%02d:%02d:%02d\n", ss/3600, (ss/60)%60, ss%60);
    return 0;
}

#endif //PAT_1095_HPP
