def rev(x):
    list_tmp = list(str(x))
    list_tmp.reverse()
    return int(''.join(list_tmp))

list1 = input().split(' ')
x, y = list(map(int, list1))
print(rev(rev(x) + rev(y)))