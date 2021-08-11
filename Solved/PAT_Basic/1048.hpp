//1048 数字加密

#ifndef PAT_1048_HPP
#define PAT_1048_HPP

#include <string>
#include <iostream>

using namespace std;

int main() {
    char cs[3] {'J', 'Q', 'K'};
    string A, B, res{};
    cin >> A >> B;
    size_t as=A.size(), bs=B.size(), i=0, ss;
    int a, b;
    ss= bs>as? bs:as;
    int tp;
    for(;i!=ss;++i) {
        if (i>=as) {
            res.append(1, B[bs-i-1]);
        } else {
            if (i>=bs) a=A[as-i-1]-'0', b=0;
            else a=A[as-i-1]-'0', b=B[bs-i-1]-'0';
            if (i%2==0) {
                tp = (a+b)%13;
                if (tp>=10) res.append(1, cs[tp-10]);
                else res.append(1, tp+'0');
            } else {
                tp = (b-a);
                if (tp<0) tp+=10;
                res.append(1, tp+'0');
            }
        }
    }
    for(auto iter=res.rbegin();iter!=res.rend();++iter) {
        printf("%c", *iter);
    }
    printf("\n");
    return 0;
}

#endif //PAT_1048_HPP
