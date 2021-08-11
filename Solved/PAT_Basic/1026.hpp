//1026 程序运行时间

#ifndef PAT_1026_HPP
#define PAT_1026_HPP

#include<iostream>

int main() {
    int begin, var, s, m, h;
    std::cin >> begin >> var;
    var = (var-begin+50)/100;
    h = var/3600;
    m = (var%3600)/60;
    s = var%60;
    printf("%02d:%02d:%02d\n", h, m ,s);
}

#endif //PAT_1026_HPP
