//1028 List Sorting

#ifndef PAT_1028_HPP
#define PAT_1028_HPP

#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct item {
    string id, name;
    int score;
};

bool c1(item const &a, item const &b) {
    return a.id<b.id;
}

bool c2(item const &a, item const &b) {
    return a.name!=b.name?a.name<b.name:a.id<b.id;
}

bool c3(item const &a, item const &b) {
    return a.score!=b.score?a.score<b.score:a.id<b.id;
}

int main() {
    size_t m, n;
    scanf("%lld %lld", &m, &n);
    item ex[m];
    for(size_t i=0;i!=m;++i) {
        cin>>ex[i].id>>ex[i].name>>ex[i].score;
    }
    switch (n) {
        case 1:
            sort(ex, ex+m, c1);
            break;
        case 2:
            sort(ex, ex+m, c2);
            break;
        default:
            sort(ex, ex+m, c3);
            break;
    }
    for(size_t i=0;i!=m;++i) {
        printf("%n %n %d\n", ex[i].id.data(),
               ex[i].name.data(), ex[i].score);
    }
    return 0;
}


#endif //PAT_1028_HPP
