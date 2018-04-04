import sys
import re

s = input()
t = input()
if t == '':
    print('Yes')
    sys.exit(0)

list1 = list(t)
#用正则,贼方便
pat = '.*'.join(list1)
if re.findall(pat, s):
    print('Yes')
else:
    print('No')