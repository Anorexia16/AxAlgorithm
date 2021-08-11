// 1123 Is it complete AVL Tree?

#ifndef PAT_1123_HPP
#define PAT_1123_HPP

#include <cstdio>
#include <queue>

struct node {
    int nv {};
    int depth {};
    node *l = nullptr;
    node *r = nullptr;
    node *f = nullptr;
};

int abs(int x) {return x>0?x:-x;}

bool child(node *x) {
    return x->f->r==x;
}

bool un(node *i) {
    int ld = i->l == nullptr? 0:i->l->depth;
    int rd = i->r == nullptr? 0:i->r->depth;
    return abs(ld-rd)>1;
}

class avl {
public:
    node *root = nullptr;

    void insert(int);

    static void update(node*);

    void insert_fix(node *);

    void lt(node *);

    void rt(node *);
};

void avl::insert(int x) {
    if (root == nullptr) {
        root = new node {x, 1, nullptr, nullptr, nullptr};
        return;
    }
    node *i = root;
    while (true) {
        if (x>i->nv) {
            if (i->r!= nullptr) {
                i=i->r;
            } else {
                i->r=new node {x, 1, nullptr, nullptr, i};
                update(i);
                insert_fix(i->r);
                return;
            }
        } else {
            if (i->l!= nullptr) {
                i=i->l;
            } else {
                i->l=new node {x, 1, nullptr, nullptr, i};
                update(i);
                insert_fix(i->l);
                return;
            }
        }
    }
}

void avl::update(node *x) {
    int ld, rd;
    for (node *i=x;i!= nullptr;i=i->f) {
        ld = i->l == nullptr? 0:i->l->depth;
        rd = i->r == nullptr? 0:i->r->depth;
        i->depth = ld>rd? ld+1: rd+1;
    }
}

void avl::insert_fix(node *x) {
    node *p;
    int df= 0, uf= 0;
    for (node* i=x;i->f!= nullptr;i=i->f) {
        df = uf;
        uf = child(i);
        if(un(i->f)) {
            switch (df+uf*2) {
                case 0:
                    lt(i);
                    return;
                case 1:
                    rt(p);
                    lt(p);
                    return;
                case 2:
                    lt(p);
                    rt(p);
                    return;
                default:
                    rt(i);
                    return;
            }
        }
        p = i;
    }
}

void avl::lt(node *x) {
    node *p = x->f;
    if (root==p) root=x;
    else child(p) ?p->f->r=x:p->f->l=x;
    x->f = p->f;
    p->l = x->r;
    if (x->r!= nullptr) x->r->f=p;
    p->f = x;
    x->r = p;
    update(p);
}

void avl::rt(node *x) {
    node *p = x->f;
    if (root==p) root=x;
    else child(p) ?p->f->r=x:p->f->l=x;
    x->f = p->f;
    p->r = x->l;
    if (x->l!= nullptr) x->l->f=p;
    p->f = x;
    x->l = p;
    update(p);
}

int main() {
    int N, temp, n{};
    std::queue<node*> q;
    avl t {};
    bool deny = false, complete = true;
    scanf("%d", &N);
    for (int i=0;i!=N;++i) {
        scanf("%d", &temp);
        t.insert(temp);
    }
    q.push(t.root);
    while(!q.empty()) {
        if (q.front()->l!= nullptr) {
            if(deny) complete= false;
            q.push(q.front()->l);
        } else deny= true;
        if (q.front()->r!= nullptr) {
            if(deny) complete= false;
            q.push(q.front()->r);
        } else deny= true;
        printf("%d",q.front()->nv);
        if (n++!=N-1) printf(" ");
        q.pop();
    }
    complete? printf("\nYES\n"): printf("\nNO\n");
}

#endif //PAT_1123_HPP
