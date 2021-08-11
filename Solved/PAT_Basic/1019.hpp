//1019 数字黑洞

#ifndef PAT_1019_HPP
#define PAT_1019_HPP

#include<vector>
#include<algorithm>
#include<iostream>

std::vector<int> max(std::vector<int> x) {
    std::sort(x.rbegin(), x.rend());
    return x;
}

int extract(std::vector<int> x) {
    int res{};
    while(!x.empty()) {
        res*=10;
        res+=x.front();
        x.erase(x.begin());
    }
    return res;
}

std::vector<int> form(int x) {
    std::vector<int> res{};
    while(x!=0) {
        res.emplace_back(x%10);
        x/=10;
    }
    return res;
}

std::vector<int> min(std::vector<int> x) {
    std::sort(x.begin(), x.end());
    return x;
}

int main() {
    std::vector<int> ma{}, mi{};
    int m;
    scanf("%d", &m);
    mi = form(m);
    while(true) {
        ma = max(mi);
        mi = min(mi);
        m = extract(ma) - extract(mi);
        printf("%04d - %04d = %04d\n", extract(ma), extract(mi), m);
        if (m==6174||m==0) {
            break;
        } else {
            ma = max(form(m));
            mi = min(form(m));
        }
    }
    return 0;
}


#endif //PAT_1019_HPP
