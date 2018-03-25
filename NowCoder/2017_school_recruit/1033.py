str1 = input()
M, N = list(map(int, str1.split(' ')))
# list1 = []
# top = -1
# while M != 0:
#     # print(M)
#     k = M % N
#     if(k > 9):
#         list1.append(chr(65+k-10))
#     else:
#         list1.append(str(k))
#     M = M//N
# # list1.reverse()
# # print(''.join(list1))
# # print(list1)
# for i in range(len(list1)-1 , -1, -1):
#     # print(i)
#     print(list1[i] , end="") 
# print()



def zhuanhuan(m , n):

    if(m == 0):
        return
    else:
        zhuanhuan(m//n,n)
        k = m % n 
        if(k > 9):
            print(chr(65+k-10) , end="")
        else:
            print(k , end="") 
# print(M)
if(M < 0):
    print("-" , end="")
    M = -M

zhuanhuan(M,N)