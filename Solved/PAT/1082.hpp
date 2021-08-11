// 1082 Read Number in Chinese

#ifndef PAT_1082_HPP
#define PAT_1082_HPP

#include <map>
#include <string>
#include <vector>
#include <iostream>

int main() {
    std::vector<std::string> res;
    std::map<char, std::string> trans;
    std::string str;
    bool zero = true, cont;
    trans['1'] = "yi";
    trans['2'] = "er";
    trans['3'] = "san";
    trans['4'] = "si";
    trans['5'] = "wu";
    trans['6'] = "liu";
    trans['7'] = "qi";
    trans['8'] = "ba";
    trans['9'] = "jiu";
    std::cin >> str;
    if (str[0] == '-') {
        res.emplace_back("Fu");
        str = str.substr(1);
    }
    str = std::string(9-str.size(), '0') + str;
    if (str[0]!='0') {
        zero = false;
        res.emplace_back(trans[str[0]]);
    }
    if (!zero) res.emplace_back("Yi");
    for (size_t i=1;i!=5;++i) {
        if (str[i]!='0') {
            if (!zero&&cont) {
                res.emplace_back("ling");
            }
            res.emplace_back(trans[str[i]]);
            switch (i) {
                case 1:
                    res.emplace_back("Qian");
                    break;
                case 2:
                    res.emplace_back("Bai");
                    break;
                case 3:
                    res.emplace_back("Shi");
                    break;
                default:
                    break;
            }
            zero = false;
            cont = false;
        } else cont = true;
    }
    if (!zero) res.emplace_back("Wan");
    for (size_t i=5;i!=9;++i) {
        if (str[i]!='0') {
            if (!zero&&cont) {
                res.emplace_back("ling");
            }
            res.emplace_back(trans[str[i]]);
            switch (i) {
                case 5:
                    res.emplace_back("Qian");
                    break;
                case 6:
                    res.emplace_back("Bai");
                    break;
                case 7:
                    res.emplace_back("Shi");
                    break;
                default:
                    break;
            }
            zero = false;
            cont = false;
        } else cont = true;
    }
    if (zero) res.emplace_back("ling");
    for (size_t i=0;i!=res.size();++i) {
        std::cout << res[i];
        i==res.size()-1? printf("\n"): printf(" ");
    }
    return 0;
}

#endif //PAT_1082_HPP
