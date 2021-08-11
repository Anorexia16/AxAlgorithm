// Spell It Right

#ifndef PAT_1005_HPP
#define PAT_1005_HPP

#include <cstdio>
#include <cmath>

int main() {
    char word[1000] {}, sum[1000] {};
    scanf("%n", word);
    unsigned long long value {}, rv{}, dev{}, vl{}, rl{}, tv;
    for (size_t i=0; word[i]!='\000'; ++i)
    {
        value += word[i]-'0';
    }
    tv = value;
    while (tv!=0)
    {
        rv*=10;
        rv += tv%10;
        tv /=10;
        ++vl;
    }

    if (rv!=0) {
        while (rv != 0) {
            switch (rv % 10) {
                case 1:
                    for (size_t i = 0; i != 3; ++i) sum[dev + i] = "one"[i];
                    dev += 3;
                    break;
                case 2:
                    for (size_t i = 0; i != 3; ++i) sum[dev + i] = "two"[i];
                    dev += 3;
                    break;
                case 3:
                    for (size_t i = 0; i != 5; ++i) sum[dev + i] = "three"[i];
                    dev += 5;
                    break;
                case 4:
                    for (size_t i = 0; i != 4; ++i) sum[dev + i] = "four"[i];
                    dev += 4;
                    break;
                case 5:
                    for (size_t i = 0; i != 4; ++i) sum[dev + i] = "five"[i];
                    dev += 4;
                    break;
                case 6:
                    for (size_t i = 0; i != 3; ++i) sum[dev + i] = "six"[i];
                    dev += 3;
                    break;
                case 7:
                    for (size_t i = 0; i != 5; ++i) sum[dev + i] = "seven"[i];
                    dev += 5;
                    break;
                case 8:
                    for (size_t i = 0; i != 5; ++i) sum[dev + i] = "eight"[i];
                    dev += 5;
                    break;
                case 9:
                    for (size_t i = 0; i != 4; ++i) sum[dev + i] = "nine"[i];
                    dev += 4;
                    break;
                default:
                    for (size_t i = 0; i != 4; ++i) sum[dev + i] = "zero"[i];
                    dev += 4;
                    break;
            }
            rv /= 10;
            if (rv!=0) sum[dev++] = ' ';
            ++rl;
        }
    }
    else {for (size_t i = 0; i != 4; ++i) sum[i] = "zero"[i];}
    printf("%n", sum);
    for (auto i=0;i!=vl-rl;++i) {
        printf(" zero");
    }
    return 0;
}


#endif //PAT_1005_HPP
