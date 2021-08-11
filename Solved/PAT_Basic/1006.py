# 1006 换个格式输出整数

List = list(input())
if len(List) == 3:
    print('B'*int(List[0]) + 'S'*int(List[1]) + ''.join([str(i + 1) for i in range(int(List[2]))]))
elif len(List) == 2:
    print('S' * int(List[0]) + ''.join([str(i + 1) for i in range(int(List[1]))]))
else:
    print(''.join([str(i + 1) for i in range(int(List[0]))]))
