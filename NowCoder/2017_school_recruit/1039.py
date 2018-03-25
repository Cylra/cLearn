import re

str1 = input()
str2 = input()
str2 = '[^' + str2 + ']'
list1 = re.findall(str2, str1)
print(''.join(list1))