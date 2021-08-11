//1061 判断题

#ifndef PAT_1061_HPP
#define PAT_1061_HPP

#include <cstdio>

int main() {
    int m, n, tp, s;
    scanf("%d %d", &m, &n);
    int sc[n], ri[n];
    for(int i=0;i!=n;++i) scanf("%d", sc+i);
    for(int i=0;i!=n;++i) scanf("%d", ri+i);
    for(int i=0;i!=m;++i) {
        s = 0;
        for (int j=0;j!=n;++j) {
            scanf("%d", &tp);
            if (tp==ri[j]) s+= sc[j];
        }
        printf("%d\n", s);
    }
    return 0;
}

#endif //PAT_1061_HPP
