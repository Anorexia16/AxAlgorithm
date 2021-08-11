/*
P1836 数页码
题目描述:
    一个学校里老师要将班上N个同学排成一列，同学被编号为1 ~ N，他采取如下的
方法：
    1.先将1号同学安排进队列，这时队列中只有他一个人；
    2.2−N号同学依次入列，编号为i的同学入列方式为：老师指定编号为i的同学站在
        编号为1∼(i−1)中某位同学（即之前已经入列的同学）的左边或右边；
    3.从队列中去掉M(M<N)个同学，其他同学位置顺序不变。
    在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。

输入格式:第1行为一个正整数N，表示了有N个同学。
    第2-N行，第i行包含两个整数k,p，其中k为小于i的正整数，p为0或者1。
    若p为0，则表示将i号同学插入到k号同学的左边，p为1则表示插入到右边。
    第N+1行为一个正整数M，表示去掉的同学数目。
    接下来M行，每行一个正整数x，表示将x号同学从队列中移去，如果x号同学
    已经不在队列中则忽略这一条指令。
输出格式:1行，包含最多N个空格隔开的正整数，表示了队列从左到右所有同学的
    编号，行末换行且无空格。
难度: 普及/提高-
历史分数--100
*/

#ifndef PAT_P1160_HPP
#define PAT_P1160_HPP

#endif //PAT_P1160_HPP
