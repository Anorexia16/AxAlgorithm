//1018 锤子剪刀布

#ifndef PAT_1018_HPP
#define PAT_1018_HPP

#include<iostream>
#include <map>

int main() {
    int lines;
    scanf("%d", &lines);
    std::map<char, int> chart1;
    chart1['B'] = 0;
    chart1['C'] = 1;
    chart1['J'] = 2;
    int const chart2[9] {0, 1, -1, -1, 0, 1, 1, -1, 0};
    int counter = 0;
    int c2 = 0;
    char temp1, temp2;
    int c3[3] = {0, 0, 0}, c4[3] = {0, 0, 0};
    for (auto iter = 0; iter!= lines; iter++) {
        scanf("\n%c %c", &temp1, &temp2);
        if (temp1 == temp2) c2+=1;
        if(chart2[chart1[temp1] * 3 + chart1[temp2]] == 1) {
            c3[chart1[temp1]] += 1;
            counter += 1;
        } else if (chart2[chart1[temp1] * 3 + chart1[temp2]] == -1) {
            c4[chart1[temp2]] += 1;
        }
    }
    printf("%d %d %d\n", counter, c2, lines-c2-counter);
    printf("%d %d %d\n", lines-c2-counter, c2, counter);
    if (c3[0] >= c3[1] && c3[0]>= c3[2]) printf("B ");
    else if (c3[0] < c3[1] && c3[1]>= c3[2]) printf("C ");
    else if (c3[0] < c3[2] && c3[1]< c3[2]) printf("J ");
    if (c4[0] >= c4[1] && c4[0]>= c4[2]) printf("B\n");
    else if (c4[0] < c4[1] && c4[1]>= c4[2]) printf("C\n");
    else if (c4[0] < c4[2] && c4[1]< c4[2]) printf("J\n");
}


#endif //PAT_1018_HPP
