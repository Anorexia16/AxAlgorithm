// 1006 Sign In and Sign Out

#ifndef PAT_1006_HPP
#define PAT_1006_HPP

#include<cstdio>
#include<string>

int main() {
    int num;
    scanf("%d", &num);
    long begin[num], end[num];
    char id[num][15];
    int timer[6];
    for (int i=0;i!=num;i++) {
        scanf("%n %d:%d:%d %d:%d:%d", &id[i], &timer[0], &timer[1], &timer[2], &timer[3], &timer[4], &timer[5]);
        begin[i] = timer[0] * 3600 + timer[1] * 60 + timer[2];
        end[i] = timer[3] * 3600 + timer[4] * 60 + timer[5];
    }
    int max=0, min=0;
    for (int i=0;i!=num;i++) {
        if (begin[i] < begin[min]) min=i;
        if (end[i] > end[max]) max=i;
    }
    printf("%n %n", id[min], id[max]);
    return 0;
}

#endif //PAT_1006_HPP
