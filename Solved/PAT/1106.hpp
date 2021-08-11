//1106 Lowest Price in Supply Chain

#ifndef PAT_1106_HPP
#define PAT_1106_HPP

#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

std::vector <int> g[100000];

void BFS(std::vector <int> &dist);
int main()
{
    int N,  K;
    double P, r;
    scanf("%d%lf%lf", &N, &P, &r);
    std::vector <int> dist(N, -1), retailer;
    for (int i = 0; i < N; i++) {
        scanf("%d", &K);
        if (K == 0) {
            retailer.push_back(i);
            continue;
        }
        int u;
        for (int j = 0; j < K; j++) {
            scanf("%d", &u);
            g[i].push_back(u);
        }
    }
    BFS(dist);
    std::vector <int> rDist;
    for (int i = 0; i < retailer.size(); i++)
        rDist.push_back(dist[retailer[i]]);//记录零售商的加价程度，也就是price的系数的指数
    sort(rDist.begin(), rDist.end());//排序
    int ansDist = rDist[0], cnt = 1;
    for (int i = 1; i < rDist.size(); i++) {
        if (rDist[i] > ansDist)
            break;
        cnt++;
    }
    double price = pow(1 + r / 100.0, ansDist)*P;
    printf("%.4lf %d\n", price, cnt);
    return 0;
}
void BFS(std::vector <int> &dist) {
    int u, v;
    std::queue<int> Q;
    Q.push(0);
    dist[0] = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = 0; i < g[u].size(); i++) {
            v = g[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

#endif //PAT_1106_HPP
