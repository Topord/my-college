#A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
#D A G E J O I B G M P T V H X K L F Q R S U W Z N Y
num = [3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3]#重复的字母有HI/PQ/SU/TV/BWZ/XY/OV及其小写
num_2=[3,1,4,4,5,2,5,6,5,3,5,9,5,7,9,3,8,3,9,4,6,2,6,4,3,3]#数组2用于不重复数字的解密
r_HI = ['B','C']                                         #用数组来储存替换重复数字的字符
r_hi = ['b','c']                                        #重复数字密码对应表
r_PQ = ['K','L']  
r_pq = ['k','l']
r_SU = ['Q','S']  
r_su = ['q','s']
r_TV = ['R','U']
r_tv = ['r','u']
r_BWZ = ['A','W','Y']
r_bwz = ['a','w','y']
r_XY = ['Z','N']
r_xy = ['z','n']
r_NR = ['H','F']
r_nr = ['h','f']
x = input("请输入需要转换的内容:")
m = 0
n = 0
judge = input("加密-->1   解密-->2:")
while(x != ' '):
    if(eval(judge) == 1):#-----------------------------------------------------------------------------------------------加密
        for i in x: 
            if(64 < ord(i) < 91):                 #大写字母
                if(ord(i)!=72 and ord(i)!=73 and ord(i)!=80 and ord(i)!=81 and ord(i)!=83 and ord(i)!=85 and ord(i)!=84 and ord(i)!=86\
                   and ord(i)!=66 and ord(i)!=87 and ord(i)!=90 and ord(i)!=88 and ord(i)!=89 and ord(i)!=78\
                   and ord(i)!=82):            #遇见重复字母时就不打印
                    m = ord(i) + num[ord(i) - 65]                #A--65, m=65+num[0]=68->C

                elif(ord(i)==72): print(r_HI[0],end='')
                elif(ord(i)==73): print(r_HI[1],end='')
                elif(ord(i)==80): print(r_PQ[0],end='')
                elif(ord(i)==81): print(r_PQ[1],end='')
                elif(ord(i)==83): print(r_SU[0],end='')
                elif(ord(i)==85): print(r_SU[1],end='')
                elif(ord(i)==84): print(r_TV[0],end='')
                elif(ord(i)==86): print(r_TV[1],end='')
                elif(ord(i)==66): print(r_BWZ[0],end='')
                elif(ord(i)==87): print(r_BWZ[1],end='')
                elif(ord(i)==90): print(r_BWZ[2],end='')
                elif(ord(i)==88): print(r_XY[0],end='')
                elif(ord(i)==89): print(r_XY[1],end='')
                elif(ord(i)==78): print(r_NR[0],end='')
                elif(ord(i)==82): print(r_NR[1],end='')


                print(chr(m),end='')

                m = 0

            elif(96 < ord(i) < 123):              #小写字母
                if(ord(i)!=104 and ord(i)!=105 and ord(i)!=112 and ord(i)!=113 and ord(i)!=115 and ord(i)!=117 and ord(i)!=116\
                   and ord(i)!=118 and ord(i)!=98 and ord(i)!=119 and ord(i)!=122 and ord(i)!=120 and ord(i)!=121\
                   and ord(i)!=110 and ord(i)!=114):      #遇见重复字母时就不打印
                    n = ord(i) + num[ord(i) - 97]
                    
                elif(ord(i)==104): print(r_hi[0],end='')
                elif(ord(i)==105): print(r_hi[1],end='')
                elif(ord(i)==112): print(r_pq[0],end='')
                elif(ord(i)==113): print(r_pq[1],end='')
                elif(ord(i)==115): print(r_su[0],end='')
                elif(ord(i)==117): print(r_su[1],end='')
                elif(ord(i)==116): print(r_tv[0],end='')
                elif(ord(i)==118): print(r_tv[1],end='')
                elif(ord(i)==98): print(r_bwz[0],end='')
                elif(ord(i)==119): print(r_bwz[1],end='')
                elif(ord(i)==122): print(r_bwz[2],end='')
                elif(ord(i)==120): print(r_xy[0],end='')
                elif(ord(i)==121): print(r_xy[1],end='')
                elif(ord(i)==110): print(r_nr[0],end='')
                elif(ord(i)==114): print(r_nr[1],end='')



                print(chr(n),end = '')
                n = 0
                    
            elif(38 < ord(i) < 48):               #大小写之间的标点符号
                print(chr(ord(i)),end='')
                
    elif(eval(judge) == 2):#------------------------------------------------------------------------------------------------------解密
        for i in x: 
            if(64 < ord(i) < 91):                 #大写字母
                if(ord(i)!=65 and ord(i)!=66 and ord(i)!=67 and ord(i)!=70 and ord(i)!=72 and ord(i)!=75 and  ord(i)!=78\
                   and ord(i)!=81 and ord(i)!=82 and ord(i)!=76 and ord(i)!=83 and ord(i)!=85 and ord(i)!=87 and ord(i)!=90\
                   and ord(i)!=89 ): #遇见重复字母时就不打印
                    m = ord(i) - num_2[ord(i) - 68]               #密码：D-->68    E
                                                                  #输入E-->69  m=69-num[1]=68 ->D 
                elif(ord(i)==65): print('B',end='')                     
                elif(ord(i)==66): print('H',end='')
                elif(ord(i)==67): print('I',end='')
                elif(ord(i)==70): print('R',end='')
                elif(ord(i)==72): print('N',end='')
                elif(ord(i)==75): print('P',end='')
                elif(ord(i)==78): print('Y',end='')
                elif(ord(i)==81): print('S',end='')
                elif(ord(i)==82): print('T',end='')
                elif(ord(i)==76): print('Q',end='')
                elif(ord(i)==83): print('U',end='')
                elif(ord(i)==85): print('V',end='')
                elif(ord(i)==87): print('W',end='')
                elif(ord(i)==90): print('X',end='')
                elif(ord(i)==89): print('Z',end='')
                

                print(chr(m),end='')
                m = 0

            elif(96 < ord(i) < 123):              #小写字母
                if(ord(i)!=97 and ord(i)!=98 and ord(i)!=99 and ord(i)!=102 and ord(i)!=104 and ord(i)!=107 and ord(i)!=110\
                   and ord(i)!=113 and ord(i)!=114 and ord(i)!=108 and ord(i)!=115 and ord(i)!=117 and ord(i)!=119 \
                   and ord(i)!=122 and ord(i)!=121):            #遇见重复字母时就不打印
                    n = ord(i) - num_2[ord(i) - 100]
                    
                elif(ord(i)==97): print('b',end='')
                elif(ord(i)==98): print('h',end='')
                elif(ord(i)==99): print('i',end='')
                elif(ord(i)==102): print('r',end='')
                elif(ord(i)==104): print('n',end='')
                elif(ord(i)==107): print('p',end='')
                elif(ord(i)==110): print('y',end='')
                elif(ord(i)==113): print('s',end='')
                elif(ord(i)==114): print('t',end='')
                elif(ord(i)==108): print('q',end='')
                elif(ord(i)==115): print('u',end='')
                elif(ord(i)==117): print('v',end='')
                elif(ord(i)==119): print('w',end='')
                elif(ord(i)==122): print('x',end='')
                elif(ord(i)==121): print('z',end='')

                print(chr(n),end = '')
                n = 0
                    
            elif(38 < ord(i) < 48):               #大小写之间的标点符号
                print(chr(ord(i)),end='')
            
            
    print('\n')
    x = input("请输入需要转换的内容:")
    judge = input("加密-->1   解密-->2:")



