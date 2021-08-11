//1033 To Fill or Not to Fill

#ifndef PAT_1033_HPP
#define PAT_1033_HPP

#include <cstdio>
#include <algorithm>

inline int read() {
    int x{}; char c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9') {x=10*x+c-'0';c=getchar();}
    return x;
}

struct sta{double p,d;}a[505];
bool cmp(sta x,sta y){
    return x.d<y.d;
}
double cm,dist,davg;
int n;

int main(){
    cm=read(),dist=read(),davg=read(),n=read();
    for(int i=1;i<=n;i++) scanf("%lf%lf", &(*(a+i)).p,
                                &(*(a+i)).d);
    std::sort(a+1,a+1+n,cmp);
    int k=1;
    double m_range = cm*davg;
    double max_d=0;
    double min_p=0;
    if(a[1].d!=0){
        printf("The maximum travel distance = %.2f",max_d);
        return 0;
    }
    int can_get,nk;
    double kd,kp,cheapest;
    double oil=0;
    while(1){
        can_get=0;
        kd=a[k].d;
        kp=a[k].p;
        nk=-1;
        cheapest=999999;
        if(kd+m_range>=dist){
            can_get=1;
        }
        int cheap=0;
        for(int i=k+1;i<=n;i++){
            if(a[i].d>kd+m_range || a[i].d>=dist){
                break;
            }
            if(a[i].p<kp){
                nk=i;
                cheap=1;
                break;
            }
            if(!can_get&&a[i].p<cheapest){
                cheapest=a[i].p;
                nk=i;
            }
        }
        if(nk==-1){
            if(can_get){
                if(oil<(dist-kd)/davg){
                    min_p += kp*((dist-kd)/davg-oil);
                }
                printf("%.2f",min_p);
            }else{
                max_d=kd+m_range;
                printf("The maximum travel distance = %.2f",max_d);
            }
            break;
        }
        if(!cheap){
            if(oil<cm){
                min_p += kp*(cm-oil);
                oil=cm;
            }
            oil-=(a[nk].d-kd)/davg;

        }else{
            if((oil<a[nk].d-kd)/davg){
                min_p += kp*((a[nk].d-kd)/davg-oil);
                oil=(a[nk].d-kd)/davg;
            }
            oil-=(a[nk].d-kd)/davg;
        }
        k=nk;
    }
    return 0;
}

#endif //PAT_1033_HPP
