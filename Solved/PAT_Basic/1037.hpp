//1037 在霍格沃茨找零钱

#ifndef PAT_1037_HPP
#define PAT_1037_HPP

#include <cstdio>

int main() {
    ssize_t s;
    int a1, a2, a3, b1, b2, b3;
    bool rf{};
    scanf("%d.%d.%d %d.%d.%d",
          &a1, &a2, &a3, &b1, &b2, &b3);
    s = 17*29*a1+29*a2+a3 - (17*29*b1+29*b2+b3);
    if (s>0) {
        printf("-");
    } else {
        s = -s;
    }
    printf("%d.%d.%d\n", s/(17*29), (s/29)%17, s%29);
    return 0;
}

#endif //PAT_1037_HPP
