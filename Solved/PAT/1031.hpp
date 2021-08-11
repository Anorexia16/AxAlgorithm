// 1031 Hello World for U

#ifndef PAT_1031_HPP
#define PAT_1031_HPP

#include<iostream>
#include<string>

int main() {
    std::string str;
    std::cin >> str;
    size_t length = str.size(), ud = (str.size()+2)/3-1;
    for (size_t i=0;i!=(length+2)/3-1;++i) {
        printf("%c", str[i]);
        for (size_t j=0; j!= length - 2*ud-2;++j) printf(" ");
        printf("%c\n", str[length-1-i]);
    }
    for (size_t i=ud;i!=length-ud;++i) {
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}

#endif //PAT_1031_HPP
