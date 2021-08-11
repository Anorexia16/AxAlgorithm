//1058 A+B in Hogwarts

#ifndef PAT_1058_HPP
#define PAT_1058_HPP

#include <cstdio>

inline size_t read() {
    size_t x{}; char c=getchar();
    while(c<'0'||c>'9') c = getchar();
    while(c<='9'&&c>='0') {x=10*x+c-'0'; c=getchar();}
    return x;
}

inline void print(size_t x) {
    if (x>9) print(x/10);
    putchar(x%10+'0');
}

int main() {
    size_t sum{};
    sum += read()*17*29;
    sum += read()*29;
    sum += read();
    sum += read()*17*29;
    sum += read()*29;
    sum += read();
    print(sum/(29*17));
    putchar('.');
    print((sum/29)%17);
    putchar('.');
    print(sum%29);
    putchar('\n');
}

#endif //PAT_1058_HPP
