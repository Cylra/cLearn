import sys

list1 = input().split(' ')
for i in list1:
    if not i.isdigit():
        print('error')
        sys.exit(0)
print( sum([int(x) for x in list1]) )