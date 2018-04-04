import sys
import re

all = sys.stdin.readlines()
for i in range(0, len(all), 3):
    str_flags = all[i].strip()
    str_flags_rev = ''.join(list(reversed(str_flags)))
    first = all[i+1].strip()
    second = all[i+2].strip()
    pat = '{0}.*{1}'.format(first, second)
    result = 0
    if re.findall(pat, str_flags):
        result += 1
    if re.findall(pat, str_flags_rev):
        result += 2
    
    if 0 == result:
        print('invalid')
    elif 1 == result:
        print('forward')
    elif 2 == result:
        print('backward')
    elif 3 == result:
        print('both')