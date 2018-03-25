import math

h = int(input())
i = math.floor(math.sqrt(h))
while( h < i * (i+1) ):
    i -= 1
print(i)