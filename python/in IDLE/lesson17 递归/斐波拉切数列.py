def num(n):
    if(n == 1 or n == 2):
        return 1
    return num(n - 1) + num(n - 2)
print(num(15))
#1,1,2,3,5,8,13,21,34
#下一个数等于前两个数相加
