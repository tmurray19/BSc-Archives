# Name:       Taidgh Murray		
# Student ID:  15315901

# File:        bar.py

############################################################################
import math

num=input("Please enter a sequence of numbers, seperated by commas: ")
li=num.split(",")
numlist=[float(i) for i in li]
maximum=max(numlist)
N=math.log10(maximum)

for v in numlist:
    r=abs(math.ceil(v/2))
    print(numlist.index(v)+1,":",r*'#',"(",r,")",sep="")

print("""
 |--------------------------------------------------|
 0                                                100
""")
