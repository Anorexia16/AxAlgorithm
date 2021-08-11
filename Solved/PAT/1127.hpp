//1127 ZigZagging on a Tree

#ifndef PAT_1127_HPP
#define PAT_1127_HPP

#include <unordered_map>
#include <cstdio>
#include <stack>

inline int read() {
    int x{}, c=getchar();
    while (c>'9'||c<'0') c=getchar();
    while (c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

struct node {
    int value{};
    node *left{}, *right{};
};

std::unordered_map<int, int> pm, im;

int *po, *in, n;

void pi_b(int low, int high, node* &ptr) {
    int idx1=im[ptr->value], left = idx1-low, right= high-idx1, idx2 = pm[ptr->value];
    if(left > 0){
        ptr->left=new node {po[idx2-right-1], nullptr, nullptr};
        pi_b(low, idx1-1, ptr->left);
    }
    if(right > 0){
        ptr->right = new node {po[idx2-1], nullptr, nullptr};
        pi_b(idx1+1, high, ptr->right);
    }
}

int main() {
    node *iter; n=read();
    int me=1, pd=0;
    std::stack<node *> st[2];
    po=new int [n], in = new int [n];
    for(int i=0;i!=n;++i) in[i]=read(), im.insert({in[i], i});
    for(int i=0;i!=n;++i) po[i]=read(), pm.insert({po[i], i});
    auto *root= new node {po[n-1], nullptr, nullptr};
    pi_b(0, n-1, root);
    st[me].push(root);
    while(!st[0].empty()||!st[1].empty()) {
        while(!st[me].empty()) {
            iter=st[me].top(), st[me].pop();
            if(me==0) {
                if(iter->left!= nullptr) st[1-me].push(iter->left);
                if(iter->right!= nullptr) st[1-me].push(iter->right);
            } else {
                if(iter->right!= nullptr) st[1-me].push(iter->right);
                if(iter->left!= nullptr) st[1-me].push(iter->left);
            }
            if(pd) putchar(' ');
            printf("%d", iter->value);
            pd= true;
        }
        me=1-me;
    }
    return 0;
}

#endif //PAT_1127_HPP
