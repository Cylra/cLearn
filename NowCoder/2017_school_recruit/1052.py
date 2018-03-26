def isLuckyNo(x):
    list1 = list(str(x))
    list1 = list(map(int, list1))
    f_x = sum(list1)

    list2 = list(bin(x)[2:])
    list2 = list(map(int, list2))
    g_x = sum(list2)

    if f_x == g_x:
        return True
    else:
        return False

n = int(input())
i = 0
while n > 0:
    if isLuckyNo(n):
        i += 1
    n -=1
print(i)