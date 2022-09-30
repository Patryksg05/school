import turtle

turtle.bgcolor("#000")
turtle.speed(0)
turtle.pensize(2)

for i in range(10):
    for j in ["#050D51", "#09167F", "#0C20BE", "#394EEF", "#5768EC", "#DADDF1", "#FFF"]:
        turtle.color(j)
        turtle.left(15)
        for x in range(4):
            turtle.forward(200)
            turtle.left(90)
turtle.hideturtle()