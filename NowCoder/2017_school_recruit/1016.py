import re

pat1 = re.compile(r'[^A-Z]')
pat2 = re.compile(r'([A-Z])\1')
pat3 = re.compile(r'([A-Z])[A-Z]*([A-Z])[A-Z]*\1[A-Z]*\2')

str1 = input()
if pat1.findall(str1) or pat2.findall(str1) or pat3.findall(str1):
    print('Dislikes')
else:
    print('Likes')