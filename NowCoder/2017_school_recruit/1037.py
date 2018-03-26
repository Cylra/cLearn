str1 = input()
list1 = list(map(int, str1.split(' ')))
dict1 = {}
for i in list1:
    if i not in dict1:
        dict1[i] = 1
    else:
        dict1[i] += 1
        if dict1[i] *2 >= len(list1):
            print(i)
            break