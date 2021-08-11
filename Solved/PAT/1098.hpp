//1098 Insertion or Heap Sort

#ifndef PAT_1098_HPP
#define PAT_1098_HPP

#include <cstdio>
#include <algorithm>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c= getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

int main() {
    int n=read(), hi=n, d, tp;
    int arr[n], heap[n], ans[n];
    for(int i=0;i!=n;++i) {arr[i]=read();heap[i]=arr[i];}
    std::make_heap(heap, heap+hi);
    for(int i=0;i!=n;++i) ans[i]=read();
    for(int i=0;i!=n;++i) {
        std::pop_heap(heap, heap+(hi--));d=1;
        for(int j=0;j!=n;++j) {
            if(heap[j]!=ans[j]) {d=0;break;}
        }
        if(d) {
            printf("Heap Sort\n");
            std::pop_heap(heap, heap+hi);
            for(int k=0;k!=n;++k) {
                printf("%d", heap[k]);
                k==n-1?putchar('\n'):putchar(' ');
            }
            return 0;
        }
        tp = arr[i];
        d = std::lower_bound(arr, arr+i+1, tp)-arr;
        for(int j=i;j!=d;--j) {
            arr[j]=arr[j-1];
        }
        arr[d]=tp;d=1;
        for(int j=0;j!=n;++j) {
            if(arr[j]!=ans[j]) {d=0;break;}
        }
        if(d&&i!=0) {
            printf("Insertion Sort\n");
            if (i<n-1) {
                tp=arr[i+1];
                d = std::lower_bound(arr, arr+i+1, tp)-arr;
                for(int j=i+1;j!=d;--j) {
                    arr[j]=arr[j-1];
                }
                arr[d]=tp;
            }
            for(int k=0;k!=n;++k) {
                printf("%d", arr[k]);
                k==n-1?putchar('\n'):putchar(' ');
            }
            return 0;
        }
    }
    return 0;
}


#endif //PAT_1098_HPP
