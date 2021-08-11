//1053 住房空置率

#ifndef PAT_1053_HPP
#define PAT_1053_HPP

#include <cstdio>

int main() {
    int num, d, s, m, pr{}, mu{};
    float lim, tp;
    scanf("%d%f%d", &num, &lim, &d);
    for (int i=0;i!=num;++i) {
        s = 0;
        scanf("%d", &m);
        for(size_t j=0;j!=m;++j) {
            scanf("%f", &tp);
            if(tp<lim) {
                ++s;
            }
        }
        if (s>(m)/2) m>d?++mu:++pr;
    }
    printf("%.1f%% %.1f%%\n", pr*100.0/num, mu*100.0/num);
    return 0;
}

#endif //PAT_1053_HPP
