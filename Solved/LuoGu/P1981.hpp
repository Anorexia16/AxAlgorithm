/*
P1981 表达式求值
题目描述:
    给定一个只包含加法和乘法的算术表达式，请你编程计算表达式的值。

输入格式:一行，为需要你计算的表达式，表达式中只包含数字、
加法运算符“+”和乘法运算符“×”，
且没有括号，所有参与运算的数字均为 0 到 2^{31}之间的整数。
输入数据保证这一行只有0-9、+、×这 12种字符。

输出格式:一个整数，表示这个表达式的值。
注意：当答案长度多于4位时，请只输出最后4位，前导0不输出。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P1981_HPP
#define PAT_P1981_HPP

#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;
    bool time {};
    size_t len{str.size()}, value{}, stack[100000], si{}, ans{};
    for(size_t i=0;i!=len;++i) {
        switch (str[i]) {
            case '*':
                if (!time) {
                    stack[si++]=value%10000;
                } else {
                    stack[si-1]*=value%10000;
                    stack[si-1]%=10000;
                }
                time = true;
                value = 0;
                break;
            case '+':
                if (!time) {
                    stack[si++]=value%10000;
                } else {
                    stack[si-1]*=value%10000;
                    stack[si-1]%=10000;
                }
                value = 0;
                time = false;
                break;
            default:
                value*=10;
                value+=str[i]-'0';
                break;
        }
    }
    if (!time) {
        stack[si++]=value;
    } else {
        stack[si-1]*=value%10000;
        stack[si-1]%=10000;
    }
    for(size_t i=0;i!=si;++i) {
        ans += stack[i];
    }
    printf("%lld", ans%10000);
    return 0;
}


#endif //PAT_P1981_HPP
