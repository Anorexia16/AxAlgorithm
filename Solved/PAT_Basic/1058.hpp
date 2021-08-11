//1058 选择题

#ifndef PAT_1058_HPP
#define PAT_1058_HPP

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

struct grade {
    int id, sc;
    bool operator<(grade const &op) const {
        if(sc!=op.sc) return sc>op.sc;
        else return id<op.id;
    }
};

int main() {
    std::map<int, int> mp{};
    int stu, ti, tp, t2;
    char c;
    scanf("%d%d", &stu, &ti);
    int ful[ti], x[ti], n[ti], sc[stu];
    for(int i=0;i!=stu;++i) sc[i]=0;
    for(int i=0;i!=ti;++i) x[i]=0;
    for(int i=0;i!=ti;++i) {
        scanf("%d%d%d", ful+i, &t2, n+i);
        for(int j=0;j!=n[i];++j) {
            scanf(" %c", &c);
            x[i] += 1<<(c-'a');
        }
    }
    for(int i=0;i!=stu;++i) {
        scanf("\n");
        for(int j=0;j!=ti;++j) {
            if (j!=0) scanf(" ");
            scanf("(%d", &t2);
            tp=0;
            for(int k=0;k!=t2;++k) {
                scanf(" %c", &c);
                tp+= 1<<(c-'a');
            }
            if (tp==x[j]) {
                sc[i]+=ful[j];
            } else {
                ++mp[j];
            }
            scanf(")");
        }
    }
    for(int i=0;i!=stu;++i) {
        printf("%d\n", sc[i]);
    }
    if (mp.empty()) {
        printf("Too simple\n");
        return 0;
    }
    std::vector<grade> res;
    res.reserve(mp.size());
    for(auto const&iter: mp) {
        res.emplace_back(grade{iter.first, iter.second});
    }
    std::sort(res.begin(), res.end());
    t2 = res[0].sc;
    printf("%d", t2);
    for(auto const &iter:res) {
        if (iter.sc!=t2) {
            break;
        } else {
            printf(" %d", iter.id+1);
        }
    }
    printf("\n");
    return 0;
}


#endif //PAT_1058_HPP
