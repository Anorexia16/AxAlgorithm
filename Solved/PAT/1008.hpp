// 1008 Elevator

#ifndef PAT_1008_HPP
#define PAT_1008_HPP

#include <cstdio>
int main() {
    int num, sum = 0;
    scanf("%d", &num);
    if (num == 0) {
        printf("0");
    }
    int floor[num];
    for (int i =0; i!= num;i++) scanf("%d", &floor[i]);
    for (int i= 0; i < num-1; i++) {
        if (floor[i+1] < floor[i]) sum += 4 * (floor[i] - floor[i+1]);
        else if (floor[i+1] > floor[i]) sum += 6*(floor[i+1] - floor[i]);
    }
    sum += 5 * num;
    sum += 6 * floor[0];
    printf("%d", sum);
}

#endif //PAT_1008_HPP
