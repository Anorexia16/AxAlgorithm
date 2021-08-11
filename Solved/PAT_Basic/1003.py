# 1003 我要通过！

num = int(input())
Ans = []
true, false = 'YES', 'NO'
for i in range(num):
    flag, List, skip = 0, [0] * 3, False
    s = input()
    for char in s:
        if char == 'A':
            List[flag] += 1
        elif char == 'P':
            if flag == 0:
                flag = 1
            else:
                Ans.append(false)
                skip = True
                break
        elif char == 'T':
            if flag == 1:
                flag = 2
            else:
                Ans.append(false)
                skip = True
                break
        else:
            Ans.append(false)
            skip = True
            break
    if skip:
        continue
    if not flag == 2:
        Ans.append(false)
        continue
    if (List[1] > 0) & (List[2] == List[0]):
        Ans.append(true)
    elif List[0]:
        if List[2] / List[0] == List[1]:
            Ans.append(true)
        else:
            Ans.append(false)
    else:
        Ans.append(false)
for i in Ans:
    print(i)
