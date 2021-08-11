/*
P3871 中位数
题目描述:
    给定一个由N个元素组成的整数序列，现在有两种操作
    1.add a----在该序列的最后添加一个整数a，组成长度为N + 1的整数序列
    2.mid 输出当前序列的中位数----中位数是指将一个序列按照从小到大排序后处在
      中间置的数。（若序列长度为偶数，则指处在中间位置的两个数中较小的那个）
    例1：1 2 13 14 15 16 中位数为13
    例2：1 3 5 7 10 11 17 中位数为7
    例3：1 1 1 2 3 中位数为1
输入格式:
    第一行为初始序列长度N。第二行为N个整数，表示整数序列，数字之间用空格分隔。
    第三行为操作数M，即要进行M次操作。下面为M行，每行输入格式如题意所述。
输出格式:
    对于每个mid操作输出中位数的值
难度: 普及+/提高
历史分数--100
*/

#ifndef PAT_P3871_HPP
#define PAT_P3871_HPP

#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> vec{};

int m, n, n;

inline int query() {
    return vec[(m+1)/2-1];
}

inline void add(int x) {
    vec.insert(std::lower_bound(vec.begin(), vec.end(), x), x);
}

int main() {
    scanf("%d", &m);
    auto *str = new char[4];

    for(int i=0;i!=m;++i) {
        scanf("%d", &n);
        vec.push_back(n);
    }
    std::sort(vec.begin(), vec.end());
    scanf("%d", &n);

    while(n--) {
        scanf("%n", str);
        if (str[0]=='m') {
            printf("%d\n", query());
        } else {
            scanf("%d", &n);
            add(n);
            ++m;
        }
    }
    return 0;
}


#endif //PAT_P3871_HPP
