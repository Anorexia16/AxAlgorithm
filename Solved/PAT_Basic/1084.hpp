//1084 外观数列

#ifndef PAT_1084_HPP
#define PAT_1084_HPP

#include <string>
#include <iostream>

int main() {
    std::string str, tp;
    int n, j;
    std::cin >> str >> n;
    for(int t=1;t!=n;++t) {
        tp.clear();
        for(int i=0;i<str.size();i=j) {
            for(j=i;j<str.size()&&str[i]==str[j];++j);
            tp.append(str[i]+std::to_string(j-i));
        }
        str = tp;
    }
    std::cout << str << std::endl;
    return 0;
}

#endif //PAT_1084_HPP
