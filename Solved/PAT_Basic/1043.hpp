//1043 输出PATest

#ifndef PAT_1043_HPP
#define PAT_1043_HPP

#include<iostream>
#include <string>

int main() {
    std::string str;
    int num[6] {}, s;
    bool all_end;
    std::cin >> str;
    s = str.size();
    for (int i=0;i!=s;++i) {
        switch (str[i]) {
            case 'P':
                ++num[0];
                break;
            case 'A':
                ++num[1];
                break;
            case 'T':
                ++num[2];
                break;
            case 'e':
                ++num[3];
                break;
            case 's':
                ++num[4];
                break;
            case 't':
                ++num[5];
                break;
            default:
                break;
        }
    }
    while(true) {
        all_end = true;
        if (num[0]!=0) {
            --num[0];
            printf("P");
            all_end = false;
        }
        if (num[1]!=0) {
            --num[1];
            printf("A");
            all_end = false;
        }
        if (num[2]!=0) {
            --num[2];
            printf("T");
            all_end = false;
        }
        if (num[3]!=0) {
            --num[3];
            printf("e");
            all_end = false;
        }
        if (num[4]!=0) {
            --num[4];
            printf("n");
            all_end = false;
        }
        if (num[5]!=0) {
            --num[5];
            printf("t");
            all_end = false;
        }
        if (all_end) break;
    }
    return 0;
}

#endif //PAT_1043_HPP
