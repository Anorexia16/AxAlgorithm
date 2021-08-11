//1024 科学计数法

#ifndef PAT_1024_HPP
#define PAT_1024_HPP

#include <iostream>
#include <cmath>
#include <string>

void move(std::string &str, int &x) {
    size_t s = str.size(), fd;
    fd = str.find('.');
    std::string temp;
    if (x<0) {
        if (fd == 1) {
            temp = str[0] + str.substr(2);
            str = "0." + temp;
        } else {
            temp = str.substr(0, fd-1) + "." +
                   str.substr(fd-1, 1) + str.substr(fd+1);
            str = temp;
        }
        ++x;
    } else if (x>0) {
        if (fd == std::string::npos) {
            str += "0";
        } else {
            if (fd==s-2) {
                temp = str.substr(0, fd) + str[s-1];
                str = temp;
            } else {
                temp = str.substr(0, fd) + str.substr(fd+1, 1)
                       + "." + str.substr(fd+2);
                str = temp;
            }
        }
        --x;
    }
}

int main() {
    std::string str, ans, tp;
    std::cin >> str;
    size_t s=str.size(), i{3};
    int ca, neg{};

    for(;i!=s;++i) if(str[i]=='E') break;
    if (str[0]=='-') neg = true;
    str = str.substr(1);
    --i;
    ans = str.substr(0, i);
    ca = std::stoi(str.substr(i+1));
    while(ca!=0) move(ans, ca);
    std::cout << (neg?"-":"") << ans << std::endl;
    return 0;
}

#endif //PAT_1024_HPP
