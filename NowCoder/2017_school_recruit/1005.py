import sys
n = int(input())
str1 = input()
if 1 == n:  #一只奶牛,不需要移动
    print(0)
    sys.exit(0)
list1 = list(map(int, str1.split()))
if sum(list1)%n != 0: #无法平分
    print(-1)
    sys.exit(0)
avg = sum(list1)//n
list2 = [ x-avg for x in list1 ]
all = 0
for i in list2:
    if i%2 != 0:  #与平均数的差值不是2的倍数
        print(-1)
        sys.exit(0)
    if i > 0:
        all += i
print(all//2)