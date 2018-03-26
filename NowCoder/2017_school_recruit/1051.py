import sys

#A的i进制
def cal_Sum(A, i):
    list1 = []
    while A !=0:
        list1.append(A%i)
        A = A//i
    # print(list1)
    return sum(list1)

all = sys.stdin.readlines()

for A in all:
    A = int(A)
    jinZhi = A-1
    fenZi = A-2
    quanBu = 0
    for i in list(range(2, A)):
        quanBu += cal_Sum(A, i)
    #需要约分24/8 = 3/1
    i = quanBu
    j = fenZi
    while j!= 0:
        k = i%j
        i = j
        j = k
    yueShu = i
    print('%d/%d' %(quanBu//yueShu, fenZi//yueShu))