import random as r
num = r.randint(1,99)

print(num)
x = input("请猜一个数字(1~100):")
x = eval(x)

if(x > num):
    print("大了！")
elif(x < num):
    print("小了！")
elif(x == num):
    print("666!")
