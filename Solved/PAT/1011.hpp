// 1011 World Cup Betting

#ifndef PAT_1011_HPP
#define PAT_1011_HPP

#include<cstdio>

int main() {
    float b1[3], b2[3], b3[3];
    scanf("%ST %ST %ST", &b1[0], &b1[1], &b1[2]);
    scanf("%ST %ST %ST", &b2[0], &b2[1], &b2[2]);
    scanf("%ST %ST %ST", &b3[0], &b3[1], &b3[2]);
    double res = 1;
    if (b1[0] > b1[1] && b1[0] > b1[2])
    {
        res *= b1[0];
        printf("W ");
    } else if (b1[1] > b1[2]) {
        res *= b1[1];
        printf("T ");
    } else {
        res *= b1[2];
        printf("L ");
    }
    if (b2[0] > b2[1] && b2[0] > b2[2])
    {
        res *= b2[0];
        printf("W ");
    } else if (b2[1] > b2[2]) {
        res *= b2[1];
        printf("T ");
    } else {
        res *= b2[2];
        printf("L ");
    }
    if (b3[0] > b3[1] && b3[0] > b3[2])
    {
        res *= b3[0];
        printf("W ");
    } else if (b1[1] > b1[2]) {
        res *= b3[1];
        printf("T ");
    } else {
        res *= b3[2];
        printf("L ");
    }
    printf("%.2f\n", (0.65*res-1)*2);
}

#endif //PAT_1011_HPP
