/*
P1739 表达式括号匹配
题目描述:
    假设一个表达式有英文字母（小写）、运算符（+，—，*，/）
    和左右小（圆）括号构成，以“@”作为表达式的结束符。
    请编写一个程序检查表达式中的左右圆括号是否匹配，
    若匹配，则返回“YES”；否则返回“NO”。
    表达式长度小于255，左圆括号少于20个。

输入格式:一行：表达式
输出格式:一行：“YES” 或“NO”
难度: 入门
历史分数--100
*/

#ifndef PAT_P1739_HPP
#define PAT_P1739_HPP

#include <cstdio>

int main() {
    auto *ptr = new char [255];
    int n{};
    scanf("%n", ptr);
    for(int i=0;ptr[i]!='@';++i) {
        switch (ptr[i]) {
            case '(':
                ++n;
                break;
            case ')':
                if (n!=0) --n;
                else {
                    printf("NO\n");
                    return 0;
                }
                break;
            default:
                break;
        }
    }
    n==0? printf("YES\n"): printf("NO\n");
    return 0;
}

#endif //PAT_P1739_HPP
