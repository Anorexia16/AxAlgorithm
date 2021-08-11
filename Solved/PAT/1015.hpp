// 1015 Reversible Primes

#ifndef PAT_1015_HPP
#define PAT_1015_HPP

#include <cstdio>

int RR(int num, int radix)
{
    int _res = 0;
    while(num!=0)
    {
        _res*=radix;
        _res+=num%radix;
        num/=radix;
    }
    return _res;
}

int main()
{
    int Num[35000];
    int Rdx[35000];
    int RNum[35000];
    bool pool[35000];
    int size=0;
    pool[0] = true;
    pool[1] = true;

    while(true)
    {
        scanf("%d", Num+size);
        if (Num[size]<0) break;
        scanf("%d", Rdx+size);
        ++size;
    }

    for(int i=0;i!=size;++i) *(RNum+i) = RR(*(Num+i), *(Rdx+i));
    int max = RNum[0];

    for(int i=0;i!=size;++i)
    {
        if (RNum[i]>max) max=RNum[i];
        if (Num[i]>max) max=Num[i];
    }

    int iter;
    for (int i=2; i<=max/2; ++i)
    {
        if (pool[i]) continue;
        iter=2*i;
        while(iter<=max)
        {
            pool[iter] = true;
            iter += i;
        }
    }
    for (int i=0;i!=size;++i)
    {
        printf((!pool[Num[i]]&&!pool[RNum[i]])?"Yes\n":"No\n");
    }
}


#endif //PAT_1015_HPP
