// 1038 Recover the Smallest Number

#ifndef PAT_1038_HPP
#define PAT_1038_HPP

#include<string>
#include<iostream>
#include<algorithm>

inline std::string pure(std::string const &s) {
    int x{};
    for (;s[x]=='0';++x);
    return s.substr(x);
}

bool is_pure(std::string const &s) {
    for (size_t i=0;i!=s.size();++i) if (s[i]!='0') return false;
    return true;
}

bool cmp (std::string const &a, std::string const &b) {
    return a+b<b+a;
}

int main() {
    int N, flag=0;
    std::string nums[10000];
    scanf("%d", &N);
    for(int i=0;i!=N;++i) {
        std::cin >> nums[i];
    }
    std::sort(nums, nums+N, cmp);
    for(int i=0;i!=N;++i) {
        flag? std::cout<<nums[i]:std::cout<<pure(nums[i]);
        if (!is_pure(nums[i])) flag=1;
    }
    if (!flag) printf("0");
    printf("\n");
    return 0;
}

#endif //PAT_1038_HPP
