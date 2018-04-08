list1 = input().split(' ')
n = int(list1[-1])
list_ret = sorted(list1[:-1], key = int)[:n]
print(' '.join(list_ret))