/*
P1540 机器翻译
题目描述:
        这个翻译软件的原理很简单，它只是从头到尾，依次将每个英
    文单词用对应的中文含义来替换。对于每个英文单词，软件会先在
    内存中查找这个单词的中文含义，如果内存中有，软件就会用它进
    行翻译；如果内存中没有，软件就会在外存中的词典内查找，查出
    单词的中文含义然后翻译，并将这个单词和译义放入内存，以备后
    续的查找和翻译。假设内存中有M个单元，每单元能存放一个单词
    和译义。每当软件将一个新单词存入内存前，如果当前内存中已存
    入的单词数不超过 M-1，软件会将新单词存入一个未使用的内存单
    元；若内存中已存入M个单词，软件会清空最早进入内存的那个单词，
    腾出单元来，存放新单词。
    假设一篇英语文章的长度为 N 个单词。给定这篇待译文章，翻译软
    件需要去外存查找多少次词典？假设在翻译开始前，内存中没有任何
    单词。

输入格式:共 2 行。每行中两个数之间用一个空格隔开。
第一行为两个正整数 M,N，代表内存容量和文章的长度。
第二行为 N 个非负整数，按照文章的顺序，每个数（大小不超过1000）
    代表一个英文单词。文章中两个单词是同一个单词，
    当且仅当它们对应的非负整数相同。
输出格式:一行，代表所有单个数字的和。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P1540_HPP
#define PAT_P1540_HPP

#include <cstdio>
#include <vector>

int main() {
    size_t m, n, tp, count{};
    bool find;
    scanf("%lld%lld", &m, &n);
    std::vector<size_t> mem {};
    for(size_t i=0;i!=n;++i) {
        scanf("%lld", &tp);
        find = false;
        if (mem.size()<m) {
            for(auto const &iter:mem) {
                if (iter==tp) {
                    find = true;
                    break;
                }
            }
            if (!find) {
                mem.emplace_back(tp);
                ++count;
            }
        } else {
            for(auto const &iter:mem) {
                if (iter==tp) {
                    find = true;
                    break;
                }
            }
            if (!find) {
                mem.erase(mem.begin());
                mem.emplace_back(tp);
                ++count;
            }
        }
    }
    printf("%lld\n", count);
    return 0;
}

#endif //PAT_P1540_HPP
