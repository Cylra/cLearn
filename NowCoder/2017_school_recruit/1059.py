import sys

def handle_Num(i):
    if len(i) <= 6:
        print(i, end='')
    elif len(i) <= 14:
        print('%s %s' %(i[0:6], i[6:]), end='')
    else:
        print('%s %s %s' %(i[0:6], i[6:14], i[14:]), end='')

all = sys.stdin.readlines()
for i in all:
    i = i.replace(' ', '')
    handle_Num(i)