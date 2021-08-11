//1085 PAT单位排行

#ifndef PAT_1085_HPP
#define PAT_1085_HPP

#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

struct school {
    double point;
    int num;
    std::string name;
    bool operator<(school const &op) const {
        return int(point)>(int)(op.point)||
               (int(point)==(int)(op.point)&&num<op.num)||
               (int(point)==(int)(op.point)&&(num==op.num)&&name<op.name);
    }
};


int main() {
    std::map<std::string, school> scs{};
    std::vector<school> cont{};
    std::string id, tp;
    int n;
    double v;
    scanf("%d", &n);
    for(size_t i=0;i!=n;++i) {
        std::cin >> id >> v >> tp;
        for (int j=0;j!=tp.size();++j) {
            if ('A'<=tp[j]&&'Z'>=tp[j]) tp[j] = tp[j]-'A'+'a';
        }
        scs[tp].name = tp;
        if (id[0]=='B') {
            scs[tp].point += v / 1.5;
        } else if (id[0]=='A') {
            scs[tp].point += v;
        } else {
            scs[tp].point += 1.5 * v;
        }
        ++scs[tp].num;
    }
    cont.reserve(scs.size());
    for(auto const &iter:scs) {
        cont.emplace_back(iter.second);
    }
    std::sort(cont.begin(), cont.end());
    printf("%lld\n", cont.size());
    int rank{}, sc=-1, mem{};
    for(auto const &iter:cont) {
        if (sc==(int)iter.point) {
            ++mem;
        } else {
            rank += 1+mem;
            sc = (int)iter.point;
            mem = 0;
        }
        printf("%d %n %d %lld\n", rank, iter.name.data(), (int)iter.point, iter.num);
    }
    return 0;
}

#endif //PAT_1085_HPP
