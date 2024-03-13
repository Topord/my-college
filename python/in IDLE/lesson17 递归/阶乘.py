def num(n):
    if n == 0:
        return 1
    else:
        return num(n-1)*n
print(num(5))
