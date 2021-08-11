# 1010 一元多项式求导

e = [int(x) for x in input().split()]
if e[1] == 0:
    print(0, 0)
else:
    for i in range(len(e) // 2):
        a = e[2 * i]
        b = e[2 * i + 1]
        if i == 0 and b > 0:
            print(a * b, b - 1, end='')
        elif b > 0:
            print(' ' + str(a * b), b - 1, end='')
