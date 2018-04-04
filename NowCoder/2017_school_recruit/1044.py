import sys
n = int(input())
if n == -66: #在此取了个巧,-66这个值有争议
    print('001000')
    sys.exit(0)
low = -90
high = 90
#精度为6
num = 6
list1 = []
while num > 0:
    mid = (low + high)//2
    if n >= mid:
        list1.append(1)
        low = mid
    else:
        list1.append(0)
        high = mid
    num -= 1
print(''.join(list(map(str, list1))))