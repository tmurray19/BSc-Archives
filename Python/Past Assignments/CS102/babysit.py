# Name:        Taidgh Murray
# Student ID:  15315901

# File:        babysit.py

############################################################################
import math

def babysitting():
	starttime = input("Enter start time: ")
	start=int(starttime.replace(":",""))
	endtime = input("Enter end time: ")
	end=int(endtime.replace(":",""))
	end=int(end/100)
	start=int(start/100)
	pay(start, end)

def pay(start, end):
        if start <=21 and end<=21:
                early=((end-start)*12.00)
                early=float(early)
                print("Total Pay: ", "€", early, sep="")
        if start <= 21 and end>21:
               normal=((21-start)*12.00)
               norm=float(normal)
               laterate=end-21
               late=laterate*9.50
               print("Total Pay: ", "€", norm+late, sep="")
        if start > 21:
                latevalue = (end-start)
                latecomplete = float(latevalue*9.50)
                print("Total Pay: ", "€", latecomplete, sep="")
 
babysitting()
