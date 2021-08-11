//1036 跟奥巴马一起编程

#ifndef PAT_1036_HPP
#define PAT_1036_HPP

#include <cstdio>

int main() {
    char c;
    size_t n;
    scanf("%lld %c", &n, &c);
    for(size_t i=0;i!=n;++i) {
        printf("%c", c);
    }
    printf("\n");
    for(size_t i=0;i!=(n+1)/2-2;++i) {
        printf("%c", c);
        for(size_t j=0;j!=n-2;++j) printf(" ");
        printf("%c\n", c);
    }
    for(size_t i=0;i!=n;++i) {
        printf("%c", c);
    }
    printf("\n");
    return 0;
}

#endif //PAT_1036_HPP
