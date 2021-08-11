//1017 A除以B

#ifndef PAT_1017_HPP
#define PAT_1017_HPP

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> num;
    std::string record;
    int q;

    std::cin >> record;
    if (record == "0") {
        printf("0 0");
        return 0;
    }
    scanf("%d" , &q);

    int const size = record.size();
    int R = 0;

    for (auto index = 0; index!=size; index++) num.emplace_back(record[index] - 48);
    if (num[0] > q) {
        printf("%d", (num[0] + R * 10) / q);
    }
    R = (num[0] + R * 10) % q;
    for (auto index = 1; index<size; index++){
        printf("%d", (num[index] + R * 10) / q);
        R = (num[index] + R * 10) % q;
    }
    if (size == 1) printf("0");
    printf(" %d", R);
}

#endif //PAT_1017_HPP
