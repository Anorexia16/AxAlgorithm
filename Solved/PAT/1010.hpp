//1010 Radix

#ifndef PAT_1010_HPP
#define PAT_1010_HPP

#include <unordered_map>
#include <iostream>

std::unordered_map<char, int> mp;
typedef long long lg;

lg trans (std::string const &str, lg const &r) {
    lg res{};for(auto const &i:str) res=res*r+mp[i];
    return res;
}

lg radix_td(std::string const &str1, std::string const &str2, lg radix) {
    lg right = trans(str1, radix), left = -1, t = right;
    for(auto const &i : str2) left = std::max(left, (lg)mp[i]+1);
    while(left < right) {
        lg mid = left + (right - left)/2, k = trans(str2, mid);
        if(k < 0 || k >= t) right = mid;
        else if(k < t) left = mid + 1;
    }
    if(trans(str2, left) != t)left = -1;
    return left;
}

int main() {
    for(int i=0;i!=37;++i) mp[static_cast<char>(i<10?i+'0':'a'+i-10)]=i;
    std::string a, b; size_t f, rd;
    std::cin >> a >> b >> f >> rd;
    rd=f==1? radix_td(a, b, rd): radix_td(b, a, rd);
    rd==-1?printf("Impossible\n"):printf("%ld", rd);
    return 0;
}


#endif //PAT_1010_HPP
