//1082 射击比赛

#ifndef PAT_1082_HPP
#define PAT_1082_HPP

#include <algorithm>
#include <cstdio>

struct man {
    ssize_t id{};
    ssize_t dev{};
};

bool cmp(man const &a, man const &b) {
    return a.dev<b.dev;
}

int main () {
    man data[10000]{};
    ssize_t x, y, id, n;
    scanf("%lld", &n);
    for(size_t i=0;i!=n;++i) {
        scanf("%lld%lld%lld", &id, &x, &y);
        data[i] = man{id, x*x+y*y};
    }
    std::sort(data, data+n, cmp);
    printf("%04lld %04lld\n", data[0].id, data[n-1].id);
    return 0;
}

#endif //PAT_1082_HPP
