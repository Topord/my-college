def num(n):
    if n==10:
        return 1
    else:
        return (num(n+1)+1)*2
print(num(1))

