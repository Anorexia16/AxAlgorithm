//1068 万绿丛中一点红

#ifndef PAT_1068_HPP
#define PAT_1068_HPP

#include <cstdio>
#include <map>

inline int abs(int x) {return x>0?x:-x;}

struct pos {int x, y, count;};

int main() {
    std::map<int, pos> map{};
    std::map<int, int> m2{};
    int m, n, tol, px=-1, py=-1, value;
    scanf("%d %d %d", &m, &n, &tol);
    int arr[n][m];
    for (int i=0;i!=n;++i) {
        for(int j=0;j!=m;++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i=0;i!=n;++i) {
        for(int j=0;j!=m;++j) {
            ++m2[arr[i][j]];
            if (j!=0) {
                if (abs(arr[i][j-1]-arr[i][j])<=tol) continue;
                if (i!=0) if (abs(arr[i-1][j-1]-arr[i][j])<=tol) continue;
                if (i!=n) if (abs(arr[i+1][j-1]-arr[i][j])<=tol) continue;
            }
            if (j!=m) {
                if (abs(arr[i][j+1]-arr[i][j])<=tol) continue;
                if (i!=0) if (abs(arr[i-1][j+1]-arr[i][j])<=tol) continue;
                if (i!=n) if (abs(arr[i+1][j+1]-arr[i][j])<=tol) continue;
            }
            if (i!=0) if (abs(arr[i-1][j]-arr[i][j])<=tol) continue;
            if (i!=n) if (abs(arr[i-1][j]-arr[i][j])<=tol) continue;
            if (map.find(arr[i][j])!=map.end()) {
                ++map[arr[i][j]].count;
            } else {
                map[arr[i][j]] = pos{i, j, 1};
            }

        }
    }
    for (auto const &iter:map) {
        if (iter.second.count==1&&m2[iter.first]==1) {
            if (px!=-1) {
                printf("Not Unique\n");
                return 0;
            } else {
                px = iter.second.x;
                py = iter.second.y;
            }
        }
    }
    if(px!=-1) printf("(%d, %d): %d\n", py+1, px+1, arr[px][py]);
    else printf("Not Exist\n");
    return 0;
}

#endif //PAT_1068_HPP
