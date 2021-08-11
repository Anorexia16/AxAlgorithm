// 1099 Build A Binary Search Tree

#ifndef PAT_1099_HPP
#define PAT_1099_HPP

#include <cstdio>

struct node{
    int left;
    int right;
    int nv;
};

int main()
{
    node tree[100];
    int stack[100];
    int queue[100];
    int value[100];
    int num, si=0, qb=0, qn=0;

    scanf("%d", &num);
    for(int i=0;i!=num;++i)
        scanf("%d %d", &(tree[i].left), &(tree[i].right));
    for(int i=0;i!=num;++i)
        scanf("%d", value+i);

    int bi=0;
    for(;tree[bi].left!=-1;bi=tree[bi].left) {
        stack[si] = bi;
        ++si;
    }

    int _extra;
    size_t pos;

    for (size_t times=0; times!=num; ++times)
    {
        _extra = value[times];
        pos = times;
        for (size_t i=times; i!=num; ++i)
        {
            if (value[i] < _extra)
            {
                _extra = value[i];
                pos = i;
            }
        }
        if (pos != times)
        {
            for (size_t re_pos=pos; re_pos!=times; --re_pos)
                value[re_pos] = value[re_pos-1];
            value[times] = _extra;
        }
    }


    for(int i=0;i!=num;++i)
    {
        tree[bi].nv = value[i];
        if(tree[bi].right!=-1) {
            bi=tree[bi].right;
            for(;tree[bi].left!=-1;bi=tree[bi].left) {
                stack[si] = bi;
                ++si;
            }
        } else {
            bi = stack[si-1];
            --si;
        }
    }

    if (num>1)
        printf("%d ", tree[0].nv);
    else
        printf("%d", tree[0].nv);
    if(tree[0].left!=-1) {
        queue[qn] = tree[0].left;
        ++qn;
    }
    if(tree[0].right!=-1) {
        queue[qn] = tree[0].right;
        ++qn;
    }

    for(int i=0;i<num-1;++i, printf(i==num-1?"": " "))
    {
        printf("%d", tree[queue[qb]].nv);
        if(tree[queue[qb]].left!=-1) {
            queue[qn] = tree[queue[qb]].left;
            ++qn;
        }
        if(tree[queue[qb]].right!=-1) {
            queue[qn] = tree[queue[qb]].right;
            ++qn;
        }
        ++qb;
    }

    return 0;
}


#endif //PAT_1099_HPP
