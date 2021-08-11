//1125 Chain the Ropes

#ifndef PAT_1125_HPP
#define PAT_1125_HPP

#include <cstdio>
#include <queue>
#include <cmath>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    std::priority_queue<long double, std::vector<long double>, std::greater<>> que;
    int n=read();
    long double tp;
    while(n--) {
        que.emplace(read());
    }
    while(que.size()!=1) {
        tp=que.top();
        que.pop();
        tp+=que.top();
        que.pop();
        que.push(tp/2);
    }
    printf("%d", (int)(que.top()));
}

#endif //PAT_1125_HPP
