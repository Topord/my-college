for j in range(1,10):
    k = 10 - j
    for i in range(1,k+1):
        c = k * i#表示结果
        print("{}x{}={}\t".format(i,k,c), end='')
    print("")
'''
第一次
j = 1:
    k = 9;
        i = 1; 1x9;
        i = 2; 2x9;
        ...
        i = 9; 9x9;
第二次
j = 2:
    k = 8;
        i = 1; 1x8;
        ...
        i = 8; 8x8
...........
'''
