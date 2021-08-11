/*
P5266 学籍管理
题目描述:
        您要设计一个学籍管理系统，最开始学籍数据是空的，然后该系统能够支持下面
    的操作（不超过 10^5条）：
        插入与修改，格式1 NAME SCORE：在系统中插入姓名为 NAME(由字母和数字
    组成不超过 20 个字符的字符串，区分大小写)，分数为 SCORE（0<SCORE<2^31）
    的学生。如果已经有同名的学生则更新这名学生的成绩为 SCORE。如果成功插入或者
    修改则输出OK。
        查询，格式2 NAME：在系统中查询姓名为 NAME 的学生的成绩。如果没能找到
    这名学生则输出Not found，否则输出该生成绩。
        删除，格式3 NAME：在系统中删除姓名为 NAME 的学生信息。如果没能找到这
    名学生则输出Not found，否则输出Deleted successfully。
        汇总，格式4：输出系统中学生数量。
输入格式:
    无
输出格式:
    无
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P5266_HPP
#define PAT_P5266_HPP

#include <unordered_map>
#include <iostream>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    std::unordered_map<std::string, int> mp{};
    std::string str;
    int q=read(), op, tp;
    while(q--) {
        op=read();
        switch (op) {
            case 1:
                std::cin>>str;
                tp=read();
                mp[str]=tp;
                puts("OK");
                break;
                case 2:
                    std::cin>>str;
                    if(mp.find(str)!=mp.end()) {
                        printf("%d\n", mp[str]);
                    } else {
                        puts("Not found");
                    }
                    break;
                    case 3:
                        std::cin>>str;
                        if(mp.find(str)!=mp.end()) {
                            mp.erase(str);
                            puts("Deleted successfully");
                        } else {
                            puts("Not found");
                        }
                        break;
                        default:
                            printf("%d\n", mp.size());
                            break;
        }
    }
    return 0;
}

#endif //PAT_P5266_HPP
