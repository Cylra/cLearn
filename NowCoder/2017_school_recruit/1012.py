import sys

n = sys.stdin.readline().strip()
list_X = sys.stdin.readline().strip().split(' ')
list_X = list(map(int, list_X))
list_Y = sys.stdin.readline().strip().split(' ')
list_Y = list(map(int, list_Y))

list_ret = [ x+y for x,y in zip(list_X, list_Y) ]
print(min(list_ret) - 2)