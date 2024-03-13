import turtle as t
t.penup()
t.goto(0,-300)
t.pendown()
t.speed(15)
def it():
    for j in range(10):
        if(j%2==0):
            t.color('black')
            t.begin_fill()
            t.circle((10-j)*30)
            t.end_fill()
        else:
            t.color('white')
            t.begin_fill()
            t.circle((10-j)*30)
            t.end_fill()

it()
    

