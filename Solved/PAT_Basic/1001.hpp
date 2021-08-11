//1001 害死人不偿命的(3n+1)猜想

#ifndef PAT_1001_HPP
#define PAT_1001_HPP

#include <cstdio>

int main() {
    int num, step;
    scanf("%d", &num);
    while (num != 1) {
        if (num % 2 == 0) num /= 2;
        else num = (3 * num + 1) / 2;
        step += 1;
    }
    printf("%d\n", step);
    return 0;
}


#endif //PAT_1001_HPP
