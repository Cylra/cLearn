import os

'''
mmp的测试用例
Abc/file.txt -> txt
Abc/file -> null
file.txt -> txt
file -> null
'''
fileName = input()
list1 = os.path.splitext(fileName)
if list1[1] != '':
    print(list1[1][1:])
else:
    print('null')