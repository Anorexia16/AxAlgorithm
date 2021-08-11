// 1105 Spiral Matrix

#ifndef PAT_1105_HPP
#define PAT_1105_HPP

#include <cstdio>
#include <algorithm>

int main() {
    int heap[10000], matrix[100][100];
    unsigned long N, m, n, mm, dir=0, x=0, y=0;
    scanf("%ul", &N);
    for (unsigned long i=0;i!=N;++i) scanf("%d", heap+i);
    mm = N;
    for (unsigned int i=N;i*i>=N;--i) if (N%i==0) mm=i;
    m = mm;
    n = N/m;
    std::make_heap(heap, heap+N);
    while (N!=0) {
        matrix[y][x] = heap[0];
        std::pop_heap(heap, heap+(N--));
        switch (dir) {
            case 0:
                if(y+x+1==n) {
                    ++y;
                    dir=1;
                } else {
                    ++x;
                }
                break;
            case 1:
                if(n+y-x==m) {
                    --x;
                    dir=2;
                } else {
                    ++y;
                }
                break;
            case 2:
                if(y+x+1==m) {
                    --y;
                    dir = 3;
                } else {
                    --x;
                }
                break;
            default:
                if (y-x==1) {
                    ++x;
                    dir = 0;
                } else {
                    --y;
                }
        }
    }

    for(int i=0; i!=m;++i) {
        for (int j=0;j!=n;++j) {
            printf("%d", matrix[i][j]);
            if (j!=n-1) printf(" ");
        }
        puts("");
    }
    return 0;
}

#endif //PAT_1105_HPP
