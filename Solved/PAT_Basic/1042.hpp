//1042 字符统计

#ifndef PAT_1042_HPP
#define PAT_1042_HPP

#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct cc{
    char c;
    int count{};
    bool operator<(cc const &op) const {
        if (count!=op.count) return count > op.count;
        else return c<op.c;
    }
};

int main() {
    map<char, int> count;
    vector<cc> vc;
    string str;
    getline(cin, str);
    for(auto const &iter:str) {
        if('a'<=iter&&iter<='z') ++count[iter];
        else if ('A'<=iter&&iter<='Z') ++count[iter-'A'+'a'];
    };
    vc.reserve(count.size());
    for(auto const &iter:count) vc.emplace_back(cc{iter.first, iter.second});
    std::sort(vc.begin(), vc.end());
    printf("%c %d\n", vc.front().c, vc.front().count);
    return 0;
}

#endif //PAT_1042_HPP
