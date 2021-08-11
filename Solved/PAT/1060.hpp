// 1066 Are They Equal

#ifndef PAT_1060_HPP
#define PAT_1060_HPP

#include<iostream>
#include<string>

size_t getExp(std::string s){
    int common = -1;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '.') {
            common = i;
            break;
        }
    }
    int isNum = -1;
    for (int i = 0; i < s.length(); i++){
        if (s[i]>'0' && s[i] <= '9'){
            isNum = i;
            break;
        }
    }
    if (isNum == -1) return 0;
    if (common == -1 && isNum != 0) return 1;
    if (common == -1) return s.length();
    int ans = common - isNum;
    if (ans >= 0) return ans;
    return ans + 1;
}


std::string getUse(std::string const &s, int n){
    int sss = n;
    std::string temp;
    int i = 0;
    for (; i < s.length() && (s[i] == '0' || s[i] == '.'); i++);
    for (; i < s.length() && n; i++){
        if (s[i] != '.'){ temp += s[i]; n--; }
    }
    if (temp.empty()) temp = "0";
    temp = "0." + temp;
    while (temp.length() <= sss+1) temp += "0";
    return temp;
}

struct num {
    std::string use;
    size_t exp{};
    void init(std::string const &s, int n){
        this->use = getUse(s, n);
        this->exp = getExp(s);
    }
    void printf() const{
        std::cout << use << "*10^" << exp;
    }
};

int main(){
    std::string s1,s2;
    num t1, t2;
    int n;
    std::cin >> n >> s1 >> s2;
    t1.init(s1,n);
    t2.init(s2,n);
    if (t1.exp == t2.exp && t1.use == t2.use){
        std::cout << "YES ";
        t1.printf();
        std::cout << std::endl;
    }
    else{
        std::cout << "NO ";
        t1.printf();
        std::cout << " ";
        t2.printf();
        std::cout << std::endl;
    }
}

#endif //PAT_1060_HPP
