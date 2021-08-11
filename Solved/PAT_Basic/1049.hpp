//1049 数列的片段和

#ifndef PAT_1049_HPP
#define PAT_1049_HPP

#include <cstdio>

int main(){
    int i;
    int N;
    scanf("%d",&N);
    long double sum=0,tmp;
    for(i=0;i<N;i++){
        scanf("%llf",&tmp);
        sum+=tmp*(N-i)*(i+1);
    }
    printf("%.2Lf\n",sum);
    return 0;
}


#endif //PAT_1049_HPP
