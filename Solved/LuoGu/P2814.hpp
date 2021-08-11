/*
P2814 家谱
题目描述:
    给出充足的父子关系，请你编写程序找到某个人的最早的祖先。
输入格式:
        输入由多行组成，首先是一系列有关父子关系的描述，其中每一组父子关系中父亲
    只有一行，儿子可能有若干行，用 #name 的形式描写一组父子关系中的父亲的名字，
    用 +name 的形式描写一组父子关系中的儿子的名字；接下来用 ?name 的形式表示
    要求该人的最早的祖先；最后用单独的一个 $ 表示文件结束。
输出格式:
        按照输入文件的要求顺序，求出每一个要找祖先的人的祖先，格式为：本人的名字
    + 一个空格 + 祖先的名字 + 回车。
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P2814_HPP
#define PAT_P2814_HPP

#include <unordered_map>
#include <iostream>

std::unordered_map<std::string, std::string> mp;
inline std::string find(std::string str) {
    std::string r=str, tp;
    while (r!=mp[r]) r=mp[r];
    while (str!=r) {
        tp=str;
        str=mp[str];
        mp[tp]=r;
    }
    return r;
}

int main() {
    std::string fa, child;
    while(true) {
        switch (getchar()) {
            case '#':
                std::cin >> fa;
                if(mp.find(fa)==mp.end()) mp[fa] = fa;
                getchar();
                break;
                case '+':
                    std::cin >> child;
                    mp[child] = child;
                    mp[child] = find(fa);
                    getchar();
                    break;
                    case '?':
                        std::cin >> child;
                        std::cout<<child<<' '<<find(child)<<std::endl;
                        getchar();
                        break;
                        default:
                            return 0;
        }
    }
}

#endif //PAT_P2814_HPP
