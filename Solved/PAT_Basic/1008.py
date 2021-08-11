# 1008 数组元素循环右移问题

s1, s2 = input(), input()
List = [x for x in s2.split(' ')]
num = int(s1.split(' ')[0]) - int(s1.split(' ')[1])
print(' '.join(List[num:] + List[:num]))
