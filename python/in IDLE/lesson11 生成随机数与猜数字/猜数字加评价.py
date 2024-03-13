import random as r
num = r.randint(1,99)
n = 1

print(num)
x = input("请猜一个数字[1~100),有9次机会:")
x = eval(x)

while(n == 1 or y == 'y'):
    if(x == num):
        print("你只猜了一次，你真棒！你真是一个小天才!")
    while(x != num):
        if(x > num):
            print("猜大了！还有",9-n,"次机会")
        elif(x < num):
            print("猜大了！还有",9-n,"次机会")
        x = input("请再猜一个数字(1~100):")
        x = eval(x)
        n = n + 1
        if(x != num and n != 9):
            continue
        elif(x == num and n < 9):
            print("猜对了，你总共猜了",n,"次")
            if(n <= 4):
                print("你脑袋有点聪明哦！")
                break
            elif(n <= 8):
                print("你的运气还行!")
                break
        elif(n ==9):
            if(x == num):
                print("第9次才猜对,刚刚好")
                break
            elif(x != num):
                print("猜错了,你已经用完了9 次的机会!")
                break
    n = 1
    print("             ")
    y = input("进入游戏请输入y,退出按回车:")
    if(y == ''):
        print("游戏结束")
        break
    elif(y == 'y'):
        print("         ")
        num = r.randint(1,99)
        print(num)
        x = input("请猜一个数字[1~100):")
        x = eval(x)
        

