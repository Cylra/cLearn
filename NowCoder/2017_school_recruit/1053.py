list1 = input().split(' ')
list1 = list(map(int, list1))
list_rest = []
for i in range(1, 10001):
    if i in list1:
        list1.remove(i)
    else:
        list_rest.append(i)
        if len(list_rest) == 3:
            break
list_rest.sort()
str_num = ''.join(list(map(str, list_rest)))
num = int(str_num) % 7
print(num)