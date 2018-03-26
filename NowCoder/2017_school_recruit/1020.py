
def gen_Queue(x):
    if 1 == x:
        print('1')
    elif 2 == x:
        print('2 1')
    else:
        list_tmp = [x, x-1]
        x -= 2
        #print(list_tmp)
        while x > 0:
            #从队尾移除,添加到队头,在list[1]处插入值
            val = list_tmp.pop()
            list_tmp.insert(0, val)
            list_tmp.insert(1, x)

            x -= 1
        print(' '.join(list(map(str, list_tmp))))

T = int(input())
list1 = []
while T > 0:
    n = int(input())
    list1.append(n)
    T -= 1

for x in list1:
    gen_Queue(x)