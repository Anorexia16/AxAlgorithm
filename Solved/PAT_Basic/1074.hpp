//1074 宇宙无敌加法器

#ifndef PAT_1074_HPP
#define PAT_1074_HPP

#include <iostream>
#include <string>

int main() {
    std::string s, s1, s2, ans;
    int carry = 0, flag = 0;
    std::cin >> s >> s1 >> s2;
    ans = s;
    std::string ss1(s.length() - s1.length(), '0');
    s1 = ss1 + s1;
    std::string ss2(s.length() - s2.length(), '0');
    s2 = ss2 + s2;
    for(int i = s.length() - 1; i >= 0; i--) {
        int mod = s[i] == '0' ? 10 : (s[i] - '0');
        ans[i] = (s1[i] - '0' + s2[i] - '0' + carry) % mod + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / mod;
    }
    if (carry != 0) ans = '1' + ans;
    for(int i = 0; i < ans.size(); i++) {
        if (ans[i] != '0' || flag == 1) {
            flag = 1;
            std::cout << ans[i];
        }
    }
    if (flag == 0) std::cout << 0;
    std::cout << std::endl;
    return 0;
}

#endif //PAT_1074_HPP
