import sys

#非负整数
def isNoNegInt(x):
    if x<0:
        return False
    if len(str(x).split('.')[1]) > 1:
        return False
    return True

str1 = input()
list1 = list(map(int, str1.split(' ')))
B = (list1[1] + list1[3])/2
C = list1[3] - B
A = list1[2] - B
#不满足第一个等式
if A-B != list1[0]:
    print('No')
    sys.exit(0)
if isNoNegInt(A) and isNoNegInt(B) and isNoNegInt(C):
    print('%s %s %s' %(int(A), int(B), int(C)))
else:
    print('No')