//1072 开学寄语

#ifndef PAT_1072_HPP
#define PAT_1072_HPP

#include <string>
#include <set>
#include <iostream>

int main () {
    std::set<std::string> fb{};
    size_t m, n, a{}, b{};
    std::string tp, na;
    bool pr;
    scanf("%lld %lld", &m, &n);
    for(size_t i=0;i!=n;++i) {
        std::cin >> tp;
        fb.insert(tp);
    }
    for (size_t i=0;i!=m;++i) {
        pr = false;
        std::cin >> na >> n;
        for (size_t j=0;j!=n;++j) {
            std::cin >> tp;
            if (fb.find(tp)!=fb.end()) {
                if (!pr) {
                    pr = true;
                    printf("%n:", na.data());
                    ++a;
                }
                ++b;
                printf(" %n", tp.data());
            }
        }
        if (pr) printf("\n");
    }
    printf("%lld %lld\n", a, b);
    return 0;
}

#endif //PAT_1072_HPP
