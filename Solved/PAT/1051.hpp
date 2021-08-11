//1051 Pop Sequence

#ifndef PAT_1051_HPP
#define PAT_1051_HPP

#include <iostream>
#include <string>

inline int read() {
    int x=0;char c= getchar();
    while(c>'9'||c<'0') c=getchar();
    while('0'<=c&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    std::string ruby;
    int cap=read(), len=read(), ins=read(), si, yf, gen, tp;
    int stack[cap];
    for(int q=0;q!=ins;++q) {
        si=0, yf=1, gen=1;
        for(int i=0;i!=len;++i) {
            tp = read();
            if (yf) {
                if (gen == tp) {++gen;continue;}
                if (si!=0) {
                    if (tp == stack[si - 1]) {
                        --si;
                        continue;
                    }
                    else if (tp < stack[si - 1]) {
                        yf = 0;
                        continue;
                    }
                }
                while (gen<tp) {
                    if (si==cap) {
                        yf = 0;
                        break;
                    } else {
                        stack[si++] = gen++;
                    }
                }
                si==cap? yf=0:++gen;
            } else {
                continue;
            }
        }
        yf? printf("YES\n"): printf("NO\n");
    }
}
#endif //PAT_1051_HPP
