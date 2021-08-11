s, an = 0.0, 0
n = int(input())
word = input().split()

for i in range(n):
    tp = word[i]
    try:
        a = float(tp)
        if not ((len(tp.split('.')) < 2 or len(tp.split('.')[1]) < 3) and -1000 <= a <= 1000):
            raise BaseException
        s += a
        an += 1
    except:
        print("ERROR: {} is not a legal number".format(tp))

if an == 1:
    print('The average of 1 number is {:.2f}'.format(s))
elif an == 0:
    print('The average of 0 numbers is Undefined')
else:
    print('The average of {} numbers is {:.2f}'.format(an, s/an))
