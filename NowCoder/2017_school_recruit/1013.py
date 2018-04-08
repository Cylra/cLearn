def isHW(str_tmp):
    list1 = list(str_tmp)
    list1.reverse()
    str2 = ''.join(list1)
    if str_tmp == str2:
        return True
    else:
        return False

A = input()
B = input()

result = 0
for i in range( len(A)+1 ):
    str_tmp = A[0:i] + B + A[i:]
    if isHW(str_tmp):
        # print(str_tmp)
        result += 1
print(result)