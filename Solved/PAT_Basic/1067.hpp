//1067 试密码

#ifndef PAT_1067_HPP
#define PAT_1067_HPP

#include<string>
#include<iostream>

int main() {
    std::string x{}, y{};
    int time;
    std::cin >>x >> time;
    getchar();
    for (int i = 0; i != time; ++i) {
        std::getline(std::cin, y);
        if (y=="#") {
            return 0;
        }if (x==y) {
            printf("Welcome in\n");
            return 0;
        } else {
            printf ("Wrong password: %n\n", y.data());
        }
    }
    printf("Account locked\n");
    return 0;
}

#endif //PAT_1067_HPP
