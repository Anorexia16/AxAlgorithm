//1078 Hashing

#ifndef PAT_1078_HPP
#define PAT_1078_HPP

#include<cstdio>

inline int read() {
    int x{}, c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

bool prime(int x) {
    if(x==0||x==1) return false;
    for(int j=2;j*j<=x;++j) {
        if(x%j==0) return false;
    }
    return true;
}

int rit (int x) {
    while(!prime(x)) ++x;
    return x;
}

int main() {
    int len=rit(read()), n=read(), tb[len], tp;
    bool trv[len], in;
    for(int i=0;i!=len;++i) trv[i]=false;
    while(n--) {
        tp=read();in=false;
        for(int i=0;i!=len;++i) {
            if(!trv[(tp+i*i)%len]||(trv[(tp+i*i)%len]&&tb[(tp+i*i)%len]==tp)) {
                in=true;tb[(tp+i*i)%len]=tp;trv[(tp+i*i)%len]=true;printf("%d", (tp+i*i)%len);break;
            }
        }
        if(!in)putchar('-');
        if(n!=0) putchar(' ');
    }
    putchar('\n');
    return 0;
}

#endif //PAT_1078_HPP
