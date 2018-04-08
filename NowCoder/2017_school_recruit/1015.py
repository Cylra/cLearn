n = int(input())
list1 = []
while n>0:
    list1.append(input())
    n-=1

result = 0
if sorted(list1) == list1:
    result += 1
if sorted(list1, key=len) == list1:
    result += 2

if 0 == result:
    print('none')
elif 1 == result:
    print('lexicographically')
elif 2 == result:
    print('lengths')
elif 3 == result:
    print('both')