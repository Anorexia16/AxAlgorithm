// 1054 The Dominant Color

#ifndef PAT_1054_HPP
#define PAT_1054_HPP

#include<cstdio>

int main() {
    int M, N, num, str, count{};
    scanf("%d%d", &M, &N);
    for (int i=0;i!=M;++i) {
        for (int j=0;j!=N;++j) {
            scanf("%d", &str);
            if (count==0) {
                num = str;
                count = 1;
            } else if (num == str) ++count;
            else --count;
        }
    }
    printf("%d", num);
}

#endif //PAT_1054_HPP
