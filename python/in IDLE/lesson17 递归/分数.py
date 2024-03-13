def num(n):
    if n == 11:
        return 1/11
    else:
        return num(n+2)+1/n
print('{:.4f}'.format(num(1)))
