#ifndef PAT_AVL_0512_HPP
#define PAT_AVL_0512_HPP

struct node {
    int nv {};
    int depth {};
    node *left = nullptr;
    node *right = nullptr;
    node *father = nullptr;
};


struct avl {
    node *root;

    static int abs(int x) {return x>0?x:-x;}

    static bool child(node *ptr) {return ptr->father->right==ptr;}

    static bool unb(node *ptr) {
        return abs((ptr->left==nullptr?0:ptr->left->depth)
        -(ptr->right==nullptr?0:ptr->right->depth))>1;
    }

    static void update(node *ptr) {
        int ld, rd;
        for (node *i=ptr;i!=nullptr;i=i->father) {
            ld = i->left==nullptr?0:i->left->depth;
            rd = i->right==nullptr?0:i->right->depth;
            i->depth = ld>rd?ld+1:rd+1;
        }
    }

    void insert(int x) {
        if (root==nullptr) {
            root = new node {x, 1, nullptr, nullptr, nullptr};
            return;
        }
        node *iter = root;
        while(true) {
            if (x==iter->nv) {
                return;
            } if (x>iter->nv) {
                if (iter->right==nullptr) {
                    iter->right = new node {x, 1, nullptr, nullptr, iter};
                    update(iter);
                    insert_fix(iter->right);
                    return;
                } else {
                    iter = iter->right;
                }
            } else {
                if (iter->left==nullptr) {
                    iter->left = new node {x, 1, nullptr , nullptr, iter};
                    update(iter);
                    insert_fix(iter->left);
                    return;
                } else {
                    iter = iter->left;
                }
            }
        }

    }

    void insert_fix(node *ptr) {
        node *gp;
        int uf {}, df;
        for (node *i=ptr;i->father!=nullptr;i=i->father) {
            df = uf;
            uf = child(i);
            if (unb(i->father)) {
                switch(df*2+uf) {
                    case 0:
                        l_t(i);
                        return;
                    case 1:
                        l_t(gp);
                        r_t(gp);
                        return;
                    case 2:
                        r_t(gp);
                        l_t(gp);
                        return;
                    default:
                        r_t(i);
                        return;
                }
            }
            gp = i;
        }
    }

    void r_t(node *x) {
        node *f = x->father;
        if (root==x->father) root=x;
        else child(f)? f->father->right=x: f->father->left=x;
        x->father = f->father;
        f->right = x->left;
        if (x->left!=nullptr) x->left->father=f;
        f->father = x;
        x->left = f;
        update(f);
    }

    void l_t(node *x){
        node *f = x->father;
        if (root==x->father) root=x;
        else child(f) ?f->father->right=x: f->father->left=x;
        x->father = f->father;
        f->left = x->right;
        if (x->right!=nullptr) x->right->father=f;
        f->father = x;
        x->right = f;
        update(f);
    }
};

#endif //PAT_AVL_0512_HPP
