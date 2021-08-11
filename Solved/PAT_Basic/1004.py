# 1004 成绩排名

num = int(input())
dic = {}
for _ in range(num):
    s = input().split(' ')
    dic[' '.join(s[0:2])] = s[2]

dic = sorted(dic, key=lambda x: int(dic[x]), reverse=True)
print(dic[0])
print(dic[-1])
