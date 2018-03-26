import math

#判断值是否为整数,3.0 19.0
def isInt(x):
    if len(str(x).split('.')[1]) > 1:
        return False
    else:
        return True

m = int(input())
r = math.sqrt(m)
a = int(r)
k = 0  #整数点的个数
if isInt(r):  #如果半径是整数
    a -= 1
while a > 0:
    b = math.sqrt(m - a**2)
    #print("b = %s" %b)
    if isInt(b):
        k +=1
    a -= 1

k *= 4
if isInt(r):
    k += 4
print(k)