import sys

n = int(input())
#奇数无法购买
if n%2 == 1 or n<6 or n == 7 or n==10:
    print(-1)
    sys.exit(0)
#尽量少的袋数,先判断8
if n%8 ==0:
    print(n//8)
    sys.exit(0)
print(n//8 +1)