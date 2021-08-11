//1073 多选题常见计分法

#ifndef PAT_1073_HPP
#define PAT_1073_HPP

#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct s {
    int times, index;
    bool operator<(n const &op) const {
        return times!=op.times?times>op.times:index<op.index;
    }
};

int main() {
    int stu, ti, tp, t2, t3, t4, flag;
    map<int, int> times{};
    vector<n> vec{};
    scanf("%d%d", &stu, &ti);
    int ful[stu], ans[ti];
    char c;
    double sc[stu];
    for(int i=0;i!=ti;++i) {
        scanf("%d", ful+i);
        scanf("%d%d", &t2, &tp);
        ans[i]=0;
        for(int j=0;j!=tp;++j) {
            getchar();
            scanf("%c", &c);
            ans[i]+=(1<<(c-'a'));
        }
    }
    for(int i=0;i!=stu;++i) {
        for(int j=0;j!=ti;++j) {
            t2 = 0;
            getchar();
            scanf("(%d ", &t3);
            for(int k=0;k!=t3;++k) {
                scanf("%c", &c);
                getchar();
                t2 += 1<<(c-'a');
            }
            flag = 0;
            for(int k=0;k!=5;++k) {
                t3=(ans[j]/(1<<k))%2, t4=(t2/(1<<k))%2;
                if (t3!=t4&&t3==0) {
                    flag = 2;
                    ++times[5*j+k];
                } else if (t3!=t4&&t4==0) {
                    flag = flag==2?2:1;
                    ++times[5*j+k];
                }
            }
            switch (flag) {
                case 0:
                    sc[i]+=ful[j];
                    break;
                case 1:
                    sc[i]+=ful[j]*0.5;
                    break;
                default:
                    break;
            }
        }
    }
    for(int i=0;i!=stu;++i) printf("%.1f\n", sc[i]);
    if (!times.empty()) {
        vec.reserve(times.size());
        for(auto const &iter:times) {
            vec.emplace_back(n{iter.second, iter.first});
        }
        sort(vec.begin(), vec.end());
        t2 = vec.front().times;
        for(auto const &iter:vec) {
            if (iter.times!=t2) {
                break;
            } else {
                printf("%d %d-%c\n", t2,
                       iter.index/5+1, 'a'+(iter.index%5));
            }
        }
    } else {
        printf("Too simple\n");
    }
    return 0;
}

#endif //PAT_1073_HPP
