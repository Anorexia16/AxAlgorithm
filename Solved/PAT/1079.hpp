//1079 Total Sales of Supply Chain

#ifndef PAT_1079_HPP
#define PAT_1079_HPP

#include <cstdio>
#include <vector>
#include <stack>
#include <cmath>

struct node {
    int to{};node *next{};
};

struct retailer{
    int dev{}, amount{};
};

inline double times(double base, double rate, int times) {
    while(times--) base*=rate;
    return base;
};

inline int read() {
    int x{};char c =getchar();
    while(c>'9'||c<'0') c = getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    std::vector<int> rei{};
    std::stack<node*> dfs;
    std::stack<int> dp;
    int n=read(), m, tp;
    double c, rate, ans{};
    scanf("%lf%lf", &c, &rate);
    rate=1.0+0.01*rate;
    node arr[n]; retailer re[n];
    for(int i=0;i!=n;++i) {
        m=read();
        arr[i].to = m;
        if (m!=0) {
            while(m--) {
                tp=read();
                arr[i].next = new node{tp, arr[i].next};
            }
        } else {
            re[i] = retailer{100000, read()};
            rei.emplace_back(i);
        }
    }
    n = 0;
    if (arr[0].to==0) {
        printf("%.1lf\n", c*re[0].amount);
        return 0;
    }
    node *iter = arr[0].next;
    while(true) {
        if (iter->next!= nullptr) {
            dfs.push(iter->next);
            dp.push(n);
        }
        if (arr[iter->to].to==0) {
            ++n;
            re[iter->to].dev = re[iter->to].dev<n?re[iter->to].dev:n;
            if (dfs.empty()) {
                break;
            } else {
                iter=dfs.top();dfs.pop();
                n=dp.top();dp.pop();
            }
        } else {
            iter = arr[iter->to].next;
            ++n;
        }
    }
    for(auto const &it: rei) ans+= re[it].amount*c*pow(rate, re[it].dev);
    printf("%.1lf\n", ans);
    return 0;
}


#endif //PAT_1079_HPP
