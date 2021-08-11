//1028 人口普查

#ifndef PAT_1028_HPP
#define PAT_1028_HPP

#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct p {
    string str;
    int y, m, d;
};

bool large(p const &a, p const &b) {
    if (a.y!=b.y) {
        return a.y>b.y;
    } else if (a.m!=b.m) {
        return a.m>b.m;
    } else return a.d>b.d;
}

bool valid(p const &op) {
    return !(large(p{"", 1814, 9, 6}, op)|| large(op, p{"", 2014, 9, 6}));
}

int main() {
    int n, si{};
    scanf("%d", &n);
    p arr[n];
    for(int i=0;i!=n;++i) {
        std::cin >> arr[si].str;
        scanf("%d/%d/%d", &arr[si].y, &arr[si].m, &arr[si].d);
        if (valid(arr[si])) {
            ++si;
        }
    }
    sort(arr, arr+si, large);
    if (si!=0) {
        printf("%d %n %n\n", si, arr[si - 1].str.data(), arr[0].str.data());
    } else {
        printf("0\n");
    }
    return 0;
}

#endif //PAT_1028_HPP
