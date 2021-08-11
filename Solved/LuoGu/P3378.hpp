/*
P1836 数页码
题目描述:
    给定一个数列，初始为空，请支持下面三种操作：

    给定一个整数 x，请将 x 加入到数列中。
    输出数列中最小的数。
    删除数列中最小的数（如果有多个数最小，只删除 1 个）。

输入格式:第一行是一个整数，表示操作的次数 n。
接下来 n 行，每行表示一次操作。每行首先有一个整数 op 表示
 操作类型。

若 op=1，则后面有一个整数 x，表示要将 x 加入数列。
若 op=2，则表示要求输出数列中的最小数。
若 op=3，则表示删除数列中的最小数。如果有多个数最小，
 只删除 1 个。
输出格式:对于每个操作 2，输出一行一个整数表示答案。
难度: 提高+/省选-
历史分数--100
*/

#ifndef PAT_P3378_HPP
#define PAT_P3378_HPP

#include <cstdio>
#include <queue>
#include <vector>


int main() {
    std::priority_queue<size_t, std::vector<size_t>, std::greater<>> heap {};
    size_t num, op;
    scanf("%lld", &num);
    for (size_t i=0;i!=num;++i) {
        scanf("%lld", &op);
        switch (op) {
            case 1:
                scanf("%lld", &op);
                heap.push(op);
                break;
            case 2:
                printf("%lld\n", heap.top());
                break;
            default:
                heap.pop();
                break;
        }
    }
    return 0;
}

#endif //PAT_P3378_HPP
