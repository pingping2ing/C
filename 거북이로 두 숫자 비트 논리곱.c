# -&- coding:utf-8 -*-
import turtle

num1,num2,num3=0,0,0
bin1,bin2,bin3=0,0,0
swidth,sheight=1000,300
curX,curY=0,0

turtle.title('거북이로 두 숫자 비트 논리곱(&) 연산하기')
turtle.shape('turtle')
turtle.setup(width=swidth+50,height=sheight+50)
turtle.screensize(swidth,sheight)
turtle.penup()
turtle.left(90)
    
num1=int(input("첫번째 숫자를 입력하세요: "))
num2=int(input("두번째 숫자를 입력하세요: "))
num3=num1&num2
bin1=bin(num1)
bin2=bin(num2)
bin3=bin(num3)
curX=swidth/2
curY=100
    
for i in range(len(bin1)-2):
    turtle.goto(curX,curY)
    if num1&1:
        turtle.color('red')
        turtle.turtlesize(2)
    else:
        turtle.color('blue')
        turtle.turtlesize(1)
    turtle.stamp()
    curX-=50
    num1>>=1
curY-=100
curX=swidth/2
for i in range(len(bin2)-2):
    turtle.goto(curX,curY)
    if num2&1:
        turtle.color('red')
        turtle.turtlesize(2)
    else:
        turtle.color('blue')
        turtle.turtlesize(1)
    turtle.stamp()
    curX-=50
    num2>>=1
curY-=100
curX=swidth/2
for i in range(len(bin3)-2):
    turtle.goto(curX,curY)
    if num3&1:
        turtle.color('red')
        turtle.turtlesize(2)
    else:
        turtle.color('blue')
        turtle.turtlesize(1)
    turtle.stamp()
    curX-=50
    num3>>=1

turtle.done()
