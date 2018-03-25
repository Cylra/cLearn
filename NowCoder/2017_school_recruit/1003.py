import sys

a = sys.stdin.readlines()
dict1 = {}
for i in a:
    i = i.strip('\n')
    list1 = i.split(' ')
    for j in list1:
        if j not in dict1:
            dict1[j] = 1
        else:
            dict1[j] += 1
print(len(dict1))