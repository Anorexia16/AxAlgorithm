/*
P1449 后缀表达式
题目描述:
    所谓后缀表达式是指这样的一个表达式：式中不再引用括号，
    运算符号放在两个运算对象之后，所有计算按运算符号出现的顺序，
    严格地由左而右新进行（不用考虑运算符的优先级）。
    如：3*(5–2)+7对应的后缀表达式为：3．5．2．-*7．+@。
    ’@’为表达式的结束符号。‘.’为操作数的结束符号。

输入格式:后缀表达式
输出格式:表达式的值
难度: 普及-
历史分数--100
*/

#ifndef PAT_P1449_HPP
#define PAT_P1449_HPP

#include <string>
#include <iostream>

int main() {
    long long stack[500] {}, si{}, tp{};
    std::string str;
    std::cin >> str;
    for(size_t i=0;;++i) {
        switch (str[i]) {
            case '.':
                stack[si++] = tp;
                tp = 0;
                break;
            case '@':
                break;
            case '+':
                stack[si-2] += stack[si-1];
                --si;
                break;
            case '-':
                stack[si-2] -= stack[si-1];
                --si;
                break;
            case '*':
                stack[si-2] *= stack[si-1];
                --si;
                break;
            case '/':
                stack[si-2] /= stack[si-1];
                --si;
                break;
            default:
                tp*=10;
                tp+=str[i]-'0';
                break;
        }
        if (str[i]=='@') break;
    }
    printf("%lld\n", stack[0]);
    return 0;
}

#endif //PAT_P1449_HPP
