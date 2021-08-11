// 1062 Talent and Virtue

#ifndef PAT_1062_HPP
#define PAT_1062_HPP

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

size_t pass, good;

using namespace std;
struct person {
    string id;
    size_t vg{}, tg{};
};

bool cmp (person const &a, person const&b) {
    if (a.vg+a.tg!=b.vg+b.tg) {
        return a.vg + a.tg > b.vg + b.tg;
    } else if (a.vg != b.vg) {
        return a.vg > b.vg;
    }else {
        return a.id < b.id;
    }

}

int main() {
    std::vector<person> sage, nobe, fool, sml;
    size_t N, v, t;
    string tp;
    std::cin >> N >> pass >> good;
    for (size_t i=0;i!=N;++i) {
        cin >> tp >>v >> t;
        if (v<pass || t< pass) continue;
        if (v>=good&&t>=good) {
            sage.emplace_back(person {tp, v, t});
        } else if (v>=good && t< good) {
            nobe.emplace_back(person{tp, v, t});
        } else if (v < good && t < good && v>=t) {
            fool.emplace_back(person {tp, v, t});
        } else {
            sml.emplace_back(person {tp, v, t});
        }
    }
    std::sort(sage.begin(), sage.end(), cmp);
    std::sort(nobe.begin(), nobe.end(), cmp);
    std::sort(fool.begin(), fool.end(), cmp);
    std::sort(sml.begin(), sml.end(), cmp);
    cout << sage.size()+nobe.size()+fool.size()+sml.size() << endl;
    for (auto const &iter:sage) {
        cout << iter.id << " " <<iter.vg << " "<<iter.tg << endl;
    }
    for (auto const &iter: nobe) {
        cout << iter.id << " " << iter.vg <<" "<< iter.tg << endl;
    }
    for (auto const &iter: fool) {
        cout << iter.id << " " << iter.vg << " " << iter.tg << endl;
    }
    for (auto const &iter: sml) {
        cout << iter.id << " " << iter.vg << " " << iter.tg << endl;
    }
    return 0;
}

#endif //PAT_1062_HPP
