//1063 Set Similarity

#ifndef PAT_1063_HPP
#define PAT_1063_HPP

#include <cstdio>
#include <set>

using namespace std;

inline int read() {
    int x{}; char c = getchar();
    while(c>'9'||c<'0') c = getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    int n = read(), m, tp;
    set<int> sum, arr[n];
    for(int i=0;i!=n;++i) {
        m = read();
        while(m--) {
            tp=read();
            arr[i].insert(tp);
        }
    }
    tp = read();
    while(tp--) {
        sum.clear();
        m=read()-1, n=read()-1;
        sum.insert(arr[n].begin(), arr[n].end());
        sum.insert(arr[m].begin(), arr[m].end());
        printf("%.1lf%%\n",(arr[m].size()+arr[n].size()-sum.size())
                           *100.0/(sum.size()));
    }
}

#endif //PAT_1063_HPP
