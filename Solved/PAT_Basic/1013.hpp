//1013 数素数

#ifndef PAT_1013_HPP
#define PAT_1013_HPP

#include<stdio.h>
#include<math.h>

int IsPrime(int b);

int main()
{
    int M, N, a = 0, b = 2, count = 0;
    scanf("%d %d", &M, &N);
    while(a < N){
        if(IsPrime(b)){
            a++;
            if(a >= M){
                printf("%d", b);
                count++;
                if(count % 10 == 0){
                    printf("\n");
                }
                else if(a != N){
                    printf(" ");
                }
            }
        }
        b++;
    }
}

int IsPrime(int b){
    int flag = 1;
    for(int i = 2; i <= sqrt(b); i++){
        if(b % i == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}

#endif //PAT_1013_HPP
