# 1011 A+B 和 C

i, li = int(input()), []
for k in range(i):
    strings = input().split(' ')
    li.append('true') if int(strings[0]) + int(strings[1]) > int(strings[2]) else li.append('false')
[print('Case #{}: {}'.format(k+1, li[k])) for k in range(i)]
