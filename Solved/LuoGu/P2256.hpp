/*
P2256 一中校运会之百米跑
题目描述:
    假设一共有N（2<=N<=20000）个参赛选手。（尼玛全校学生都没这么多吧）
    老师会告诉你这N个选手的名字。
    接着会告诉你M（1<=M<=1000000）句话，即告诉你学生A与学生B在同一个组里。
    如果学生A与学生B在同一组里，学生B与学生C也在同一组里，就说明学生A与学生C在同一组。
    然后老师会问你K（1<=K<=1000000）句话，即学生X和学生Y是否在同一组里。
    若是则输出"Yes."，否则输出"No."
输入格式:
    第一行输入N和M。
    接下来N行输入每一个同学的名字。
        再往下M行每行输入两个名字，且保证这两个名字都在上面的N行中出现过，表示这两个参赛
    选手在同一个组里。
    再来输入K。接下来输入K个体育老师的询问。
输出格式:
    对于每一个体育老师的询问，输出"Yes."或"No."。
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P2256_HPP
#define PAT_P2256_HPP

#include <unordered_map>
#include <iostream>
#include <string>

std::unordered_map<std::string, int> mp;
int *grp;
int find(int x) {
    int r=x, tp;
    while(r!=grp[r]) r=grp[r];
    while(x!=r) {
        tp=x;
        x=grp[x];
        grp[tp]=r;
    }
    return r;
}

int main() {
    std::string t1, t2;
    int n, r, a, b;
    std::cin>>n>>r;
    grp = new int[n];
    for(int i=0;i!=n;++i) grp[i]=i;
    for(int i=0;i!=n;++i) {
        std::cin>>t1;
        mp[t1]=i;
    }
    while(r--) {
        std::cin>>t1>>t2;
        a=mp[t1], b=mp[t2];
        grp[find(a)]=find(b);
    }
    std::cin>>r;
    while(r--) {
        std::cin>>t1>>t2;
        find(mp[t1])==find(mp[t2])?
        printf("Yes.\n"): printf("No.\n");
    }
    return 0;
}

#endif //PAT_P2256_HPP
