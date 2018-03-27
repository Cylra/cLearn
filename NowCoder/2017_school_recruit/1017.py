import sys
#Fibonacci生成器
def Fibonacci():
    a, b = 0, 1
    while 1:
        yield b
        a, b = b, a + b

N = int(input())
if N < 4:
    print(0)
    sys.exit(0)
f = Fibonacci()
last = next(f)
while 1:
    now = next(f)
    print('now = %s' %now)
    if N >= last and N <= now:
        print( min(N-last, now-N) )
        break
    last = now