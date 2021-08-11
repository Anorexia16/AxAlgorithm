/*
P1836 数页码
题目描述:
        某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个
    缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发
    的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系
    统，因此有可能不能拦截所有的导弹。

        输入导弹依次飞来的高度（雷达给出的高度数据是≤50000的正整数），计算这套系
    统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。
输入格式:
    1行，若干个整数（个数≤100000）
输出格式:
    2行，每行一个整数，第一个数字表示这套系统最多能拦截多少导弹，第二个数字表示如果
    要拦截所有导弹最少要配备多少套这种导弹拦截系统。
难度: 普及/提高-
历史分数--200
*/

#ifndef PAT_P1020_HPP
#define PAT_P1020_HPP

#include <vector>
#include <iostream>
#include <algorithm>


int main() {
    int arr[100000], as{}, tp;
    std::string str;
    std::getline(std::cin, str);
    int s=str.size();
    for(int i=0;i!=s;++i) {
        if(str[i]==' ') {arr[++as]=tp; tp=0;}
        else tp=tp*10+str[i]-'0';
    }
    arr[++as]=tp;
    int round{1}, len = 1, dp[as+1], dpl[as+1];
    dp[1]=dpl[1]=arr[1];
    for(int i=2;i<=as;++i) {
        if(arr[i]<=dp[len]) dp[++len] = arr[i];
        else *std::upper_bound(dp+1, dp+len+1, arr[i], std::greater<>()) = arr[i];
        if(dpl[round]<arr[i]) dpl[++round]=arr[i];
        else *std::lower_bound(dpl+1,dpl+round+1,arr[i])=arr[i];
    }
    printf("%d\n%d\n", len, round);
    return 0;
}

#endif //PAT_P1020_HPP
