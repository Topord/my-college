for j in range(1,10):
    for i in range(1,j+1):
        c = j * i#表示结果
        print("{}x{}={}\t".format(i,j,c), end='')
    print("")
