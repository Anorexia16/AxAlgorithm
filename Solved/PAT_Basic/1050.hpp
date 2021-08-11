//1050 螺旋矩阵

#ifndef PAT_1050_HPP
#define PAT_1050_HPP

#include <algorithm>
#include <vector>
#include <cstdio>

int main() {
    std::vector<size_t> arr;
    size_t len, m, n, dir{}, mi{}, ni{};
    scanf("%lld", &len);
    arr.reserve(len);
    for(size_t i=0;i!=len;++i) {
        scanf("%lld", &m);
        arr.emplace_back(m);
    }
    std::sort(std::rbegin(arr), std::rend(arr));
    for(size_t i=1;i*i<=len;++i) {
        if (len%i==0) {
            n=i;
            m=len/i;
        }
    }
    size_t matrix[m][n];
    for(size_t i=0;i!=len;++i) {
        matrix[mi][ni] = arr[i];
        switch (dir) {
            case 0:
                if (mi+ni==n-1) {
                    ++mi;
                    dir=1;
                } else ++ni;
                break;
            case 1:
                if (mi+n-ni==m) {
                    --ni;
                    dir=2;
                } else ++mi;
                break;
            case 2:
                if (ni+mi==m-1) {
                    --mi;
                    dir=3;
                } else --ni;
                break;
            default:
                if (mi==ni+1) {
                    ++ni;
                    dir=0;
                } else --mi;
                break;
        }
    }
    for(size_t i=0;i!=m;++i) {
        for(size_t j=0;j!=n;++j) {
            j==n-1? printf("%lld\n", matrix[i][j]):
            printf("%lld ", matrix[i][j]);
        }
    }
}


#endif //PAT_1050_HPP
