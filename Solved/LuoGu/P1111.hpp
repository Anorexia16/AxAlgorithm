/*
P1111 修复公路
题目描述:
    给出A地区的村庄数N，和公路数M，公路是双向的。并告诉你每条公路的连着哪两个
    村庄，并告诉你什么时候能修完这条公路。问最早什么时候任意两个村庄能够通车，
    即最早什么时候任意两条村庄都存在至少一条修复完成的道路（可以由多条公路连成
    一条道路）
输入格式:
    第1行两个正整数N,M
    下面M行，每行3个正整数x, y, t，告诉你这条公路连着x,y两个村庄，在时间t时
    能修复完成这条公路。
输出格式:
    如果全部公路修复完毕仍然存在两个村庄无法通车，则输出-1，否则输出最早什么时
    候任意两个村庄能够通车。
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P1111_HPP
#define PAT_P1111_HPP

#include <algorithm>
#include <cstdio>

size_t ct, road, f, t, c;
size_t root[100000], q[100000];

struct plan {
    size_t from;
    size_t to;
    size_t time;
};

plan y[100000];

bool cmp (plan const &a, plan const &b) {
    return a.time<b.time;
}

size_t find(size_t from) {
    size_t rt = root[from];
    while(rt!=root[rt]) rt=root[rt];
    return rt;
}

int main() {
    scanf("%lld%lld", &ct, &road);

    for(size_t i=0;i!=ct;++i) {
        root[i] = i;
        q[i] = 1;
    }
    for(size_t i=0;i!=road;++i) {
        scanf("%lld%lld%lld", &f, &t, &c);
        y[i] = plan{f, t, c};
    }
    std::sort(y, y + road, cmp);
    for(size_t i=0;i!=road;++i) {
        f = find(y[i].from), t = find(y[i].to);
        if (f != t) {
            root[f] = t;
            --ct;
        }
        if (ct==1) {
            printf("%lld\n", y[i].time);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}

#endif //PAT_P1111_HPP
