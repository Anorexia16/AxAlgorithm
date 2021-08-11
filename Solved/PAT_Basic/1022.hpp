//1022 D进制的A+B

#ifndef PAT_1022_HPP
#define PAT_1022_HPP

#include<cstdio>

int main()
{
    double A, B, C;
    int i, D;
    char ch[32];

    scanf("%lf%lf%d", &A, &B, &D);
    C = A + B;
    if (C < 1)
    {
        printf("0");
    }
    for (i = 0; C >= 1; i++)
    {
        ch[i] = '0' + static_cast<int>(C - D * (int)(C / D)) ;
        C = C / D;
    }
    while (i > 0)
    {
        i--;
        printf("%c", ch[i]);
    }
    printf("\n");
    return 0;
}

#endif //PAT_1022_HPP
