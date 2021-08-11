//1051 复数乘法

#ifndef PAT_1051_HPP
#define PAT_1051_HPP

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double m1, m2, t1, t2, A, B;
    std::cin >> m1 >> t1 >> m2 >> t2;
    A = m1*m2*(cos(t1) * cos(t2) - sin(t1) * sin(t2));
    B = m1*m2*(cos(t1) * sin(t2) + sin(t1) * cos(t2));
    A + 0.005 >= 0 && A < 0 ? printf("0.00"): printf("%.2f", A);
    if(B >= 0)
        printf("+%.2fi", B);
    else if (B + 0.005 >= 0 && B < 0)
        printf("+0.00i");
    else
        printf("%.2fi", B);
    return 0;
}

#endif //PAT_1051_HPP
