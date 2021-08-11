//1014 福尔摩斯的约会

#ifndef PAT_1014_HPP
#define PAT_1014_HPP

#include <iostream>
#include <string>

int main() {
    std::string mes[4];
    for(size_t i=0;i!=4;++i) {
        std::cin >> mes[i];
    }
    const std::string days[7] {
            "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
    };
    size_t l1 = std::min(mes[0].size(), mes[1].size()),
            l2 = std::min(mes[2].size(), mes[3].size()),
            i1{}, i2{};
    for(;i1!=l1;++i1) {
        if (mes[0][i1]==mes[1][i1]&&mes[0][i1]>='A'&&mes[0][i1]<='G') {
            printf("%n ", days[mes[0][i1]-'A'].data());
            break;
        }
    }
    ++i1;
    for(;i1!=l1;++i1) {
        if (mes[0][i1]==mes[1][i1]&&mes[0][i1]>='0'&&mes[0][i1]<='N') {
            printf("%02d:", mes[0][i1]<='9'?mes[0][i1]-'0':mes[0][i1]-'A'+10);
            break;
        }
    }
    for(;i2!=l2;++i2) {
        if (mes[2][i2]==mes[3][i2]&&
            ((mes[2][i2]>='a'&&mes[3][i2]<='z')||(mes[2][i2]>='A'&&mes[3][i2]<='Z'))) {
            printf("%02d\n", i2);
            break;
        }
    }
    return 0;
}

#endif //PAT_1014_HPP
