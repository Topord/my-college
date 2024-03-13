import random as r
num = r.randint(1,99)
n = 1

print(num)
x = input("请猜一个数字(1~100):")
x = eval(x)

if(x == num):
    print("你只猜了一次，你真棒！")
while(x != num):
    if(x > num):
        print("猜大了！")
    elif(x < num):
        print("猜小了！")
    x = input("请再猜一个数字(1~100):")
    x = eval(x)
    n = n + 1
    if(x != num and n != 9):
        continue
    elif(x == num and n < 9):
        print("猜对了，你总共猜了",n,"次")
        break
    elif(n == 9 ):
        print("你已经用完了9 次的机会!")
        break
