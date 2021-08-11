//1027 打印沙漏

#ifndef PAT_1027_HPP
#define PAT_1027_HPP

#include <cstdio>

int main() {
    int n, line{};
    char c;
    scanf("%d %c", &n, &c);
    for(;2*line*line-1<=n;++line);
    --line;
    for(size_t i=0;i!=line;++i) {
        for(size_t j=0;j!=i;++j) printf(" ");
        for(size_t j=0;j!=2*line-1-2*i;++j)
            printf("%c", c);
        for(size_t j=0;j!=i;++j) printf(" ");
        printf("\n");
    }
    for (size_t i=0;i<line-1;++i) {
        for(size_t j=0;j!=line-i-2;++j) printf(" ");
        for(size_t j=0;j!=2*i+3;++j) printf("%c", c);
        for(size_t j=0;j!=line-i-2;++j) printf(" ");
        printf("\n");
    }
    printf("%d\n", n-2*line*line+1);
    return 0;
}

#endif //PAT_1027_HPP
