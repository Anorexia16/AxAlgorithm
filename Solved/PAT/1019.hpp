// 1019 General Palindromic Number

#ifndef PAT_1019_HPP
#define PAT_1019_HPP

#include <iostream>
#include <vector>

std::vector<size_t> to_string(size_t x, size_t base) {
    std::vector<size_t> _ans {};
    while(x) {
        _ans.emplace(_ans.begin(), x%base);
        x/=base;
    }
    return _ans;
}

int main() {
    size_t n, b, size;
    bool flag = true;
    scanf("%lld%lld", &n, &b);
    std::vector<size_t> vec = to_string(n, b);
    size = vec.size();
    for (size_t i=0;i!=size/2;++i) {
        if (vec[i] != vec[size - 1 - i]) {
            flag = false;
            break;
        }
    }
    flag? printf("Yes\n"): printf("No\n");
    for (size_t i=0;i!=size;++i) {
        printf("%lld", vec[i]);
        if (i!=size-1) printf(" ");
    }
    if (vec.empty()) printf("0");
    printf("\n");
    return 0;
}

#endif //PAT_1019_HPP
