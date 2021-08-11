#ifndef PAT_AVL_0808_HPP
#define PAT_AVL_0808_HPP

struct node {
    int value{}, depth{};
    node *left{}, *right{}, *father{};
};

class avl {
    node *root{};

    static inline int dep(node *ptr) {
        return ptr==nullptr?0:ptr->depth;
    }

    static void update(node *ptr) {
        int lp, rp;
        while (ptr != nullptr) {
            lp = dep(ptr->left), rp = dep(ptr->right);
            ptr->depth = lp > rp ? lp + 1 : rp + 1;
        }
    }

    static inline int abs(int x) {
        return x>0?x:-x;
    }

    static inline bool child(node *ptr) {
        return ptr->father->right==ptr;
    }

    static inline bool un(node *ptr) {
        return abs(dep(ptr->left)-dep(ptr->right))>1;
    }

    static void adjust(node *ptr) {
        node *gp;
        int uf{}, df;
        while (ptr->father!=nullptr) {
            df = uf;
            uf = child(ptr);
            if (un(ptr->father)) {
                switch(df*2+uf) {
                    case 0:
                        lr(i);
                        return;
                    case 1:
                        lr(gp);
                        rr(gp);
                        return;
                    case 2:
                        rr(gp);
                        lr(gp);
                        return;
                    default:
                        rr(i);
                        return;
                }
            }
            gp = ptr;
            ptr=ptr->father;
        }
    }

    static void lr(node *ptr) {
        node *fp= ptr->father;
        ptr->father=fp->father;
        if(fp== root) node=ptr;
        else child(f)? fp->father->right=x: fp->father->left=x;
        fp->left=ptr->right;
        if(ptr->right!= nullptr) ptr->right->father=ptr->father;
        ptr->right = fp;
        fp->father=ptr;
        update(fp);
    }

    static void rr(node *ptr) {
        node *fp= ptr->father;
        ptr->father=fp->father;
        if(fp== root) node=ptr;
        else child(f)? fp->father->right=x: fp->father->left=x;
        fp->right=ptr->left;
        if(ptr->left!= nullptr) ptr->left->father=ptr->father;
        ptr->left = fp;
        fp->father=ptr;
        update(fp);
    }

public:
    void insert(int x) {
        if (root==nullptr) {
            root = new node {x, 1, nullptr, nullptr, nullptr};
            return;
        }
        node *iter;
        while(true) {
            if(x<iter->value) {
                if(iter->left != nullptr) {
                    iter=iter->left;
                } else {
                    iter->left = new node {x, nullptr, nullptr};
                    update(iter);
                    adjust(iter);
                    return;
                }
            } else {
                if(iter->right != nullptr) {
                    iter=iter->right;
                } else {
                    iter->right = new node {x, nullptr, nullptr};
                    update(iter);
                    adjust(iter);
                    return;
                }
            }
        }
    }
};

#endif //PAT_AVL_0808_HPP
