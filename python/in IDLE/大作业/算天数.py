import datetime as dt
months = [0,31,59,90,120,151,181,212,243,273,304,334]
#--------------------------------------------------------------------------------------获取当天的时间（精准到日）
today = dt.datetime.today()

today_year = str(today)[:-22]#-----------------------当今年份
today_month = str(today)[6:-19]#---------------------当今月份
today_day = str(today)[8:-15]#-----------------------当今日期

today_year = int(today_year)#------------------------转为int,便于计算
today_month  = int(today_month)#---------------------转为int,便于计算
today_day  = int(today_day)#-------------------------转为int,便于计算
print(today)
#---------------------------------------------------------------------------------------获取用户的出生年月日
year_differ_day = 0
use_year = input("请输入你出生的年份：")
use_month = input("请输入你出生的月份：")
use_day = input("请输入你出生的日期：")

use_year = int(use_year)#----------------------------转为int,便于计算
use_month = int(use_month)#--------------------------转为int,便于计算
use_day = int(use_day)#------------------------------转为int,便于计算

def now_day(today_month,today_day):
    if 0 <= today_month <= 12:
        add = months[today_month - 1]
    else:
        print ('输入错误')
    add += today_day
    return add

def before_day(use_month,use_day):
    if 0 <= use_month <= 12:
        add = months[use_month - 1]
    else:
        print ('输入错误')
    add += use_day
    if (use_month % 400 == 0) or ((use_month % 4 == 0) and (use_month % 100 != 0)):
        add = 366 - add
    else:
        add = 365 - add
    return add

def year_day(use_year,today_year):
    global year_differ_day
    while(use_year < today_year - 1):
        if (use_year % 400 == 0) or ((use_year % 4 == 0) and (use_year % 100 != 0)):
            year_differ_day += 366
            use_year += 1
        else:
            year_differ_day += 365
            use_year += 1
    return year_differ_day

def all_day(sum1,sum2,differ_day):
    all_day = sum1 + sum2 + differ_day
    print(all_day)

sum1 = now_day(today_month,today_day) 
sum2 = before_day(use_month,use_day)
year_differ_day = year_day(use_year,today_year)
all_day = all_day(sum1,sum2,year_differ_day)
