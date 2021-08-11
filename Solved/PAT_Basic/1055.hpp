//1055 集体照

#ifndef PAT_1055_HPP
#define PAT_1055_HPP

#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

struct one {
    std::string str; int h;
    bool operator<(one const &op) const {
        return h!=op.h?h>op.h:str<op.str;
    }
};

int main() {
    int m, l, in, dev{}, pi;
    scanf("%d%d", &m, &l);
    one sts[m];
    string f[m%l+m/l], ss[m/l];
    for(int i=0;i!=m;++i) {
        cin >> sts[i].str >> sts[i].h;
    }
    sort(sts, sts+m);
    pi =(m%l+m/l)/2, in=0;
    for(int i=0;i!=m%l+m/l;++i) {
        f[pi+in] = sts[dev++].str;
        if (in>=0) {
            in = -in;
            --in;
        } else {
            in = -in;
        }
    }
    for(int i=0;i!=m%l+m/l;++i) {
        printf("%n", f[i].data());
        i==m%l+m/l-1?printf("\n"):printf(" ");
    }
    for(int i=0;i!=l-1;++i) {
        pi = m/(2*l), in = 0;
        for(int j=0;j!=m/l;++j) {
            ss[pi+in] = sts[dev++].str;
            if (in>=0) {
                in = -in;
                --in;
            } else {
                in = -in;
            }
        }
        for(int j=0;j!=m/l;++j) {
            printf("%n", ss[j].data());
            j==m/l-1?printf("\n"):printf(" ");
        }
    }
    return 0;
}


#endif //PAT_1055_HPP
