// 1121 Damn Single

#ifndef PAT_1121_HPP
#define PAT_1121_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main() {
    unsigned int cp[100000];
    for(int i=0;i<100000;i++)cp[i]=-1;
    int N;cin>>N;
    int a,b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        cp[a]=b;
        cp[b]=a;
    }
    int M;cin>>M;
    set<int> guests;
    for(int i=0;i<M;i++){
        cin>>a;
        guests.insert(a);
    }
    set<int> ans;
    for(auto g:guests){
        if(cp[g]==-1){
            ans.insert(g);
        }else if(guests.find(cp[g])==guests.end()){
            ans.insert(g);
        }
    }
    printf("%d\n",ans.size());
    bool flag=true;
    for(auto g:ans){
        if(flag)flag=false;
        else printf(" ");
        printf("%05d",g);
    }
}

#endif //PAT_1121_HPP
