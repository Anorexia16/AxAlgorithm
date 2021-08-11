// 1007 Maximum Subsequence Sum

#ifndef PAT_1007_HPP
#define PAT_1007_HPP

#include <cstdio>

int main() {
    int arr[10000];
    int pls[10000];
    int dev[10000];
    int pre[10000];
    int size;
    bool neg = true;
    scanf("%d", &size);
    for (int i=0; i!=size; ++i)
    {
        scanf("%d", arr+i);
        if (arr[i] >= 0) neg = false;
    }
    pls[0] = arr[0];
    for (int i=1; i!=size; ++i) pls[i] = arr[i] + pls[i-1];

    int min = 0;
    int mi = -1;
    for(int i=0; i!=size;++i)
    {
        pre[i] = mi;
        dev[i] = pls[i] - min;
        if (pls[i]<min)
        {
            min = pls[i];
            mi = i;
        }
    }
    int mai = 0;
    for (int i=0; i!=size; ++i)
    {
        if (dev[i]>dev[mai])
        {
            mai = i;
        }
    }
    if (!neg) printf("%d %d %d", dev[mai], arr[pre[mai] + 1], arr[mai]);
    else printf("%d %d %d", 0, arr[0], arr[size - 1]);

}

#endif //PAT_1007_HPP
