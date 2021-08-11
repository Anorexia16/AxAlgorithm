//1078 字符串压缩与解压

#ifndef PAT_1078_HPP
#define PAT_1078_HPP

#include <iostream>
int main() {
    char t, c;
    scanf("%c\n", &t);
    std::string s, num;
    getline(std::cin, s);
    int n = 1;
    if (t == 'D') {
        for (char i : s) {
            if (i >= '0' && i <= '9') {
                num.append(1, i);
            } else {
                if (!num.empty()) n = stoi(num);
                while(n--) printf("%c", i);
                n = 1, num = "";
            }
        }
    } else if (s.length() != 0) {
        c = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == c) ++n;
            else {
                if (n >= 2) std::cout << n;
                std::cout << c;
                n = 1;
                c = s[i];
            }
        }
        if (n >= 2) std::cout << n;
        std::cout << c;
    }
    return 0;
}

#endif //PAT_1078_HPP
