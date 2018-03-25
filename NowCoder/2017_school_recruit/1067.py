import sys

def rev_juzi(str1):
    list1 = str1.split(' ')
    list1.reverse()
    print(' '.join(list1))

a = sys.stdin.readlines()
for i in a:
    rev_juzi(i.strip('\n'))