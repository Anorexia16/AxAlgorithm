/*
P3366 [模板]最小生成树
题目描述:
   如题，给出一个无向图，求出最小生成树，如果该图不连通，则输出 orz。
输入格式:
    第一行包含两个整数 N,M，表示该图共有 N 个结点和 M 条无向边。
    接下来 M 行每行包含三个整数 Xi,Yi,Zi，表示有一条长度为 Zi的无向
    边连接结点 Xi,Yi。
输出格式:
    如果该图连通，则输出一个整数表示最小生成树的各边的长度之和。
    如果该图不连通则输出 orz。
难度: 普及-
历史分数--100
*/

#ifndef PAT_P3366_HPP
#define PAT_P3366_HPP

#include <queue>
#include <vector>
#include <cstdio>

struct edge {
    int weight{}, from{}, to{};
    edge *next {};
};

struct cmp{
    bool operator()(edge const *a, edge  const *b) {
        return a->weight >= b->weight;
    }
};

int main() {
    int n, m, a, b, w, s{};
    scanf("%d %d", &n, &m);
    edge *graph[n], *iter;
    bool traveled[n];
    std::queue<edge *> bfs{};
    std::priority_queue<edge*, std::vector<edge*>, cmp> pq {};

    for (int i=0;i!=n;++i) traveled[i] = false;
    for(int i=0;i!=n;++i) graph[i] = new edge{};
    for(int i=0;i!=m;++i) {
        scanf("%d %d %d", &a, &b, &w);
        graph[a-1]->next = new edge{w, a-1, b-1, graph[a-1]->next};
        graph[b-1]->next = new edge{w, b-1, a-1, graph[b-1]->next};
    };

    int c = n-1;
    iter = graph[0]->next;
    traveled[0] = true;
    while (iter != nullptr) {
        if(!traveled[iter->to]) {
            traveled[iter->to] = true;
            bfs.push(iter);
            --c;
        }
        iter = iter->next;
    }
    while(!bfs.empty()) {
        iter = graph[bfs.front()->to]->next;
        while (iter != nullptr) {
            if(!traveled[iter->to]) {
                traveled[iter->to] = true;
                bfs.push(iter);
                --c;
            }
            iter = iter->next;
        }
        bfs.pop();
    }
    if (c!=0) {
        printf("orz\n");
        return 0;
    }
    for (int i=0;i!=n;++i) traveled[i] = false;
    iter = graph[0]->next;
    traveled[0] = true;
    while (iter != nullptr) {
        pq.push(iter);
        iter = iter->next;
    }
    while(!pq.empty()) {
        if (traveled[pq.top()->to]) {
            pq.pop();
            continue;
        }
        s += pq.top()->weight;
        iter = graph[pq.top()->to]->next;
        traveled[pq.top()->to] = true;
        pq.pop();
        while (iter != nullptr) {
            if(!traveled[iter->to]) {
                pq.push(iter);
            }
            iter = iter->next;
        }
    }
    printf("%d\n", s);
    return 0;
}

#endif //PAT_P3366_HPP
