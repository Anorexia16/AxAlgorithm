//1071 Speech Patterns

#ifndef PAT_1071_HPP
#define PAT_1071_HPP

#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct wd {
    string s; int ti;
    bool operator<(wd const &op) const {
        return ti!=op.ti?ti>op.ti:s<op.s;
    }
};

int ia(char const &c) {
    if(c>='A'&&c<='Z') return 1;
    if((c>='a'&&c<='z')||(c>='0'&&c<='9')) return 2;
    return 0;
}

string pure(string str) {
    int s=str.size();
    for(int i=0;i!=s;++i) {
        if(ia(str[i])==1) str[i]+='a'-'A';
    }
    return str;
}

int main() {
    unordered_map<string, int> mp;
    vector<wd> vec;
    string str; int bi=0, ei=0, s;
    getline(cin, str); s=str.size();
    for(;ei!=s;++ei) {
        if(!ia(str[ei])) {
            if(bi!=ei) {
                ++mp[pure(str.substr(bi, ei-bi))];
            }
            bi=ei+1;
        }
    }
    if(bi!=ei) {
        ++mp[pure(str.substr(bi))];
    }
    vec.reserve(mp.size());
    for(auto const &iter:mp) {
        vec.emplace_back(wd{iter.first, iter.second});
    }
    sort(vec.begin(), vec.end());
    printf("%n %d\n", vec.front().s.data(), vec.front().ti);
    return 0;
}

#endif //PAT_1071_HPP
