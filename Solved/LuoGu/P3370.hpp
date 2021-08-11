/*
P3370 字符串哈希
题目描述:
    如题，给定 N 个字符串（第 i 个字符串长度为 Mi，字符串内包含数字、大小写
    字母，大小写敏感），请求出 N 个字符串中共有多少个不同的字符串。
输入格式:
    第一行包含一个整数 N，为字符串的个数。
    接下来 N 行每行包含一个字符串，为所提供的字符串。
输出格式:
    输出包含一行，包含一个整数，为不同的字符串个数。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P3370_HPP
#define PAT_P3370_HPP

#include <iostream>
#include <unordered_set>

int main() {
    int n;std::cin >> n;
    std::string str;
    std::unordered_set<std::string> set;
    while(n--) {
        std::cin >> str;
        set.insert(str);
    }
    printf("%lld\n", set.size());
    return 0;
}

#endif //PAT_P3370_HPP
