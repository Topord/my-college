def num(n):
    if n == 9:
        return  -15
    else:
        if n%2 == 0:
            return -num(n+1)-n
        else:
            return num(n+1)+n
print(num(1))
