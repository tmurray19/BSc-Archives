# Name:        Taidgh Murray
# Student ID:  15315901

# File:        interest.py

############################################################################
import math
print("To exit this program, enter a negative number.")

def main():
        while True:
                r=float(input("Please insert annual interest rate: "))
                if r>0:
                        time2double(r)
                elif r<0:
                        return 0
def time2double(r):
	y=2/(r/100)
	print("It will take about", math.ceil(y), "years")
main()