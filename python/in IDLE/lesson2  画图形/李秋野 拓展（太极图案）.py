import turtle
a=5
'''大圆半径'''
n=1
'''箭头每次转动的角度'''
b=2.5
'''圆弧半径'''
c=0.7
'''小圆半径'''
turtle.pensize(1)
turtle.speed(500)
turtle.penup()
turtle.goto(0,-300)
turtle.pendown()

for i in range(360):     
    turtle.forward(a)
    turtle.left(n)
'''画大圆'''

for i in range(180):
    turtle.forward(b)
    turtle.left(n)
'''画下面的圆弧'''

for i in range(180):
    turtle.forward(b)
    turtle.right(n)
'''画上面的圆弧'''

turtle.penup()
turtle.goto(0,200)
turtle.pendown()
'''上面小圆的位置'''
for i in range(360):
    turtle.forward(c)
    turtle.right(n)
'''画上面的小圆'''

turtle.penup()
turtle.goto(0,-150)
turtle.pendown()

turtle.begin_fill()
turtle.color('black','black')
for i in range(360):
    turtle.forward(c)
    turtle.right(n)
turtle.end_fill()
'''画下面的小圆并填充为黑色'''


turtle.penup()
turtle.goto(0,-300)
turtle.pendown()
turtle.color('black','black')
turtle.begin_fill()

for i in range(180):
    turtle.forward(a)
    turtle.left(n)

for i in range(180):
    turtle.forward(b)
    turtle.left(n)
'''上面的圆弧'''

for i in range(180):
    turtle.forward(b)
    turtle.right(n)
'''下面的圆弧'''
turtle.end_fill()
'''上面的是为右上角的阴阳鱼填色'''


turtle.penup()
turtle.goto(0,200)
turtle.pendown()
turtle.color('black','white')
turtle.begin_fill()
for i in range(360):
    turtle.forward(c)
    turtle.left(n)
turtle.end_fill()
'''画上面的白色圆'''









    




    
    

   

    
 
 
 
 
