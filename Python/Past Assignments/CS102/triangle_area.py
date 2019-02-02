# Name:        Taidgh Murray
# Student ID:  15315901

# File:        triangle_area.py

############################################################################
import math

def sides():
	global a
	global b
	global c
	a=int(input("Please enter the first side: "))
	b=int(input("Please enter the second side: "))
	c=int(input("Please enter the third side: "))
	
def perimeter():
        global p
        p=(a+b+c)/2
        print("The perimeter is", p)

def heron():
	area=math.sqrt(p*(p-a)*(p-b)*(p-c))
	print("The area of the triangle is", area)

sides()
perimeter()
heron()
