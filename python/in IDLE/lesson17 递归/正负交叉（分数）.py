def num(n,m):                   #n表示分子, m用来判断此项的正负
    if n == 13:
        return  1/13
    else:
        if m%2 == 0:
            m += 1
            return num(n+2,m)-1/n
        else:
            m += 1
            return num(n+2,m)+1/n
x = num(1,1)

print('{:.4f}'.format(x))

