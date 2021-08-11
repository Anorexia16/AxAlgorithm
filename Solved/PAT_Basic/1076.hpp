//1076 Wifi密码

#ifndef PAT_1076_HPP
#define PAT_1076_HPP

#include <cstdio>

int main() {
    int m;
    char a, b;
    scanf("%d", &m);
    for(int i=0;i!=m;++i) {
        scanf("\n");
        for(int j=0;j!=4;++j) {
            if (j!=0) scanf(" ");
            scanf("%c-%c", &a, &b);
            if (b=='T') {
                printf("%d", a-'A'+1);
            }
        }
    }
    printf("\n");
    return 0;
}

#endif //PAT_1076_HPP
