import datetime as dt
import turtle as t
tm = dt.datetime.today()
get = int(tm.weekday())
print(get)
t.penup()
t.goto(-50,-250)
t.pendown()
if(get == 0): t.write('星期一', font=("",30, "normal"))
elif(get == 1): t.write('星期二', font=("",30, "normal"))
elif(get == 2): t.write('星期三', font=("",30, "normal"))
elif(get == 3): t.write('星期四', font=("",30, "normal"))
elif(get == 4): t.write('星期五', font=("",30, "normal"))
elif(get == 5): t.write('星期六', font=("",30, "normal"))
elif(get == 6): t.write('星期日', font=("",30, "normal"))
