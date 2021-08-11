/*
P1996 约瑟夫问题
题目描述:
    n 个人围成一圈，从第一个人开始报数,数到 m 的人出列，
    再由下一个人重新从 1 开始报数，数到 m 的人再出圈，
    依次类推，直到所有的人都出圈，请输出依次出圈人的编号。

输入格式:输入两个整数 n,m。
输出格式:输出一行 n 个整数，按顺序输出每个出圈人的编号。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P1996_HPP
#define PAT_P1996_HPP

#include <vector>
#include <cstdio>

int main() {
    size_t n, m, dev{};
    std::vector<size_t> num;
    scanf("%lld%lld", &n, &m);
    num.reserve(n);
    for(size_t i=0;i!=n;++i) num.emplace_back(i);
    for(size_t i=0;i!=n;++i) {
        dev+=m-1;
        dev%=num.size();
        printf("%lld", 1+num[dev]);
        i==n-1?printf("\n"):printf(" ");
        num.erase(num.begin()+dev);
    }
    return 0;
}

#endif //PAT_P1996_HPP
