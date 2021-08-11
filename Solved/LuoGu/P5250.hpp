/*
P5250 木材仓库
题目描述:
        博艾市有一个木材仓库，里面可以存储各种长度的木材，但是保证没有两个木材
    的长度是相同的。作为仓库负责人，你有时候会进货，有时候会出货，因此需要维护这
    个库存。有不超过 100000 条的操作：
        进货，格式1 Length：在仓库中放入一根长度为 Length(不超过 10^9) 的
    木材。如果已经有相同长度的木材那么输出Already Exist。
        出货，格式2 Length：从仓库中取出长度为 Length 的木材。如果没有刚好
    长度的木材，取出仓库中存在的和要求长度最接近的木材。如果有多根木材符合要求，
    取出比较短的一根。输出取出的木材长度。如果仓库是空的，输出Empty。
输入格式:
    无
输出格式:
    无
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P5250_HPP
#define PAT_P5250_HPP
#include <algorithm>
#include <cstdio>
#include <set>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    std::set<int> st{};
    int q=read(), op, x;
    while(q--) {
        op=read(), x=read();
        if(op==1) {
            if(st.find(x)!=st.end()) {
                printf("Already Exist\n");
            } else {
                st.insert(x);
            }
        } else {
            {
                if(st.empty()) printf("Empty\n");
                else if (st.count(x)) {
                    st.erase(x);
                    printf("%d\n", x);
                }
                else {
                    st.insert(x);
                    auto it = st.find(x);
                    auto it2 = it;
                    it++;
                    if (it2 == st.begin()) {
                        printf("%d\n", *it);
                        st.erase(it);
                    }
                    else if (it == st.end()) {
                        printf("%d\n", *(--it2));
                        st.erase(it2);
                    }
                    else if (x-*(--it2) > *it-x) {
                        printf("%d\n", *it);
                        st.erase(it);
                    }
                    else {
                        printf("%d\n", *it2);
                        st.erase(it2);
                    }
                    st.erase(x);
                }
            }
        }
    }
    return 0;
}


#endif //PAT_P5250_HPP
