import sys
import re

rep1 = re.compile('\d')
def findNarNum(m, n):
    list_result = []
    for i in list(range(m, n+1)):
        list1 = list(map(int, rep1.findall(str(i))))
        if i == sum(list(map(lambda x: x**3, list1))):
            list_result.append(str(i))
    if len(list_result) == 0:
        print('no')
    else:
        print(' '.join(list_result))

a = sys.stdin.readlines()
for i in a:
    m, n = [ int(x) for x in i.split(' ') ]
    findNarNum(m, n)