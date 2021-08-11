# 1007 素数对猜想

num = int(input())
ans = 0
List = [False] * (num + 1)
for i in range(2, num+1):
    if not List[i]:
        if num // i > 1:
            for k in range(2, (num // i) + 1):
                List[k*i] = True
for k in range(2, num-1):
    if not (k % 2 == 0):
        if (List[k] is False) & (List[k+2] is False):
            ans += 1
print(ans)
