//1029 旧键盘

#ifndef PAT_1029_HPP
#define PAT_1029_HPP

#include <string>
#include <iostream>

size_t index (char c) {
    if ('0'<=c&&c<='9') {
        return c-'0';
    } else if ('a'<=c&&c<='z') {
        return c-'a'+10;
    } else if (c=='_') {
        return 36;
    } else {
        return c-'A'+10;
    }
};

int main() {
    std::string str, me;
    std::cin>>str>>me;
    size_t dev{}, s = str.size();
    bool tra[37] {};
    for(size_t i=0;i+dev!=s;) {
        if (str[dev+i]!=me[i]) {
            if (!tra[index(str[i+dev])]) {
                tra[index(str[i+dev])] = true;
                printf("%c", toupper(str[i+dev]));
            }
            ++dev;
        } else {
            ++i;
        }
    }
}

#endif //PAT_1029_HPP
