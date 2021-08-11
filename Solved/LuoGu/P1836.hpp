/*
P1836 数页码
题目描述:
    一本书的页码是从 1\sim n1∼n 编号的连续整数：1,2,3,...,n。
    请你求出全部页码中所有单个数字的和，例如第123页，它的和就是
    1+2+3=6。
输入格式:
    一行一个整数 n。
输出格式:
    一行，代表所有单个数字的和。
难度: 提高+/省选-
历史分数--100
*/

#ifndef PAT_P1836_HPP
#define PAT_P1836_HPP

#include <cstdio>

size_t zip(size_t n) {
    size_t s{};
    while(n!=0) {
        s+=n%10;
        n/=10;
    }
    return s;
}

int main() {
    size_t num, sum{}, tp, level=0, base1, base2=1, base3{};
    scanf("%lld", &num);
    sum+=num%10;
    base1 = (1+num%10);
    while(num!=0) {
        tp = num%10;
        num /= 10;
        sum+=zip(num)*base1;
        sum+=base2*tp*(tp-1)/2;
        sum+=tp*45*base3;
        ++level;
        base3=level*base2;
        base2*=10;
        base1=base2*(num%10);
    }
    printf("%lld", sum);
    return 0;
}



#endif //PAT_P1836_HPP
