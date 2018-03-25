str1 = input()
dict1 = {}
for x in str1:
    if x not in dict1:
        dict1[x] = 1
    else:
        dict1[x] += 1
        #必须是字符
        if dict1[x] == 3 and x.isalpha() :
            print(x)
            break