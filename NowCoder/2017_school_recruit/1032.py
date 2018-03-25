import re

num = int(input())
sum = 1
while(num > 1):
    sum = sum * num
    num -= 1
str1 = str(sum)
count = 0
 
# while(str1[-1] == '0'):
#     count += 1
#     str1 = str1[:-1]

result = re.findall("0+$",str1)
try:
    print(len(result[0]))
except :
    print(0)