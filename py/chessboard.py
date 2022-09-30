import turtle

screen = turtle.Screen()
cb = turtle.Turtle()

def draw():
    for i in range(4):
        cb.forward(30)
        cb.left(90)
    cb.forward(30)

if __name__ == "__main__":
    screen.setup(600,600)
    cb.speed(100)

    for i in range(8):
        cb.up()
        cb.setpos(-132, 30*i)
        cb.down()

        for j in range(8):
            if(i+j)%2==0:
                col = '#032A53'
            else:
                col = '#C2CCD6'

            cb.fillcolor(col)
            cb.begin_fill()

            draw()

            cb.end_fill()

    cb.hideturtle()
    turtle.done()


