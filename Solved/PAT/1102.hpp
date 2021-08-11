// 1102 Invert a Binary Tree

#ifndef PAT_1102_HPP
#define PAT_1102_HPP

#include <iostream>

struct node {
    int left = -1;
    int right = -1;

};

int main() {
    size_t n, root{}, bi{}, ei{}, qe[20], s[20], si{}, tp;
    bool is_root[10] {};
    char l, r;
    node tree[10];
    scanf("%lld\n", &n);
    for (int i=0;i!=n;++i) {
        std::cin >>l >>r;
        if (l!='-') {
            tree[i].left = l-'0';
            is_root[l-'0'] = true;
        }
        if (r!='-') {
            tree[i].right = r-'0';
            is_root[r-'0'] = true;
        }
    }
    for (int i=0;i!=n;++i) {
        if(!is_root[i]) {
            root = i;
            break;
        }
    }
    qe[ei++] = root;
    printf("%lld", root);
    for(int i=1;i<n;++i) {
        if (tree[qe[bi]].right!=-1) qe[ei++]=tree[qe[bi]].right;
        if (tree[qe[bi]].left!=-1) qe[ei++]=tree[qe[bi]].left;
        printf( " %lld", qe[++bi]);
    }
    printf("\n");
    while(true) {
        s[si++] = root;
        if (tree[root].right==-1) break;
        root=tree[root].right;
    };
    for(int i=0;i<n;++i) {
        tp = s[--si];
        printf("%lld", tp);
        if (i<n-1) printf(" ");
        if (tree[tp].left!=-1) {
            s[si++] = tree[tp].left;
            while(tree[s[si-1]].right!=-1) {
                s[si] = tree[s[si-1]].right;
                ++si;
            }
        }
    }
    printf("\n");
    return 0;
}

#endif //PAT_1102_HPP
