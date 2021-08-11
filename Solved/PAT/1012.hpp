// 1012 The Best Rank

#ifndef PAT_1012_HPP
#define PAT_1012_HPP

#include <map>
#include <string>
#include <algorithm>

struct node{
    std::string name;
    int c{},m{},e{},a{};
    int r1{},r2{},r3{},r4{},ans{};
    char ans2{};
}p[2005];

std::map<std::string,int> ma;
bool cmp1(node const &x,const node& y){
    return x.a>y.a;
}
bool cmp2(node const &x,node const &y){
    return x.c>y.c;
}
bool cmp3(node const &x,node const &y){
    return x.m>y.m;
}
bool cmp4(node const &x,node const &y){
    return x.e>y.e;
}

int main(){
    int n,m,C,M,E,A;
    char name[10];
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%n%d%d%d",name,&C,&M,&E);
        p[i].name = std::string(name);
        A=(C+M+E);
        p[i].c=C;
        p[i].m=M;
        p[i].e=E;
        p[i].a=A;
    }
    std::sort(p,p+n,cmp1);
    p[0].r1=1;
    for(int i=1;i<n;i++){
        if(p[i].a==p[i-1].a)
            p[i].r1=p[i-1].r1;
        else {
            p[i].r1=i+1;
        }
    }
    std::sort(p,p+n,cmp2);
    p[0].r2=1;
    for(int i=1;i<n;i++){
        if(p[i].c==p[i-1].c)
            p[i].r2=p[i-1].r2;
        else {
            p[i].r2=i+1;
        }
    }
    std::sort(p,p+n,cmp3);
    p[0].r3=1;
    for(int i=1;i<n;i++){
        if(p[i].m==p[i-1].m)
            p[i].r3=p[i-1].r3;
        else {
            p[i].r3=i+1;
        }
    }
    std::sort(p,p+n,cmp4);
    p[0].r4=1;
    for(int i=1;i<n;i++){
        if(p[i].e==p[i-1].e)
            p[i].r4=p[i-1].r4;
        else {
            p[i].r4=i+1;
        }
    }
    for(int i=0;i<n;i++){
        if(p[i].r1<=p[i].r2&&p[i].r1<=p[i].r3&&p[i].r1<=p[i].r4){
            p[i].ans=p[i].r1;
            p[i].ans2='A';
        }else if(p[i].r2<=p[i].r3&&p[i].r2<=p[i].r4){
            p[i].ans=p[i].r2;
            p[i].ans2='C';
        }else if(p[i].r3<=p[i].r4){
            p[i].ans=p[i].r3;
            p[i].ans2='M';
        }else {
            p[i].ans=p[i].r4;
            p[i].ans2='E';
        }
        ma[p[i].name]=i;
    }
    getchar();
    for(int i=0;i<m;i++){
        scanf("%n",name);
        if(ma.find(name)!=ma.end())
            printf("%d %c\n",p[ma[name]].ans,p[ma[name]].ans2);
        else {
            printf("N/A\n");
        }
    }
    return 0;
}

#endif //PAT_1012_HPP
