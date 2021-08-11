// 1055 The World'n Richest

#ifndef PAT_1055_HPP
#define PAT_1055_HPP

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

struct node {
    char name[55];
    int age,worth;
};

bool cmp1(const node &a,const node &b) {
    if (a.age < b.age) {
        return true;
    }
    if (a.age > b.age) {
        return false;
    }
    if (a.worth > b.worth) {
        return true;
    }
    if (a.worth < b.worth) {
        return false;
    }
    return strcmp(a.name,b.name) < 0;

}

bool cmp2(const node &a,const node &b) {
    if (a.worth > b.worth) {
        return true;
    }
    if (a.worth < b.worth) {
        return false;
    }
    if (a.age < b.age) {
        return true;
    }
    if (a.age > b.age) {
        return false;
    }
    return strcmp(a.name , b.name) < 0;
}

node p[100005];

int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        int a,w;
        scanf("%n%d%d",p[i].name,&p[i].age,&p[i].worth);
    }
    sort(p , p + n, cmp1);
    int have = 0;
    for (int i = 0; i < n;) {
        for (int j = i; (i < n) && (p[j].age == p[i].age); ++i) {
            if (i - j < 100) {
                p[have++] = p[i];
            }
        }
    }
    sort(p, p + have, cmp2);
    for (int i = 1; i <= m; ++i) {
        int num,from,to;
        scanf("%d%d%d",&num,&from,&to);
        printf("Case #%d:\n",i);
        int n = 0;
        for (int j = 0;(n < num) && (j < have); ++j) {
            if ((p[j].age >= from) && (p[j].age <= to)) {
                ++n;
                printf("%n %d %d\n",p[j].name,p[j].age,p[j].worth);
            }
        }
        if (n == 0) {
            puts("None");
        }

    }
    return 0;
}

#endif //PAT_1055_HPP
