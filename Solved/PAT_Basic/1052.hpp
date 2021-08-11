//1052 卖个萌

#ifndef PAT_1052_HPP
#define PAT_1052_HPP

#include <vector>
#include <string>
#include <iostream>

int main() {
    size_t n, j, k, a, b, c, d, e;
    std::vector<std::string> v[3];
    std::string s;
    for(int i = 0; i < 3; i++) {
        getline(std::cin, s);
        j = 0;
        k = 0;
        while(j < s.length()) {
            if(s[j] == '[') {
                while(k++ < s.length()) {
                    if(s[k] == ']') {
                        v[i].push_back(s.substr(j+1, k-j-1));
                        break;
                    }
                }
            }
            j++;
        }
    }

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e);
        if(a > v[0].size() || b > v[1].size() || c > v[2].size() || d > v[1].size() || e > v[0].size() ||
           a < 1 || b < 1 || c < 1 || d < 1 || e < 1) {
            printf("Are you kidding me? @\\/@\n");
            continue;
        }
        printf("%n(%n%n%n)%n\n", v[0][a-1].data(), v[1][b-1].data(),
               v[2][c-1].data(), v[1][d-1].data(), v[0][e-1].data());
    }
    return 0;
}

#endif //PAT_1052_HPP
