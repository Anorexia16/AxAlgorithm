//1083 List Grades

#ifndef PAT_1083_HPP
#define PAT_1083_HPP

#include <vector>
#include <iostream>
#include <algorithm>

struct person {
    std::string name, id;
    int grade;
    bool operator<(person const &pr) const {
        return grade<pr.grade;
    }
};

int main() {
    std::vector<person> vec;
    std::string n, d;
    int num, tp, b, e, l, r;
    std::cin>>num;
    vec.reserve(num);
    while(num--) {
        std::cin >> n >> d >> tp;
        vec.emplace_back(person{n, d, tp});
    }
    std::sort(vec.begin(), vec.end());
    std::cin >> l >> r;
    b = std::distance(vec.begin(), std::lower_bound(vec.begin(), vec.end(),
                                                    person{"", "", l}));
    e = std::distance(vec.begin(), std::upper_bound(vec.begin(), vec.end(),
                                                    person{"", "", r}));
    if(b==e) {printf("NONE\n");return 0;}
    for(int i=e-1;i!=b-1;--i) {
        printf("%s %s\n", vec[i].name.data(), vec[i].id.data());
    }
    return 0;
}


#endif //PAT_1083_HPP
