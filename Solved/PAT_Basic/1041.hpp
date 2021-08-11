//1041 考试座位号

#ifndef PAT_1041_HPP
#define PAT_1041_HPP

#include<iostream>
#include<map>
#include<string>

struct person {
    std::string id;
    size_t num;
};

int main() {
    std::map<size_t, person> map;
    std::string temp;
    size_t m, n, tp;
    std::cin >> m;
    for(size_t i=0;i!=m;++i) {
        std::cin >> temp >> n >> tp;
        map[n] = person{temp, tp};
    }
    std::cin >> n;
    for(size_t i=0;i!=n;++i) {
        std::cin >> tp;
        printf("%n %ld\n", map[tp].id.data(), map[tp].num);
    }
    return 0;
}

#endif //PAT_1041_HPP
