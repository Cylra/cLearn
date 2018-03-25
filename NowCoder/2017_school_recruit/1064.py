import sys
import math

def sqlrt(n, m):
    sum = 0
    while m > 0:
        m -= 1
        sum += n
        n = math.sqrt(n)
    print("%.2f" %sum)

a = sys.stdin.readlines()
for i in a:
    n, m = [ int(x) for x in i.split(' ') ]
    sqlrt(n, m)